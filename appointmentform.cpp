#include "appointmentform.h"
#include "ui_appointmentform.h"

AppointmentForm::AppointmentForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AppointmentForm)
{
    ui->setupUi(this);
}

AppointmentForm::~AppointmentForm()
{
    delete ui;
}
