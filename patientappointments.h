#ifndef PATIENTAPPOINTMENTS_H
#define PATIENTAPPOINTMENTS_H

#include <QDialog>
#include <QString>

namespace Ui {
class PatientAppointments;
}

class PatientAppointments : public QDialog
{
    Q_OBJECT

public:
    explicit PatientAppointments(QWidget *parent = nullptr);
    ~PatientAppointments();

private slots:
    void loadAppointments();
    void on_editAppointmentButton_clicked();
    void on_deleteAppointmentButton_clicked();
    void on_addAppointmentButton_clicked();  // Added for completeness

private:
    Ui::PatientAppointments *ui;
};

#endif // PATIENTAPPOINTMENTS_H
