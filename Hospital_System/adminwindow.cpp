#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>

AdminWindow::AdminWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    loadUserList();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::loadUserList()
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(fields[0])); // username
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(fields[3])); // age
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(fields[2])); // role
    }

    file.close();
}

void AdminWindow::saveUserList()
{
    QFile file("users.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QString username = ui->tableWidget->item(row, 0)->text();
        QString age = ui->tableWidget->item(row, 1)->text();
        QString role = ui->tableWidget->item(row, 2)->text();
        QString password = "defaultpassword";  // Default password for new users

        out << username << "," << password << "," << role << "," << age << "\n";
    }

    file.close();
}

void AdminWindow::on_pushButtonAdd_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString age = ui->lineEditAge->text();
    QString role = ui->comboBoxType->currentText();

    // Check if the username already exists
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        if (ui->tableWidget->item(row, 0)->text() == username) {
            QMessageBox::warning(this, "Add User", "Username already taken.");
            return;
        }
    }

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(username));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(age));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(role));

    saveUserList();
}

void AdminWindow::on_pushButtonUpdate_clicked()
{
    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Update User", "Please select a user to update.");
        return;
    }

    QString username = ui->lineEditUsername->text();
    QString age = ui->lineEditAge->text();
    QString role = ui->comboBoxType->currentText();

    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(username));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(age));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(role));

    saveUserList();
}

void AdminWindow::on_pushButtonDelete_clicked()
{
    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Delete User", "Please select a user to delete.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete User", "Are you sure you want to delete this user?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        ui->tableWidget->removeRow(row);
        saveUserList();
    }
}

void AdminWindow::on_tableWidget_itemSelectionChanged()
{
    int row = ui->tableWidget->currentRow();
    if (row < 0) return;

    QString username = ui->tableWidget->item(row, 0)->text();
    QString age = ui->tableWidget->item(row, 1)->text();
    QString role = ui->tableWidget->item(row, 2)->text();

    ui->lineEditUsername->setText(username);
    ui->lineEditAge->setText(age);
    ui->comboBoxType->setCurrentText(role);
}
