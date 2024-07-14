#include "doctorwindow.h"
#include "ui_doctorwindow.h"

DoctorWindow::DoctorWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DoctorWindow)
{
    ui->setupUi(this);
}

DoctorWindow::~DoctorWindow()
{
    delete ui;
}
