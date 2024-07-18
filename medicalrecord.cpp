#include "medicalrecord.h"
#include "ui_medicalrecord.h"
#include "currentuser.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

medicalrecord::medicalrecord(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::medicalrecord)
{
    ui->setupUi(this);

    // Load existing record for the current user
    loadRecord();
}

medicalrecord::~medicalrecord()
{
    delete ui;
}

void medicalrecord::on_pushButtonSave_clicked()
{
    // Retrieve the current user
    CurrentUser *user = CurrentUser::instance();
    QString username = user->getUsername();

    // Retrieve data from the form
    QString name = ui->lineEditName->text();
    QString age = ui->lineEditAge->text();
    QString medicalHistory = ui->textEditHistory->toPlainText();
    QString currentMedications = ui->textEditMedications->toPlainText();
    QString notes = ui->textEditNotes->toPlainText();

    // Create a string to be saved
    QString recordData = QString("%1,%2,%3,%4,%5,%6")
                             .arg(username)
                             .arg(name)
                             .arg(age)
                             .arg(medicalHistory)
                             .arg(currentMedications)
                             .arg(notes);

    // Open records.txt for appending
    QFile file("records.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "Save Error", "Failed to open records.txt for writing.");
        return;
    }

    QTextStream out(&file);
    out << recordData << "\n";
    file.close();

    // Notify user of successful save
    QMessageBox::information(this, "Save Successful", "Medical record has been saved successfully.");
}

void medicalrecord::loadRecord()
{
    // Retrieve the current user
    CurrentUser *user = CurrentUser::instance();
    QString username = user->getUsername();

    // Open records.txt for reading
    QFile file("records.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Load Error", "Failed to open records.txt for reading.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields[0] == username) {
            // Populate the form fields with the data from the record
            ui->lineEditName->setText(fields[1]);
            ui->lineEditAge->setText(fields[2]);
            ui->textEditHistory->setPlainText(fields[3]);
            ui->textEditMedications->setPlainText(fields[4]);
            ui->textEditNotes->setPlainText(fields[5]);
            file.close();
            return;
        }
    }

    file.close();
}
