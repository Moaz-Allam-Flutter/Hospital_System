// adminwindow.cpp
#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>

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
    ui->tableWidget->setRowCount(0);

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 4)
        {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(fields[0])); // Username
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(fields[3])); // Age
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(fields[2])); // Type
        }
    }

    file.close();
}
