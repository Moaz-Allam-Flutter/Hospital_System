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

private:
    Ui::medicalrecord *ui;
};

#endif // MEDICALRECORD_H
