#include "appointmentform.h"
#include "ui_appointmentform.h"
#include <QFile>
#include <QTextStream>
#include <QRandomGenerator>

AppointmentForm::AppointmentForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppointmentForm)
{
    ui->setupUi(this);
    loadDoctors();
    connect(ui->comboBoxDoctor, SIGNAL(currentIndexChanged(int)), this, SLOT(on_doctorComboBox_currentIndexChanged(int)));
}

AppointmentForm::~AppointmentForm()
{
    delete ui;
}

void AppointmentForm::loadDoctors()
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields[2] == "Doctor") {
            ui->comboBoxDoctor->addItem(fields[0]);
        }
    }

    file.close();
}

void AppointmentForm::loadSlots(const QString &doctor)
{
    ui->comboBoxAvailableSlots->clear();

    QFile file("slots.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields[1] == doctor && fields[3] == "Available") {
            ui->comboBoxAvailableSlots->addItem(fields[0]); // Display only SlotId
        }
    }

    file.close();
}

void AppointmentForm::on_doctorComboBox_currentIndexChanged(int index)
{
    QString selectedDoctor = ui->comboBoxDoctor->itemText(index);
    loadSlots(selectedDoctor);
}

void AppointmentForm::on_btnBookAppointment_clicked()
{
    QString patientName = ui->lineEditPatientName->text();
    QString contactNumber = ui->lineEditContactNumber->text();
    QString doctor = ui->comboBoxDoctor->currentText();
    QString slot = ui->comboBoxAvailableSlots->currentText(); // Retrieve SlotId directly
    QString status = "Confirmed";

    if (patientName.isEmpty() || contactNumber.isEmpty() || doctor.isEmpty() || slot.isEmpty()) {
        // Handle validation error (show message to user)
        return;
    }

    // Generate a unique 7-digit AppointmentId
    int appointmentId = QRandomGenerator::global()->bounded(1000000, 10000000);

    // Append the appointment to appointments.txt
    QFile appointmentsFile("appointments.txt");
    if (!appointmentsFile.open(QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&appointmentsFile);
    out << appointmentId << "," << slot << "," << patientName << "," << contactNumber << "," << doctor << "," << status << "\n";
    appointmentsFile.close();

    // Update the slot to "Not Available" in slots.txt
    QFile slotsFile("slots.txt");
    if (!slotsFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QStringList lines;
    QTextStream in(&slotsFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields[0] == slot) {
            fields[3] = "Not Available"; // Update availability
            line = fields.join(",");
        }
        lines.append(line);
    }
    slotsFile.close();

    if (!slotsFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        return;

    QTextStream outSlots(&slotsFile);
    foreach (const QString &line, lines) {
        outSlots << line << "\n";
    }
    slotsFile.close();

    // Optionally, show a success message to the user and close the form
    accept();
}
