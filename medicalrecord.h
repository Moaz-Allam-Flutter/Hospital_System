#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H

#include <QDialog>

namespace Ui {
class medicalrecord;
}

class medicalrecord : public QDialog
{
    Q_OBJECT

public:
    explicit medicalrecord(QWidget *parent = nullptr);
    ~medicalrecord();

private slots:
    void on_pushButtonSave_clicked();  // Slot for the Save button

private:
    void loadRecord();  // Declaration of loadRecord method

    Ui::medicalrecord *ui;
};

#endif // MEDICALRECORD_H
