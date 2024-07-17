/********************************************************************************
** Form generated from reading UI file 'doctorwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORWINDOW_H
#define UI_DOCTORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoctorWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *appointmentsTab;
    QVBoxLayout *verticalLayout_2;
    QTableView *appointmentsTable;
    QHBoxLayout *buttonsLayout;
    QPushButton *addAppointmentButton;
    QPushButton *editAppointmentButton;
    QPushButton *deleteAppointmentButton;
    QWidget *medicalRecordsTab;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *searchBar;
    QListView *patientList;
    QTextEdit *medicalRecordDetails;
    QHBoxLayout *buttonsLayout2;
    QPushButton *addRecordButton;
    QPushButton *editRecordButton;
    QPushButton *deleteRecordButton;

    void setupUi(QDialog *DoctorWindow)
    {
        if (DoctorWindow->objectName().isEmpty())
            DoctorWindow->setObjectName("DoctorWindow");
        DoctorWindow->resize(704, 474);
        verticalLayout = new QVBoxLayout(DoctorWindow);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(DoctorWindow);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8("/* General Styles */\n"
"QWidget {\n"
"    background-color: #fbfbfe;\n"
"    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;\n"
"    font-size: 18px;\n"
"    color: #050315;\n"
"}\n"
"\n"
"/* QLabel Styles */\n"
"QLabel {\n"
"    color: #050315;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* QLineEdit Styles */\n"
"QLineEdit {\n"
"    background-color: #dedcff;\n"
"    border: 1px solid #2118d8;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font-size: 18px;\n"
"    color: #050315;\n"
"}\n"
"\n"
"/* QTextEdit Styles */\n"
"QTextEdit {\n"
"    background-color: #dedcff;\n"
"    border: 1px solid #2118d8;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font-size: 18px;\n"
"    color: #050315;\n"
"}\n"
"\n"
"/* QPushButton Styles */\n"
"QPushButton {\n"
"    background-color: #0094ff;\n"
"    color: #fbfbfe;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 10px 20px;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPus"
                        "hButton:hover {\n"
"    background-color: #433bff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2118d8;\n"
"    padding-left: 15px;\n"
"    padding-top: 15px;\n"
"}\n"
"\n"
"/* Save Button Specific Styles */\n"
"QPushButton#pushButtonSave {\n"
"    background-color: #0094ff;\n"
"    color: #fbfbfe;\n"
"}\n"
"\n"
"QPushButton#pushButtonSave:hover {\n"
"    background-color: #433bff;\n"
"}\n"
"\n"
"QPushButton#pushButtonSave:pressed {\n"
"    background-color: #2118d8;\n"
"    padding-left: 15px;\n"
"    padding-top: 15px;\n"
"}\n"
""));
        appointmentsTab = new QWidget();
        appointmentsTab->setObjectName("appointmentsTab");
        verticalLayout_2 = new QVBoxLayout(appointmentsTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        appointmentsTable = new QTableView(appointmentsTab);
        appointmentsTable->setObjectName("appointmentsTable");

        verticalLayout_2->addWidget(appointmentsTable);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName("buttonsLayout");
        addAppointmentButton = new QPushButton(appointmentsTab);
        addAppointmentButton->setObjectName("addAppointmentButton");

        buttonsLayout->addWidget(addAppointmentButton);

        editAppointmentButton = new QPushButton(appointmentsTab);
        editAppointmentButton->setObjectName("editAppointmentButton");

        buttonsLayout->addWidget(editAppointmentButton);

        deleteAppointmentButton = new QPushButton(appointmentsTab);
        deleteAppointmentButton->setObjectName("deleteAppointmentButton");

        buttonsLayout->addWidget(deleteAppointmentButton);


        verticalLayout_2->addLayout(buttonsLayout);

        tabWidget->addTab(appointmentsTab, QString());
        medicalRecordsTab = new QWidget();
        medicalRecordsTab->setObjectName("medicalRecordsTab");
        verticalLayout_3 = new QVBoxLayout(medicalRecordsTab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        searchBar = new QLineEdit(medicalRecordsTab);
        searchBar->setObjectName("searchBar");

        verticalLayout_3->addWidget(searchBar);

        patientList = new QListView(medicalRecordsTab);
        patientList->setObjectName("patientList");

        verticalLayout_3->addWidget(patientList);

        medicalRecordDetails = new QTextEdit(medicalRecordsTab);
        medicalRecordDetails->setObjectName("medicalRecordDetails");

        verticalLayout_3->addWidget(medicalRecordDetails);

        buttonsLayout2 = new QHBoxLayout();
        buttonsLayout2->setObjectName("buttonsLayout2");
        addRecordButton = new QPushButton(medicalRecordsTab);
        addRecordButton->setObjectName("addRecordButton");

        buttonsLayout2->addWidget(addRecordButton);

        editRecordButton = new QPushButton(medicalRecordsTab);
        editRecordButton->setObjectName("editRecordButton");

        buttonsLayout2->addWidget(editRecordButton);

        deleteRecordButton = new QPushButton(medicalRecordsTab);
        deleteRecordButton->setObjectName("deleteRecordButton");

        buttonsLayout2->addWidget(deleteRecordButton);


        verticalLayout_3->addLayout(buttonsLayout2);

        tabWidget->addTab(medicalRecordsTab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(DoctorWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DoctorWindow);
    } // setupUi

    void retranslateUi(QDialog *DoctorWindow)
    {
        DoctorWindow->setWindowTitle(QCoreApplication::translate("DoctorWindow", "Doctor Window", nullptr));
        addAppointmentButton->setText(QCoreApplication::translate("DoctorWindow", "Add", nullptr));
        editAppointmentButton->setText(QCoreApplication::translate("DoctorWindow", "Edit", nullptr));
        deleteAppointmentButton->setText(QCoreApplication::translate("DoctorWindow", "Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(appointmentsTab), QCoreApplication::translate("DoctorWindow", "Appointments", nullptr));
        searchBar->setPlaceholderText(QCoreApplication::translate("DoctorWindow", "Search Patient", nullptr));
        addRecordButton->setText(QCoreApplication::translate("DoctorWindow", "Add", nullptr));
        editRecordButton->setText(QCoreApplication::translate("DoctorWindow", "Edit", nullptr));
        deleteRecordButton->setText(QCoreApplication::translate("DoctorWindow", "Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(medicalRecordsTab), QCoreApplication::translate("DoctorWindow", "Medical Records", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorWindow: public Ui_DoctorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORWINDOW_H
