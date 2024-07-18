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
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields[1] == doctor) {
            ui->tableWidgetSlots->insertRow(row);
            for (int col = 0; col < fields.size(); ++col) {
                ui->tableWidgetSlots->setItem(row, col, new QTableWidgetItem(fields[col]));
            }
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
