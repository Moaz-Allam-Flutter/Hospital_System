/********************************************************************************
** Form generated from reading UI file 'patientwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTWINDOW_H
#define UI_PATIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PatientWindow
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *btnBookAppointment;
    QPushButton *btnFillMedicalRecord;
    QPushButton *btnMessageHealthcareProvider;
    QPushButton *btnPastAppointments;

    void setupUi(QDialog *PatientWindow)
    {
        if (PatientWindow->objectName().isEmpty())
            PatientWindow->setObjectName("PatientWindow");
        PatientWindow->resize(406, 384);
        PatientWindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    color: #050315;\n"
"    background-color: #fbfbfe;\n"
"    font-family: 'Arial', sans-serif;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #312c93;\n"
"    color: #fbfbfe;\n"
"	font-size: 24px;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    margin: 10px auto;\n"
"    width: 300px;\n"
"    height: 50px;\n"
"    display: block;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #433bff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #dedcff;\n"
"    color: #312c93;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(PatientWindow);
        verticalLayout->setObjectName("verticalLayout");
        btnBookAppointment = new QPushButton(PatientWindow);
        btnBookAppointment->setObjectName("btnBookAppointment");

        verticalLayout->addWidget(btnBookAppointment);

        btnFillMedicalRecord = new QPushButton(PatientWindow);
        btnFillMedicalRecord->setObjectName("btnFillMedicalRecord");

        verticalLayout->addWidget(btnFillMedicalRecord);

        btnMessageHealthcareProvider = new QPushButton(PatientWindow);
        btnMessageHealthcareProvider->setObjectName("btnMessageHealthcareProvider");

        verticalLayout->addWidget(btnMessageHealthcareProvider);

        btnPastAppointments = new QPushButton(PatientWindow);
        btnPastAppointments->setObjectName("btnPastAppointments");

        verticalLayout->addWidget(btnPastAppointments);


        retranslateUi(PatientWindow);

        QMetaObject::connectSlotsByName(PatientWindow);
    } // setupUi

    void retranslateUi(QDialog *PatientWindow)
    {
        PatientWindow->setWindowTitle(QCoreApplication::translate("PatientWindow", "Patient Window", nullptr));
        btnBookAppointment->setText(QCoreApplication::translate("PatientWindow", "Book an Appointment", nullptr));
        btnFillMedicalRecord->setText(QCoreApplication::translate("PatientWindow", "Fill a Medical Record", nullptr));
        btnMessageHealthcareProvider->setText(QCoreApplication::translate("PatientWindow", "Message a Healthcare Provider", nullptr));
        btnPastAppointments->setText(QCoreApplication::translate("PatientWindow", "Past Appointments", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientWindow: public Ui_PatientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTWINDOW_H
