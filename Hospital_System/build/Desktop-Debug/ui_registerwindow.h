/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditUsername;
    QLabel *labelUsernameError;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditPassword;
    QLabel *labelPasswordError;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditRetypePassword;
    QLabel *labelRetypeError;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBoxDate;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QComboBox *comboBoxMonth;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLineEdit *lineEditDay;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEditYear;
    QLabel *labelAgeError;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBoxGender;
    QWidget *layoutWidget_8;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButtonMale;
    QRadioButton *radioButtonFemale;
    QGroupBox *groupBoxType;
    QWidget *layoutWidget_9;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *radioButtonDoctor;
    QRadioButton *radioButtonPatient;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButtonRegister;
    QLabel *labelError;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(694, 584);
        RegisterWindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #f0f4f8;\n"
"    font-family: 'Arial', sans-serif;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #333;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    padding: 5px;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #0094ff;\n"
"    box-shadow: 0 0 5px rgba(0, 148, 255, 0.5);\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #0094ff;\n"
"    color: #fff;\n"
"    padding: 10px 15px;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007acc;\n"
"}\n"
"\n"
"QGroupBox {\n"
"    font-weight: bold;\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 4px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QRadioButton {\n"
"    margin-left: 5px;\n"
"}\n"
"\n"
"QComboBox {\n"
"    padding: 5px;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border-color: #"
                        "0094ff;\n"
"    box-shadow: 0 0 5px rgba(0, 148, 255, 0.5);\n"
"}\n"
"\n"
"QLabel#error,\n"
"QLabel#labelUsernameError,\n"
"QLabel#labelPasswordError,\n"
"QLabel#labelRetypeError,\n"
"QLabel#labelAgeError {\n"
"    color: #ff0004;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QGroupBox#groupBoxDate,\n"
"QGroupBox#groupBoxGender,\n"
"QGroupBox#groupBoxType {\n"
"    margin: 10px;\n"
"}\n"
""));
        layoutWidget = new QWidget(RegisterWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 13, 671, 561));
        verticalLayout_7 = new QVBoxLayout(layoutWidget);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEditUsername = new QLineEdit(layoutWidget);
        lineEditUsername->setObjectName("lineEditUsername");
        lineEditUsername->setFont(font);

        horizontalLayout->addWidget(lineEditUsername);

        labelUsernameError = new QLabel(layoutWidget);
        labelUsernameError->setObjectName("labelUsernameError");
        QFont font1;
        labelUsernameError->setFont(font1);

        horizontalLayout->addWidget(labelUsernameError);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setFont(font);
        lineEditPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEditPassword);

        labelPasswordError = new QLabel(layoutWidget);
        labelPasswordError->setObjectName("labelPasswordError");
        labelPasswordError->setFont(font1);

        horizontalLayout_2->addWidget(labelPasswordError);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        lineEditRetypePassword = new QLineEdit(layoutWidget);
        lineEditRetypePassword->setObjectName("lineEditRetypePassword");
        lineEditRetypePassword->setFont(font);
        lineEditRetypePassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(lineEditRetypePassword);

        labelRetypeError = new QLabel(layoutWidget);
        labelRetypeError->setObjectName("labelRetypeError");
        labelRetypeError->setFont(font1);

        horizontalLayout_3->addWidget(labelRetypeError);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_7->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        groupBoxDate = new QGroupBox(layoutWidget);
        groupBoxDate->setObjectName("groupBoxDate");
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        groupBoxDate->setFont(font2);
        layoutWidget_3 = new QWidget(groupBoxDate);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(10, 40, 311, 73));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_4 = new QLabel(layoutWidget_3);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        comboBoxMonth = new QComboBox(layoutWidget_3);
        comboBoxMonth->addItem(QString());
        comboBoxMonth->addItem(QString());
        comboBoxMonth->addItem(QString());
        comboBoxMonth->addItem(QString());
        comboBoxMonth->addItem(QString());
        comboBoxMonth->addItem(QString());
        comboBoxMonth->addItem(QString());
        comboBoxMonth->addItem(QString());
        comboBoxMonth->addItem(QString());
        comboBoxMonth->addItem(QString());
        comboBoxMonth->addItem(QString());
        comboBoxMonth->addItem(QString());
        comboBoxMonth->setObjectName("comboBoxMonth");

        verticalLayout_2->addWidget(comboBoxMonth);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_5 = new QLabel(layoutWidget_3);
        label_5->setObjectName("label_5");

        verticalLayout_3->addWidget(label_5);

        lineEditDay = new QLineEdit(layoutWidget_3);
        lineEditDay->setObjectName("lineEditDay");

        verticalLayout_3->addWidget(lineEditDay);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_6 = new QLabel(layoutWidget_3);
        label_6->setObjectName("label_6");

        verticalLayout_4->addWidget(label_6);

        lineEditYear = new QLineEdit(layoutWidget_3);
        lineEditYear->setObjectName("lineEditYear");

        verticalLayout_4->addWidget(lineEditYear);


        horizontalLayout_4->addLayout(verticalLayout_4);


        horizontalLayout_5->addWidget(groupBoxDate);

        labelAgeError = new QLabel(layoutWidget);
        labelAgeError->setObjectName("labelAgeError");
        labelAgeError->setFont(font1);

        horizontalLayout_5->addWidget(labelAgeError);


        verticalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        groupBoxGender = new QGroupBox(layoutWidget);
        groupBoxGender->setObjectName("groupBoxGender");
        layoutWidget_8 = new QWidget(groupBoxGender);
        layoutWidget_8->setObjectName("layoutWidget_8");
        layoutWidget_8->setGeometry(QRect(10, 40, 221, 81));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_8);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        radioButtonMale = new QRadioButton(layoutWidget_8);
        radioButtonMale->setObjectName("radioButtonMale");

        verticalLayout_5->addWidget(radioButtonMale);

        radioButtonFemale = new QRadioButton(layoutWidget_8);
        radioButtonFemale->setObjectName("radioButtonFemale");

        verticalLayout_5->addWidget(radioButtonFemale);


        horizontalLayout_6->addWidget(groupBoxGender);

        groupBoxType = new QGroupBox(layoutWidget);
        groupBoxType->setObjectName("groupBoxType");
        layoutWidget_9 = new QWidget(groupBoxType);
        layoutWidget_9->setObjectName("layoutWidget_9");
        layoutWidget_9->setGeometry(QRect(10, 40, 221, 89));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_9);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        radioButtonDoctor = new QRadioButton(layoutWidget_9);
        radioButtonDoctor->setObjectName("radioButtonDoctor");

        verticalLayout_6->addWidget(radioButtonDoctor);

        radioButtonPatient = new QRadioButton(layoutWidget_9);
        radioButtonPatient->setObjectName("radioButtonPatient");

        verticalLayout_6->addWidget(radioButtonPatient);


        horizontalLayout_6->addWidget(groupBoxType);


        verticalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        pushButtonRegister = new QPushButton(layoutWidget);
        pushButtonRegister->setObjectName("pushButtonRegister");

        horizontalLayout_10->addWidget(pushButtonRegister);

        labelError = new QLabel(layoutWidget);
        labelError->setObjectName("labelError");

        horizontalLayout_10->addWidget(labelError);


        verticalLayout_7->addLayout(horizontalLayout_10);


        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RegisterWindow", "Username             ", nullptr));
        labelUsernameError->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" color:#ff0004;\">user already exits! </span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterWindow", "Password              ", nullptr));
        labelPasswordError->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterWindow", "Retype-Password ", nullptr));
        labelRetypeError->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" color:#ff0004;\">Password not match!</span></p></body></html>", nullptr));
        groupBoxDate->setTitle(QCoreApplication::translate("RegisterWindow", "Date of Birth", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterWindow", "Month", nullptr));
        comboBoxMonth->setItemText(0, QCoreApplication::translate("RegisterWindow", "Jan", nullptr));
        comboBoxMonth->setItemText(1, QCoreApplication::translate("RegisterWindow", "Feb", nullptr));
        comboBoxMonth->setItemText(2, QCoreApplication::translate("RegisterWindow", "Mar", nullptr));
        comboBoxMonth->setItemText(3, QCoreApplication::translate("RegisterWindow", "Apr", nullptr));
        comboBoxMonth->setItemText(4, QCoreApplication::translate("RegisterWindow", "May", nullptr));
        comboBoxMonth->setItemText(5, QCoreApplication::translate("RegisterWindow", "Jun", nullptr));
        comboBoxMonth->setItemText(6, QCoreApplication::translate("RegisterWindow", "Jul", nullptr));
        comboBoxMonth->setItemText(7, QCoreApplication::translate("RegisterWindow", "Aug", nullptr));
        comboBoxMonth->setItemText(8, QCoreApplication::translate("RegisterWindow", "Sep", nullptr));
        comboBoxMonth->setItemText(9, QCoreApplication::translate("RegisterWindow", "Oct", nullptr));
        comboBoxMonth->setItemText(10, QCoreApplication::translate("RegisterWindow", "Nov", nullptr));
        comboBoxMonth->setItemText(11, QCoreApplication::translate("RegisterWindow", "Dec", nullptr));

        label_5->setText(QCoreApplication::translate("RegisterWindow", "Day", nullptr));
        label_6->setText(QCoreApplication::translate("RegisterWindow", "Year", nullptr));
        labelAgeError->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:12pt; color:#ff0004;\">Error: Age is less than 12!</span></p></body></html>", nullptr));
        groupBoxGender->setTitle(QCoreApplication::translate("RegisterWindow", "Gender", nullptr));
        radioButtonMale->setText(QCoreApplication::translate("RegisterWindow", "Male", nullptr));
        radioButtonFemale->setText(QCoreApplication::translate("RegisterWindow", "Female", nullptr));
        groupBoxType->setTitle(QCoreApplication::translate("RegisterWindow", "Acount Type", nullptr));
        radioButtonDoctor->setText(QCoreApplication::translate("RegisterWindow", "Doctor", nullptr));
        radioButtonPatient->setText(QCoreApplication::translate("RegisterWindow", "Patient", nullptr));
        pushButtonRegister->setText(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
        labelError->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" color:#ff0004;\">All fields are required</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
