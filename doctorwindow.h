#ifndef DOCTORWINDOW_H
#define DOCTORWINDOW_H

#include <QDialog>

namespace Ui {
class DoctorWindow;
}

class DoctorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DoctorWindow(QWidget *parent = nullptr);
    ~DoctorWindow();

private slots:
    void addAppointment();
    void editAppointment();
    void deleteAppointment();
    void addRecord();
    void editRecord();
    void deleteRecord();
    void loadAppointments();
    void loadPatients();

private:
    Ui::DoctorWindow *ui;
};

#endif // DOCTORWINDOW_H
