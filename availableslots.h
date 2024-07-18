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

private:
    Ui::AvailableSlots *ui;
};

#endif // AVAILABLESLOTS_H
