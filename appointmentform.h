#ifndef APPOINTMENTFORM_H
#define APPOINTMENTFORM_H

#include <QDialog>

namespace Ui {
class AppointmentForm;
}

class AppointmentForm : public QDialog
{
    Q_OBJECT

public:
    explicit AppointmentForm(QWidget *parent = nullptr);
    ~AppointmentForm();

private slots:
    void on_doctorComboBox_currentIndexChanged(int index);
    void on_btnBookAppointment_clicked();

private:
    void loadDoctors();
    void loadSlots(const QString &doctor);

    Ui::AppointmentForm *ui;
};

#endif // APPOINTMENTFORM_H
