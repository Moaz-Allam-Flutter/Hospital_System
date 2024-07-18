#ifndef PATIENTAPPOINTMENTS_H
#define PATIENTAPPOINTMENTS_H

#include <QDialog>

namespace Ui {
class PatientAppointments;
}

class PatientAppointments : public QDialog
{
    Q_OBJECT

public:
    explicit PatientAppointments(QWidget *parent = nullptr);
    ~PatientAppointments();

private:
    Ui::PatientAppointments *ui;
};

#endif // PATIENTAPPOINTMENTS_H
