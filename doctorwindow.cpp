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
