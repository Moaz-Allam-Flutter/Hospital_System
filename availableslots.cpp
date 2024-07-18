#include "availableslots.h"
#include "ui_availableslots.h"

AvailableSlots::AvailableSlots(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AvailableSlots)
{
    ui->setupUi(this);
}

AvailableSlots::~AvailableSlots()
{
    delete ui;
}
