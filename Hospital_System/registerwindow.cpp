#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QFile>
#include <QTextStream>
#include <QIntValidator>

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->labelUsernameError->hide();
    ui->labelPasswordError->hide();
    ui->labelRetypeError->hide();
    ui->labelAgeError->hide();
    ui->labelError->hide();
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButtonRegister_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    QString retypePassword = ui->lineEditRetypePassword->text();
    int age = 2024 - ui->lineEditYear->text().toInt();

    // Validate input
    if (username.isEmpty() || password.isEmpty() || retypePassword.isEmpty() ||
        ui->comboBoxMonth->currentIndex() == -1 || ui->lineEditDay->text().isEmpty() ||
        ui->lineEditYear->text().isEmpty() || (!ui->radioButtonMale->isChecked() && !ui->radioButtonFemale->isChecked()) ||
        (!ui->radioButtonDoctor->isChecked() && !ui->radioButtonPatient->isChecked()))
    {
        ui->labelError->show();
        return;
    }

    if (password != retypePassword)
    {
        ui->labelRetypeError->show();
        return;
    }

    if (userExists(username))
    {
        ui->labelUsernameError->show();
        return;
    }

    // Get the role (Doctor, Patient, Staff)
    QString role;
    if (ui->radioButtonDoctor->isChecked()) role = "Doctor";
    else if (ui->radioButtonPatient->isChecked()) role = "Patient";

    registerUser(username, password, role, age);

    close();
}

bool RegisterWindow::userExists(const QString &username)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields[0] == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void RegisterWindow::registerUser(const QString &username, const QString &password, const QString &role, int age)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << username << "," << password << "," << role << "," << age << "\n";
    file.close();
}
