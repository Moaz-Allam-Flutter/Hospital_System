#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "registerwindow.h"
#include "doctorwindow.h"
#include "adminwindow.h"
#include "patientwindow.h"
#include <QFile>
#include <QTextStream>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->labelError->hide();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    QString role;

    if (validateUser(username, password, role))
    {
        if (role == "Doctor") {
            DoctorWindow *doctorWindow = new DoctorWindow();
            doctorWindow->show();
        } else if (role == "Patient") {
            PatientWindow *patientWindow = new PatientWindow();
            patientWindow->show();
        } else if (role == "Admin") {
            AdminWindow *adminWindow = new AdminWindow();
            adminWindow->show();
        }
        close();
    }
    else
    {
        ui->labelError->setText("<html><head/><body><p><span style=\" color:#ff0004;\">Invalid username or password!</span></p></body></html>");
        ui->labelError->show();
    }
}

void LoginWindow::on_pushButtonRegister_clicked()
{
    RegisterWindow registerWindow(this);
    registerWindow.exec();
}

bool LoginWindow::validateUser(const QString &username, const QString &password, QString &role)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields[0] == username && fields[1] == password)
        {
            role = fields[2];
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
