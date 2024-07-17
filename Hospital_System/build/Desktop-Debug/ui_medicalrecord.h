/********************************************************************************
** Form generated from reading UI file 'medicalrecord.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDICALRECORD_H
#define UI_MEDICALRECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_medicalrecord
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QLabel *labelPatientInfo;
    QLineEdit *lineEditName;
    QLineEdit *lineEditAge;
    QLabel *labelMedicalHistory;
    QTextEdit *textEditHistory;
    QLabel *labelCurrentMedications;
    QTextEdit *textEditMedications;
    QLabel *labelAppointments;
    QTextEdit *textEditAppointments;
    QLabel *labelNotes;
    QTextEdit *textEditNotes;
    QPushButton *pushButtonSave;

    void setupUi(QDialog *medicalrecord)
    {
        if (medicalrecord->objectName().isEmpty())
            medicalrecord->setObjectName("medicalrecord");
        medicalrecord->resize(600, 500);
        verticalLayout = new QVBoxLayout(medicalrecord);
        verticalLayout->setObjectName("verticalLayout");
        labelTitle = new QLabel(medicalrecord);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        labelPatientInfo = new QLabel(medicalrecord);
        labelPatientInfo->setObjectName("labelPatientInfo");

        verticalLayout->addWidget(labelPatientInfo);

        lineEditName = new QLineEdit(medicalrecord);
        lineEditName->setObjectName("lineEditName");

        verticalLayout->addWidget(lineEditName);

        lineEditAge = new QLineEdit(medicalrecord);
        lineEditAge->setObjectName("lineEditAge");

        verticalLayout->addWidget(lineEditAge);

        labelMedicalHistory = new QLabel(medicalrecord);
        labelMedicalHistory->setObjectName("labelMedicalHistory");

        verticalLayout->addWidget(labelMedicalHistory);

        textEditHistory = new QTextEdit(medicalrecord);
        textEditHistory->setObjectName("textEditHistory");

        verticalLayout->addWidget(textEditHistory);

        labelCurrentMedications = new QLabel(medicalrecord);
        labelCurrentMedications->setObjectName("labelCurrentMedications");

        verticalLayout->addWidget(labelCurrentMedications);

        textEditMedications = new QTextEdit(medicalrecord);
        textEditMedications->setObjectName("textEditMedications");

        verticalLayout->addWidget(textEditMedications);

        labelAppointments = new QLabel(medicalrecord);
        labelAppointments->setObjectName("labelAppointments");

        verticalLayout->addWidget(labelAppointments);

        textEditAppointments = new QTextEdit(medicalrecord);
        textEditAppointments->setObjectName("textEditAppointments");

        verticalLayout->addWidget(textEditAppointments);

        labelNotes = new QLabel(medicalrecord);
        labelNotes->setObjectName("labelNotes");

        verticalLayout->addWidget(labelNotes);

        textEditNotes = new QTextEdit(medicalrecord);
        textEditNotes->setObjectName("textEditNotes");

        verticalLayout->addWidget(textEditNotes);

        pushButtonSave = new QPushButton(medicalrecord);
        pushButtonSave->setObjectName("pushButtonSave");

        verticalLayout->addWidget(pushButtonSave);


        retranslateUi(medicalrecord);

        QMetaObject::connectSlotsByName(medicalrecord);
    } // setupUi

    void retranslateUi(QDialog *medicalrecord)
    {
        medicalrecord->setWindowTitle(QCoreApplication::translate("medicalrecord", "Medical Record", nullptr));
        labelTitle->setText(QCoreApplication::translate("medicalrecord", "Patient Medical Record", nullptr));
        labelPatientInfo->setText(QCoreApplication::translate("medicalrecord", "Patient Information:", nullptr));
        lineEditName->setPlaceholderText(QCoreApplication::translate("medicalrecord", "Name", nullptr));
        lineEditAge->setPlaceholderText(QCoreApplication::translate("medicalrecord", "Age", nullptr));
        labelMedicalHistory->setText(QCoreApplication::translate("medicalrecord", "Medical History:", nullptr));
        labelCurrentMedications->setText(QCoreApplication::translate("medicalrecord", "Current Medications:", nullptr));
        labelAppointments->setText(QCoreApplication::translate("medicalrecord", "Appointments:", nullptr));
        labelNotes->setText(QCoreApplication::translate("medicalrecord", "Notes:", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("medicalrecord", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class medicalrecord: public Ui_medicalrecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDICALRECORD_H
