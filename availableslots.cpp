#include "availableslots.h"
#include "ui_availableslots.h"
#include <QFile>
#include <QTextStream>

AvailableSlots::AvailableSlots(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AvailableSlots)
{
    ui->setupUi(this);
    ui->tableWidgetSlots->horizontalHeader()->setStretchLastSection(true);
    loadDoctors();
    connect(ui->comboBoxDoctor, SIGNAL(currentIndexChanged(int)), this, SLOT(on_doctorComboBox_currentIndexChanged(int)));
}

AvailableSlots::~AvailableSlots()
{
    delete ui;
}

void AvailableSlots::loadDoctors()
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

void AvailableSlots::loadSlots(const QString &doctor)
{
    ui->tableWidgetSlots->clearContents();
    ui->tableWidgetSlots->setRowCount(0);

    QFile file("slots.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading";
        return;
    }

    QTextStream in(&file);
    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        // Check if the current line matches the doctor
        if (fields.size() >= 6 && fields[1] == doctor) {
            ui->tableWidgetSlots->insertRow(row);

            // Set items in the order: SlotID, DoctorName, Date, Time, Duration, Available
            ui->tableWidgetSlots->setItem(row, 0, new QTableWidgetItem(fields[0])); // SlotID
            ui->tableWidgetSlots->setItem(row, 1, new QTableWidgetItem(fields[1])); // DoctorName
            ui->tableWidgetSlots->setItem(row, 2, new QTableWidgetItem(fields[2])); // Date
            ui->tableWidgetSlots->setItem(row, 3, new QTableWidgetItem(fields[4])); // Time
            ui->tableWidgetSlots->setItem(row, 4, new QTableWidgetItem(fields[5])); // Duration
            ui->tableWidgetSlots->setItem(row, 5, new QTableWidgetItem(fields[3])); // Available

            row++;
        }
    }

    file.close();
}


void AvailableSlots::on_doctorComboBox_currentIndexChanged(int index)
{
    QString selectedDoctor = ui->comboBoxDoctor->itemText(index);
    loadSlots(selectedDoctor);
}
