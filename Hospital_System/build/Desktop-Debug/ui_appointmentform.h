/********************************************************************************
** Form generated from reading UI file 'appointmentform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPOINTMENTFORM_H
#define UI_APPOINTMENTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AppointmentForm
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *titleLayout;
    QLabel *messageTitle;
    QFormLayout *formLayout;
    QLabel *labelPatientName;
    QLineEdit *lineEditPatientName;
    QLabel *labelDoctor;
    QLabel *labelDate;
    QDateEdit *dateEdit;
    QLabel *labelTime;
    QTimeEdit *timeEdit;
    QComboBox *comboBoxDoctor;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnBookAppointment;
    QPushButton *btnCancel;

    void setupUi(QDialog *AppointmentForm)
    {
        if (AppointmentForm->objectName().isEmpty())
            AppointmentForm->setObjectName("AppointmentForm");
        AppointmentForm->resize(400, 432);
        AppointmentForm->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #f7f9fc;\n"
"    font-family: 'Arial', sans-serif;\n"
"    font-size: 14px;\n"
"    padding: 20px;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #333;\n"
"    margin-bottom: 10px;\n"
"}\n"
"\n"
"QLineEdit, QComboBox {\n"
"    padding: 10px;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    background-color: #ffffff;\n"
"    color: #000;  /* Text color in QLineEdit set to black */\n"
"}\n"
"\n"
"QLineEdit:focus, QComboBox:focus {\n"
"    border-color: #007acc;\n"
"    box-shadow: 0 0 5px rgba(0, 122, 204, 0.5);\n"
"}\n"
"\n"
"QPushButton#btnBookAppointment {\n"
"    background-color: #0094ff;\n"
"    color: #fff;\n"
"    padding: 12px 18px;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton#btnBookAppointment:hover {\n"
"    background-color: #218838;\n"
"}\n"
"\n"
"QPushButton#btnCancel {\n"
"    background-color: #dedcff;\n"
"    color: #080608;\n"
"    paddi"
                        "ng: 12px 18px;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton#btnCancel:hover {\n"
"    background-color: #c82333;\n"
"}\n"
"\n"
"QFormLayout {\n"
"    spacing: 10px;\n"
"    margin-bottom: 20px;\n"
"}\n"
"\n"
"QFormLayout QLineEdit, QFormLayout QComboBox {\n"
"    min-width: 250px;\n"
"}\n"
"\n"
"QComboBox {\n"
"    padding: 10px;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border-left: 1px solid #ccc;\n"
"}\n"
"\n"
"QDateEdit, QTimeEdit {\n"
"    padding: 10px;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    background-color: #ffffff;\n"
"    color: #000;  /* Text color in QDateEdit and QTimeEdit set to black */\n"
"}\n"
"\n"
"QDateEdit::down-arrow, QTimeEdit::down-arrow {\n"
"   color: #000;\n"
"}\n"
"\n"
"QDateEdit:focus, QTimeEdit:focus {\n"
"    border-color: #007acc;\n"
"    box-shadow: 0 0 5px rgba(0, 122, "
                        "204, 0.5);\n"
"}\n"
"\n"
"QWidget#appointmentDetails {\n"
"    background-color: #e6f0ff;\n"
"    padding: 15px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QWidget#appointmentDetails QLabel {\n"
"    color: #0056b3;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QWidget#appointmentDetails QLineEdit {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #007acc;\n"
"    color: #000;  /* Text color in QLineEdit within appointmentDetails set to black */\n"
"}\n"
"\n"
"QWidget#appointmentDetails QComboBox {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #007acc;\n"
"}\n"
"\n"
"QWidget#appointmentDetails QDateEdit, QWidget#appointmentDetails QTimeEdit {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #007acc;\n"
"    color: #000;  /* Text color in QDateEdit and QTimeEdit within appointmentDetails set to black */\n"
"}\n"
"\n"
"QWidget#appointmentDetails QDateEdit::down-arrow, QWidget#appointmentDetails QTimeEdit::down-arrow {\n"
"    image: url(:/black-arrow-down.png);  /* Assuming you"
                        " have an image resource for a black arrow */\n"
"}\n"
"\n"
"QWidget#appointmentDetails QPushButton {\n"
"    background-color: #28a745;\n"
"    color: #fff;\n"
"    padding: 10px 15px;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QWidget#appointmentDetails QPushButton:hover {\n"
"    background-color: #218838;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(AppointmentForm);
        verticalLayout->setObjectName("verticalLayout");
        titleLayout = new QVBoxLayout();
        titleLayout->setObjectName("titleLayout");
        messageTitle = new QLabel(AppointmentForm);
        messageTitle->setObjectName("messageTitle");
        messageTitle->setEnabled(true);
        messageTitle->setStyleSheet(QString::fromUtf8("\n"
"         QLabel {\n"
"             font-size: 18px;\n"
"             font-weight: bold;\n"
"         }\n"
"        "));
        messageTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        titleLayout->addWidget(messageTitle);


        verticalLayout->addLayout(titleLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        labelPatientName = new QLabel(AppointmentForm);
        labelPatientName->setObjectName("labelPatientName");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelPatientName);

        lineEditPatientName = new QLineEdit(AppointmentForm);
        lineEditPatientName->setObjectName("lineEditPatientName");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditPatientName);

        labelDoctor = new QLabel(AppointmentForm);
        labelDoctor->setObjectName("labelDoctor");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelDoctor);

        labelDate = new QLabel(AppointmentForm);
        labelDate->setObjectName("labelDate");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelDate);

        dateEdit = new QDateEdit(AppointmentForm);
        dateEdit->setObjectName("dateEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, dateEdit);

        labelTime = new QLabel(AppointmentForm);
        labelTime->setObjectName("labelTime");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelTime);

        timeEdit = new QTimeEdit(AppointmentForm);
        timeEdit->setObjectName("timeEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, timeEdit);

        comboBoxDoctor = new QComboBox(AppointmentForm);
        comboBoxDoctor->setObjectName("comboBoxDoctor");

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBoxDoctor);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnBookAppointment = new QPushButton(AppointmentForm);
        btnBookAppointment->setObjectName("btnBookAppointment");

        horizontalLayout->addWidget(btnBookAppointment);

        btnCancel = new QPushButton(AppointmentForm);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AppointmentForm);

        QMetaObject::connectSlotsByName(AppointmentForm);
    } // setupUi

    void retranslateUi(QDialog *AppointmentForm)
    {
        AppointmentForm->setWindowTitle(QCoreApplication::translate("AppointmentForm", "Appointment Booking", nullptr));
        messageTitle->setText(QCoreApplication::translate("AppointmentForm", "Appointment Booking Form", nullptr));
        labelPatientName->setText(QCoreApplication::translate("AppointmentForm", "Patient Name:", nullptr));
        labelDoctor->setText(QCoreApplication::translate("AppointmentForm", "Doctor:", nullptr));
        labelDate->setText(QCoreApplication::translate("AppointmentForm", "Date:", nullptr));
        labelTime->setText(QCoreApplication::translate("AppointmentForm", "Time:", nullptr));
        btnBookAppointment->setText(QCoreApplication::translate("AppointmentForm", "Book Appointment", nullptr));
        btnCancel->setText(QCoreApplication::translate("AppointmentForm", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppointmentForm: public Ui_AppointmentForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPOINTMENTFORM_H
