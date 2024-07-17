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

private:
    Ui::AppointmentForm *ui;
};

#endif // APPOINTMENTFORM_H
