#include "patientwindow.h"
#include "ui_patientwindow.h"
#include "appointmentform.h"
#include "availableslots.h"
#include "patientappointments.h"
#include "medicalrecord.h"

PatientWindow::PatientWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PatientWindow)
{
    ui->setupUi(this);
}

PatientWindow::~PatientWindow()
{
    delete ui;
}

void PatientWindow::on_btnBookAppointment_clicked()
{
    AppointmentForm *appointmentForm = new AppointmentForm();
    appointmentForm->show();
}

void PatientWindow::on_btnFillMedicalRecord_clicked()
{
    AvailableSlots *availableSlots = new AvailableSlots();
    availableSlots->show();
}

void PatientWindow::on_btnMessageHealthcareProvider_clicked()
{
    PatientAppointments *patientAppointments = new PatientAppointments();
    patientAppointments->show();
}

void PatientWindow::on_btnPastAppointments_clicked()
{
    medicalrecord *record = new medicalrecord();
    record->show();
}
