#include "patientwindow.h"
#include "ui_patientwindow.h"

patientWindow::patientWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::patientWindow)
{
    ui->setupUi(this);
}

patientWindow::~patientWindow()
{
    delete ui;
}
