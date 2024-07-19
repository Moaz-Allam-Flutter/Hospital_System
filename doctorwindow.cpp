<<<<<<< HEAD
#include "doctorwindow.h"
#include "ui_doctorwindow.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QRandomGenerator>
#include <QMessageBox>
#include "currentuser.h"

// Constructor
DoctorWindow::DoctorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorWindow)
{
    ui->setupUi(this);

    // Initialize the tables and set column widths
    initializeAppointmentsTable();
    initializeMedicalRecordsTable();
    initializeSlotsTable();

    // Load data from files
    loadSlotsFromFile("slots.txt");
    loadMedicalRecordsFromFile("records.txt");
    loadAppointmentsForDoctor();

    // Connect the search bar signal to the filter function
    connect(ui->searchBar, &QLineEdit::textChanged, this, &DoctorWindow::filterMedicalRecordsTable);

}

// Destructor
DoctorWindow::~DoctorWindow()
{
    // Save data to files before closing
    saveSlotsToFile("slots.txt");
    saveMedicalRecordsToFile("records.txt");
    delete ui;
}

// Initialize the appointments table
void DoctorWindow::initializeAppointmentsTable()
{
    // Set column count and headers for the appointments table
    ui->tableWidget->setColumnCount(5); // Slot Id, Patient Name, Contact Number, Status
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // Set column widths
    ui->tableWidget->setColumnWidth(0, 120); // App Id
    ui->tableWidget->setColumnWidth(1, 120); // Slot Id
    ui->tableWidget->setColumnWidth(2, 150); // Patient Name
    ui->tableWidget->setColumnWidth(3, 150); // Contact Number
    ui->tableWidget->setColumnWidth(4, 150); // Status
}

// Initialize the medical records table
void DoctorWindow::initializeMedicalRecordsTable()
{
    // Set column count and headers for the medical records table
    ui->tableWidget_3->setColumnCount(4); // Patient Name, Age, Current Medication, Notes
    ui->tableWidget_3->setHorizontalHeaderLabels(QStringList() << "Patient Name" << "Age" << "Current Medication" << "Notes");
    ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);

    // Set column widths
    ui->tableWidget_3->setColumnWidth(0, 150); // Patient Name
    ui->tableWidget_3->setColumnWidth(1, 60);  // Age
    ui->tableWidget_3->setColumnWidth(2, 200); // Current Medication
    ui->tableWidget_3->setColumnWidth(3, 250); // Notes
}

// Initialize the slots table
void DoctorWindow::initializeSlotsTable()
{
    // Set column count and headers for the slots table
    ui->tableWidget_2->setColumnCount(5); // Slot Id, Date, Status, Time, Duration
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "Slot Id" << "Date" << "Status" << "Time" << "Duration");
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);

    // Set column widths
    ui->tableWidget_2->setColumnWidth(0, 120); // Slot Id
    ui->tableWidget_2->setColumnWidth(1, 150); // Date
    ui->tableWidget_2->setColumnWidth(2, 150); // Status
    ui->tableWidget_2->setColumnWidth(3, 150); // Time
    ui->tableWidget_2->setColumnWidth(4, 150); // Duration
}

// Generate a random slot ID
int DoctorWindow::generateRandomSlotId()
{
    return QRandomGenerator::global()->bounded(10000, 99999);
}

// Handle the Add Slot button click
void DoctorWindow::on_addSlotButton_clicked()
{
    // Gather slot information from input fields
    int slotId = generateRandomSlotId();
    QString date = ui->slotDateEdit->date().toString("yyyy-MM-dd");
    QString status = "Available"; // Default status
    QString time = ui->slotTimeEdit->time().toString("hh:mm");
    QString duration = QString::number(ui->slotDurationSpinBox->value()) + " mins";

    // Retrieve the current user
    CurrentUser *user = CurrentUser::instance();
    QString currentUsername = user->getUsername();

    // Add a new row to the table
    int row = ui->tableWidget_2->rowCount();
    ui->tableWidget_2->insertRow(row);
    ui->tableWidget_2->setItem(row, 0, new QTableWidgetItem(QString::number(slotId)));
    ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(date));
    ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(status));
    ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(time));
    ui->tableWidget_2->setItem(row, 4, new QTableWidgetItem(duration));

    // Save data to file
    saveSlotToFile("slots.txt", QString("%1,%2,%3,%4,%5,%6").arg(slotId).arg(currentUsername).arg(date).arg(status).arg(time).arg(duration));
}

// Handle the Edit Slot button click
void DoctorWindow::on_editSlotButton_clicked()
{
    // Get the selected row
    int row = ui->tableWidget_2->currentRow();
    if (row == -1) return; // No selection

    // Update the selected row with new values
    QString date = ui->slotDateEdit->date().toString("yyyy-MM-dd");
    QString status = "Available"; // Default status or get from a ComboBox
    QString time = ui->slotTimeEdit->time().toString("hh:mm");
    QString duration = QString::number(ui->slotDurationSpinBox->value()) + " mins";

    ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(date));
    ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(status));
    ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(time));
    ui->tableWidget_2->setItem(row, 4, new QTableWidgetItem(duration));

    // Save data to file
    saveSlotsToFile("slots.txt");
}

// Handle the Delete Slot button click
void DoctorWindow::on_deleteSlotButton_clicked()
{
    // Get the selected row
    int row = ui->tableWidget_2->currentRow();
    if (row != -1) {
        // Remove the selected row
        ui->tableWidget_2->removeRow(row);

        // Save data to file
        saveSlotsToFile("slots.txt");
    }
}

// Save slots data to a text file
void DoctorWindow::saveSlotsToFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing";
        return;
    }

    QTextStream out(&file);
    int rowCount = ui->tableWidget_2->rowCount();
    int columnCount = ui->tableWidget_2->columnCount();

    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = ui->tableWidget_2->item(row, col);
            if (item) {
                out << item->text();
            }
            if (col < columnCount - 1) {
                out << ","; // Comma-separated
            }
        }
        out << "\n";
    }

    file.close();
}

// Save a single slot to a text file
void DoctorWindow::saveSlotToFile(const QString &filename, const QString &slotData)
{
    QFile file(filename);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing";
        return;
    }

    QTextStream out(&file);
    out << slotData << "\n";

    file.close();
}

// Load slots data from a text file
void DoctorWindow::loadSlotsFromFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading";
        return;
    }

    // Retrieve the current user
    CurrentUser *user = CurrentUser::instance();
    QString currentUsername = user->getUsername();

    QTextStream in(&file);
    ui->tableWidget_2->setRowCount(0); // Clear existing data

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        if (fields.size() < 6) {
            qDebug() << "Incorrect data format in file";
            continue;
        }

        QString username = fields[1];

        if (username == currentUsername) {
            int row = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(row);

            // Set items in the order: Slot Id, Date, Status, Time, Duration
            ui->tableWidget_2->setItem(row, 0, new QTableWidgetItem(fields[0])); // Slot Id
            ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(fields[2])); // Date
            ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(fields[3])); // Status
            ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(fields[4])); // Time
            ui->tableWidget_2->setItem(row, 4, new QTableWidgetItem(fields[5])); // Duration
        }
    }

    file.close();
}

// Save medical records data to a text file
void DoctorWindow::saveMedicalRecordsToFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing";
        return;
    }

    QTextStream out(&file);
    int rowCount = ui->tableWidget_3->rowCount();
    int columnCount = ui->tableWidget_3->columnCount();

    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = ui->tableWidget_3->item(row, col);
            if (item) {
                out << item->text();
            }
            if (col < columnCount - 1) {
                out << ","; // Comma-separated
            }
        }
        out << "\n";
    }

    file.close();
}

// Load medical records data from a text file
void DoctorWindow::loadMedicalRecordsFromFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading";
        return;
    }

    QTextStream in(&file);
    ui->tableWidget_3->setRowCount(0); // Clear existing data

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        int row = ui->tableWidget_3->rowCount();
        ui->tableWidget_3->insertRow(row);

        for (int col = 0; col < fields.size(); ++col) {
            ui->tableWidget_3->setItem(row, col, new QTableWidgetItem(fields[col]));
        }
    }

    file.close();
}

// Filter the medical records table based on search text
void DoctorWindow::filterMedicalRecordsTable(const QString &searchText)
{
    bool foundMatch;
    for (int row = 0; row < ui->tableWidget_3->rowCount(); ++row) {
        foundMatch = false;
        for (int col = 0; col < ui->tableWidget_3->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget_3->item(row, col);
            if (item) {
                QString itemText = item->text();
                // Debugging output
                qDebug() << "Checking row" << row << "column" << col << ":" << itemText;

                if (itemText.contains(searchText, Qt::CaseInsensitive)) {
                    foundMatch = true;
                    break;
                }
            }
        }
        // Hide or show row based on match
        ui->tableWidget_3->setRowHidden(row, !foundMatch);
    }
}

void DoctorWindow::on_searchMedicalRecords_textChanged(const QString &text)
{
    filterMedicalRecordsTable(text);
}


void DoctorWindow::loadAppointmentsForDoctor()
{
    // Retrieve the current user
    CurrentUser *user = CurrentUser::instance();
    QString currentUsername = user->getUsername();

    QFile file("appointments.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    ui->tableWidget->setRowCount(0); // Clear existing data

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        if (fields.size() != 6) {
            qDebug() << "Incorrect data format in file";
            continue;
        }

        QString doctorName = fields[4];

        if (doctorName == currentUsername) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);

            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(fields[0])); // Appiontment Id
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(fields[1])); // Slot Id
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(fields[2])); // Patient Name
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(fields[3])); // Contact Number
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(fields[5])); // Status
        }
    }

    file.close();
}

void DoctorWindow::on_deleteAppointmentButton_clicked()
{
    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Cancel Appointment", "Please select an appointment to cancel.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel Appointment", "Are you sure you want to Cancel this appointment?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }

    QString appId = ui->tableWidget->item(row, 0)->text();

    QFile file("appointments.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Unable to open appointments file.");
        return;
    }

    QTextStream in(&file);
    QStringList fileContent;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 6 && fields[0] == appId) {
            fields[5] = "Canceled"; // Update the status to "Canceled"
            line = fields.join(",");
        }
        fileContent.append(line);
    }
    file.close();

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::warning(this, "Error", "Unable to open appointments file for writing.");
        return;
    }

    QTextStream out(&file);
    for (const QString& line : fileContent) {
        out << line << "\n";
    }
    file.close();

    loadAppointmentsForDoctor(); // Refresh the table
}
=======
#include "doctorwindow.h"
#include "ui_doctorwindow.h"
#include <QDebug> // For debugging purposes
#include <QFile>
#include <QTextStream>
#include <QRandomGenerator>

// Constructor
DoctorWindow::DoctorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorWindow)
{
    ui->setupUi(this);

    // Initialize the tables and set column widths
    initializeAppointmentsTable();
    initializeMedicalRecordsTable();
    initializeSlotsTable();

    // Load data from files
    loadSlotsFromFile("slots.txt");
    loadMedicalRecordsFromFile("records.txt");

    // Connect search input to the slot
}

// Destructor
DoctorWindow::~DoctorWindow()
{
    // Save data to files before closing
    saveSlotsToFile("slots.txt");
    saveMedicalRecordsToFile("records.txt");
    delete ui;
}

// Initialize the appointments table
void DoctorWindow::initializeAppointmentsTable()
{
    // Set column count and headers for the appointments table
    ui->tableWidget->setColumnCount(4); // Slot Id, Patient Name, Contact Number, Status
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Slot Id" << "Patient Name" << "Contact Number" << "Status");
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // Set column widths
    ui->tableWidget->setColumnWidth(0, 120); // Slot Id
    ui->tableWidget->setColumnWidth(1, 150); // Patient Name
    ui->tableWidget->setColumnWidth(2, 150); // Contact Number
    ui->tableWidget->setColumnWidth(3, 150); // Status
}

// Initialize the medical records table
void DoctorWindow::initializeMedicalRecordsTable()
{
    // Set column count and headers for the medical records table
    ui->tableWidget_3->setColumnCount(4); // Patient Name, Age, Current Medication, Notes
    ui->tableWidget_3->setHorizontalHeaderLabels(QStringList() << "Patient Name" << "Age" << "Current Medication" << "Notes");
    ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);

    // Set column widths
    ui->tableWidget_3->setColumnWidth(0, 150); // Patient Name
    ui->tableWidget_3->setColumnWidth(1, 60);  // Age
    ui->tableWidget_3->setColumnWidth(2, 200); // Current Medication
    ui->tableWidget_3->setColumnWidth(3, 250); // Notes
}

// Initialize the slots table
void DoctorWindow::initializeSlotsTable()
{
    // Set column count and headers for the slots table
    ui->tableWidget_2->setColumnCount(5); // Slot Id, Date, Status, Time, Duration
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "Slot Id" << "Date" << "Status" << "Time" << "Duration");
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);

    // Set column widths
    ui->tableWidget_2->setColumnWidth(0, 120); // Slot Id
    ui->tableWidget_2->setColumnWidth(1, 150); // Date
    ui->tableWidget_2->setColumnWidth(2, 150); // Status
    ui->tableWidget_2->setColumnWidth(3, 150); // Time
    ui->tableWidget_2->setColumnWidth(4, 150); // Duration
}

// Generate a random slot ID
int DoctorWindow::generateRandomSlotId()
{
    return QRandomGenerator::global()->bounded(10000, 99999);
}

// Handle the Add Slot button click
void DoctorWindow::on_addSlotButton_clicked()
{
    // Gather slot information from input fields
    int slotId = generateRandomSlotId();
    QString date = ui->slotDateEdit->date().toString("yyyy-MM-dd");
    QString status = "Available"; // Default status
    QString time = ui->slotTimeEdit->time().toString("hh:mm");
    QString duration = QString::number(ui->slotDurationSpinBox->value()) + " mins";

    // Add a new row to the table
    int row = ui->tableWidget_2->rowCount();
    ui->tableWidget_2->insertRow(row);
    ui->tableWidget_2->setItem(row, 0, new QTableWidgetItem(QString::number(slotId)));
    ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(date));
    ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(status));
    ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(time));
    ui->tableWidget_2->setItem(row, 4, new QTableWidgetItem(duration));

    // Save data to file
    saveSlotsToFile("slots.txt");
}

// Handle the Edit Slot button click
void DoctorWindow::on_editSlotButton_clicked()
{
    // Get the selected row
    int row = ui->tableWidget_2->currentRow();
    if (row == -1) return; // No selection

    // Update the selected row with new values
    QString date = ui->slotDateEdit->date().toString("yyyy-MM-dd");
    QString status = "Available"; // Default status or get from a ComboBox
    QString time = ui->slotTimeEdit->time().toString("hh:mm");
    QString duration = QString::number(ui->slotDurationSpinBox->value()) + " mins";

    ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(date));
    ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(status));
    ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(time));
    ui->tableWidget_2->setItem(row, 4, new QTableWidgetItem(duration));

    // Save data to file
    saveSlotsToFile("slots.txt");
}

// Handle the Delete Slot button click
void DoctorWindow::on_deleteSlotButton_clicked()
{
    // Get the selected row
    int row = ui->tableWidget_2->currentRow();
    if (row != -1) {
        // Remove the selected row
        ui->tableWidget_2->removeRow(row);

        // Save data to file
        saveSlotsToFile("slots.txt");
    }
}

// Save slots data to a text file
void DoctorWindow::saveSlotsToFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing";
        return;
    }

    QTextStream out(&file);
    int rowCount = ui->tableWidget_2->rowCount();
    int columnCount = ui->tableWidget_2->columnCount();

    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = ui->tableWidget_2->item(row, col);
            if (item) {
                out << item->text();
            }
            if (col < columnCount - 1) {
                out << ","; // Comma-separated
            }
        }
        out << "\n";
    }

    file.close();
}

// Load slots data from a text file
void DoctorWindow::loadSlotsFromFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading";
        return;
    }

    QTextStream in(&file);
    ui->tableWidget_2->setRowCount(0); // Clear existing data

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        int row = ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(row);

        for (int col = 0; col < fields.size(); ++col) {
            ui->tableWidget_2->setItem(row, col, new QTableWidgetItem(fields[col]));
        }
    }

    file.close();
}

// Save medical records data to a text file
void DoctorWindow::saveMedicalRecordsToFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing";
        return;
    }

    QTextStream out(&file);
    int rowCount = ui->tableWidget_3->rowCount();
    int columnCount = ui->tableWidget_3->columnCount();

    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = ui->tableWidget_3->item(row, col);
            if (item) {
                out << item->text();
            }
            if (col < columnCount - 1) {
                out << ","; // Comma-separated
            }
        }
        out << "\n";
    }

    file.close();
}

// Load medical records data from a text file
void DoctorWindow::loadMedicalRecordsFromFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading";
        return;
    }

    QTextStream in(&file);
    ui->tableWidget_3->setRowCount(0); // Clear existing data

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        int row = ui->tableWidget_3->rowCount();
        ui->tableWidget_3->insertRow(row);

        for (int col = 0; col < fields.size(); ++col) {
            ui->tableWidget_3->setItem(row, col, new QTableWidgetItem(fields[col]));
        }
    }

    file.close();
}

// Filter the medical records table based on search text
void DoctorWindow::filterMedicalRecordsTable(const QString &searchText)
{
    for (int row = 0; row < ui->tableWidget_3->rowCount(); ++row) {
        bool match = false;
        for (int col = 0; col < ui->tableWidget_3->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget_3->item(row, col);
            if (item && item->text().contains(searchText, Qt::CaseInsensitive)) {
                match = true;
                break;
            }
        }
        ui->tableWidget_3->setRowHidden(row, !match);
    }
}

// Slot for search text changed
void DoctorWindow::on_searchMedicalRecords_textChanged(const QString &text)
{
    filterMedicalRecordsTable(text);
}
>>>>>>> 81e2f7df5dbae2ba98fe419dce88c0553d014146
