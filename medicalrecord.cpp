#include "medicalrecord.h"
#include "ui_medicalrecord.h"

medicalrecord::medicalrecord(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::medicalrecord)
{
    ui->setupUi(this);
}

medicalrecord::~medicalrecord()
{
    delete ui;
}
