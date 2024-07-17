/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditUsername;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditPassword;
    QLabel *labelError;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonLogin;
    QPushButton *pushButtonRegister;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(652, 333);
        LoginWindow->setStyleSheet(QString::fromUtf8("/* General Styles */\n"
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
"QPushButton:hover {\n"
"    background-color: #433bff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2118d8;\n"
"    padding-left: 15px;\n"
"    padding-top: 15px;\n"
"}\n"
"\n"
"/* Register Button Specific St"
                        "yles */\n"
"QPushButton#pushButtonRegister {\n"
"    background-color: #dedcff;\n"
"    color: #050315;\n"
"}\n"
"\n"
"QPushButton#pushButtonRegister:hover {\n"
"    background-color: #c7c4ff;\n"
"}\n"
"\n"
"QPushButton#pushButtonRegister:pressed {\n"
"    background-color: #dedcff;\n"
"    padding-left: 15px;\n"
"    padding-top: 15px;\n"
"}\n"
""));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 631, 294));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setBold(true);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEditUsername = new QLineEdit(layoutWidget);
        lineEditUsername->setObjectName("lineEditUsername");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        lineEditUsername->setFont(font1);

        horizontalLayout->addWidget(lineEditUsername);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setFont(font1);
        lineEditPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEditPassword);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        labelError = new QLabel(layoutWidget);
        labelError->setObjectName("labelError");
        labelError->setFont(font);

        verticalLayout_2->addWidget(labelError);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButtonLogin = new QPushButton(layoutWidget);
        pushButtonLogin->setObjectName("pushButtonLogin");
        pushButtonLogin->setFont(font);

        horizontalLayout_3->addWidget(pushButtonLogin);

        pushButtonRegister = new QPushButton(layoutWidget);
        pushButtonRegister->setObjectName("pushButtonRegister");
        pushButtonRegister->setFont(font);

        horizontalLayout_3->addWidget(pushButtonRegister);


        verticalLayout_2->addLayout(horizontalLayout_3);

        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 652, 29));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "LoginWindow", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "Username       ", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "Password        ", nullptr));
        labelError->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        pushButtonLogin->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        pushButtonRegister->setText(QCoreApplication::translate("LoginWindow", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
