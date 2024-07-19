#include "patientappointments.h"
#include "ui_patientappointments.h"
#include "currentuser.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QInputDialog>
#include "appointmentform.h"

PatientAppointments::PatientAppointments(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PatientAppointments)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    loadAppointments();
}

PatientAppointments::~PatientAppointments()
{
    delete ui;
}

void PatientAppointments::loadAppointments()
{
    qDebug() << "loadAppointments Called"; // Debugging

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    // Retrieve the current user
    CurrentUser *user = CurrentUser::instance();
    QString currentUsername = user->getUsername();
    qDebug() << "Current Username:" << currentUsername; // Debugging

    QFile file("appointments.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open appointments.txt";
        return;
    }

    QTextStream in(&file);
    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields[2] == currentUsername) {  // Assuming the username is in the third column
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(fields[0]));  // appid
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(fields[4]));  // doctor
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(fields[1]));  // slot id
            row++;
        }
    }

    file.close();
}

void PatientAppointments::on_editAppointmentButton_clicked()
{
    qDebug() << "on_editAppointmentButton_clicked Called"; // Debugging

    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Edit Appointment", "Please select an appointment to edit.");
        return;
    }

    QString oldSlotId = ui->tableWidget->item(currentRow, 2)->text();  // Get old Slot ID
    bool ok;
    QString newSlotId = QInputDialog::getText(this, "Edit Slot ID", "Enter new Slot ID:", QLineEdit::Normal, oldSlotId, &ok);

    if (ok && !newSlotId.isEmpty()) {
        // Check if the new slot is available
        QFile slotsFile("slots.txt");
        if (!slotsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Edit Appointment", "Failed to open slots.txt.");
            return;
        }

        QStringList slotLines;
        QTextStream slotIn(&slotsFile);
        bool newSlotAvailable = false;

        while (!slotIn.atEnd()) {
            QString slotLine = slotIn.readLine();
            QStringList slotFields = slotLine.split(",");
            if (slotFields[0] == newSlotId) {
                if (slotFields[5] == "Available") {
                    newSlotAvailable = true;
                }
            }
            slotLines << slotLine;
        }
        slotsFile.close();

        if (!newSlotAvailable) {
            QMessageBox::warning(this, "Edit Appointment", "The selected slot is not available.");
            return;
        }

        // Update appointments.txt
        QFile file("appointments.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Edit Appointment", "Failed to open appointments.txt.");
            return;
        }

        QStringList lines;
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields[0] == ui->tableWidget->item(currentRow, 0)->text()) {
                fields[1] = newSlotId;  // Update Slot ID
                line = fields.join(",");
            }
            lines << line;
        }
        file.close();

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Edit Appointment", "Failed to open appointments.txt for writing.");
            return;
        }

        QTextStream out(&file);
        for (const QString &line : lines) {
            out << line << "\n";
        }
        file.close();

        // Update slots.txt
        QFile updatedSlotsFile("slots.txt");
        if (!updatedSlotsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Edit Appointment", "Failed to open slots.txt for reading.");
            return;
        }

        QStringList updatedSlotLines;
        QTextStream updatedSlotIn(&updatedSlotsFile);
        while (!updatedSlotIn.atEnd()) {
            QString slotLine = updatedSlotIn.readLine();
            QStringList slotFields = slotLine.split(",");
            if (slotFields[0] == oldSlotId) {
                slotFields[3] = "Available";  // Make the old slot available
                slotLine = slotFields.join(",");
            } else if (slotFields[0] == newSlotId) {
                slotFields[3] = "Not Available";  // Make the new slot unavailable
                slotLine = slotFields.join(",");
            }
            updatedSlotLines << slotLine;
        }
        updatedSlotsFile.close();

        if (!updatedSlotsFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Edit Appointment", "Failed to open slots.txt for writing.");
            return;
        }

        QTextStream updatedSlotOut(&updatedSlotsFile);
        for (const QString &slotLine : updatedSlotLines) {
            updatedSlotOut << slotLine << "\n";
        }
        updatedSlotsFile.close();

        loadAppointments();  // Refresh the list
    }
}

void PatientAppointments::on_deleteAppointmentButton_clicked()
{
    qDebug() << "on_deleteAppointmentButton_clicked Called"; // Debugging

    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Delete Appointment", "Please select an appointment to delete.");
        return;
    }

    QString slotId = ui->tableWidget->item(currentRow, 2)->text();  // Get Slot ID
    QFile file("appointments.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Delete Appointment", "Failed to open appointments.txt.");
        return;
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields[0] != ui->tableWidget->item(currentRow, 0)->text()) {
            lines << line;
        }
    }
    file.close();

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Delete Appointment", "Failed to open appointments.txt for writing.");
        return;
    }

    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    file.close();

    // Update slots.txt to make the slot available
    QFile slotsFile("slots.txt");
    if (!slotsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Delete Appointment", "Failed to open slots.txt.");
        return;
    }

    QStringList slotLines;
    QTextStream slotIn(&slotsFile);
    while (!slotIn.atEnd()) {
        QString slotLine = slotIn.readLine();
        QStringList slotFields = slotLine.split(",");
        if (slotFields[0] == slotId) {
            slotFields[5] = "Available";  // Make the slot available
            slotLine = slotFields.join(",");
        }
        slotLines << slotLine;
    }
    slotsFile.close();

    if (!slotsFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Delete Appointment", "Failed to open slots.txt for writing.");
        return;
    }

    QTextStream slotOut(&slotsFile);
    for (const QString &slotLine : slotLines) {
        slotOut << slotLine << "\n";
    }
    slotsFile.close();

    loadAppointments();  // Refresh the list
}

void PatientAppointments::on_addAppointmentButton_clicked()
{
    qDebug() << "on_addAppointmentButton_clicked Called"; // Debugging

    AppointmentForm *appointmentForm = new AppointmentForm();
    appointmentForm->show();
}
