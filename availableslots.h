#ifndef AVAILABLESLOTS_H
#define AVAILABLESLOTS_H

#include <QDialog>

namespace Ui {
class AvailableSlots;
}

class AvailableSlots : public QDialog
{
    Q_OBJECT

public:
    explicit AvailableSlots(QWidget *parent = nullptr);
    ~AvailableSlots();

private slots:
    void on_doctorComboBox_currentIndexChanged(int index);
    void loadDoctors();
    void loadSlots(const QString &doctor);

private:
    Ui::AvailableSlots *ui;
};

#endif // AVAILABLESLOTS_H
