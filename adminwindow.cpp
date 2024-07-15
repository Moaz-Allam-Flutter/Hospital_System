// adminwindow.cpp
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

    // Connect signals and slots
    connect(ui->pushButtonAdd, &QPushButton::clicked, this, &AdminWindow::on_pushButtonAdd_clicked);
    connect(ui->pushButtonUpdate, &QPushButton::clicked, this, &AdminWindow::on_pushButtonUpdate_clicked);
    connect(ui->pushButtonDelete, &QPushButton::clicked, this, &AdminWindow::on_pushButtonDelete_clicked);
    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, &AdminWindow::on_tableWidget_itemSelectionChanged);
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
    ui->tableWidget->setRowCount(0); // Clear existing rows

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 4) // Ensure there are exactly 4 fields (username, password, role, age)
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

void AdminWindow::addUser(const QString &username, const QString &password, const QString &role, int age)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << username << "," << password << "," << role << "," << age << "\n";
    file.close();

    loadUserList();
}

void AdminWindow::updateUser(const QString &username, const QString &password, const QString &role, int age)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 4 && fields[0] == username)
        {
            line = QString("%1,%2,%3,%4").arg(username, password, role, QString::number(age));
        }
        lines.append(line);
    }
    file.close();

    QFile outFile("users.txt");
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&outFile);
    for (const QString &line : lines)
    {
        out << line << "\n";
    }
    outFile.close();

    loadUserList();
}

void AdminWindow::deleteUser(const QString &username)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 4 && fields[0] != username)
        {
            lines.append(line);
        }
    }
    file.close();

    QFile outFile("users.txt");
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&outFile);
    for (const QString &line : lines)
    {
        out << line << "\n";
    }
    outFile.close();

    loadUserList();
}

QString AdminWindow::getSelectedUsername()
{
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget->selectedItems();
    if (selectedItems.isEmpty())
        return QString();

    return selectedItems.first()->text();
}

void AdminWindow::on_pushButtonAdd_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = "defaultpassword"; // Password should be set up securely
    QString role = ui->comboBoxType->currentText();
    int age = ui->lineEditAge->text().toInt();

    if (username.isEmpty() || age <= 0)
    {
        QMessageBox::warning(this, "Input Error", "Please provide a valid username and age.");
        return;
    }

    addUser(username, password, role, age);
}

void AdminWindow::on_pushButtonUpdate_clicked()
{
    QString username = getSelectedUsername();
    if (username.isEmpty())
    {
        QMessageBox::warning(this, "Selection Error", "Please select a user to update.");
        return;
    }

    QString newUsername = ui->lineEditUsername->text();
    QString password = "defaultpassword"; // Password should be set up securely
    QString role = ui->comboBoxType->currentText();
    int age = ui->lineEditAge->text().toInt();

    if (newUsername.isEmpty() || age <= 0)
    {
        QMessageBox::warning(this, "Input Error", "Please provide a valid username and age.");
        return;
    }

    updateUser(username, password, role, age);
}

void AdminWindow::on_pushButtonDelete_clicked()
{
    QString username = getSelectedUsername();
    if (username.isEmpty())
    {
        QMessageBox::warning(this, "Selection Error", "Please select a user to delete.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete User", "Are you sure you want to delete this user?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        deleteUser(username);
    }
}

void AdminWindow::on_tableWidget_itemSelectionChanged()
{
    QString username = getSelectedUsername();
    if (username.isEmpty())
        return;

    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 4 && fields[0] == username)
        {
            ui->lineEditUsername->setText(fields[0]);
            ui->lineEditAge->setText(fields[3]);
            ui->comboBoxType->setCurrentText(fields[2]);
            break;
        }
    }
    file.close();
}
