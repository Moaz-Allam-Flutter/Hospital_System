#include "patientappointments.h"
#include "ui_patientappointments.h"

PatientAppointments::PatientAppointments(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PatientAppointments)
{
    ui->setupUi(this);
}

PatientAppointments::~PatientAppointments()
{
    delete ui;
}
