/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonUpdate;
    QPushButton *pushButtonDelete;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelUsername;
    QLineEdit *lineEditUsername;
    QLabel *labelAge;
    QLineEdit *lineEditAge;
    QLabel *labelType;
    QComboBox *comboBoxType;
    QWidget *tab;
    QTableWidget *tableWidget_2;
    QPushButton *pushButtonDeleteAppointment;

    void setupUi(QDialog *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(1020, 720);
        AdminWindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #f0f4f8;\n"
"    font-family: 'Arial', sans-serif;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: #0094ff;\n"
"    color: #fff;\n"
"    padding: 10px;\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #007acc;\n"
"}\n"
"\n"
"/* Different background colors for each tab */\n"
"QWidget#tab_2 {\n"
"    background-color: #e6f7ff;\n"
"}\n"
"\n"
"QWidget#tab {\n"
"    background-color: #e6ffe6;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #333;\n"
"}\n"
"\n"
"QLineEdit, QComboBox {\n"
"    padding: 5px;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QLineEdit:focus, QComboBox:focus {\n"
"    border-color: #0094ff;\n"
"    box-shadow: 0 0 5px rgba(0, 148, 255, 0.5);\n"
"}\n"
"\n"
"/* Different colors for each button */\n"
"QPushButton#pushButtonAdd {\n"
"    "
                        "background-color: #0094ff;\n"
"    color: #fff;\n"
"    padding: 10px 15px;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton#pushButtonAdd:hover {\n"
"    background-color: #433bff;\n"
"}\n"
"\n"
"QPushButton#pushButtonUpdate, QPushButton#pushButtonDelete {\n"
"    background-color: #dedcff;\n"
"    color: #050315;\n"
"    padding: 10px 15px;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton#pushButtonUpdate:hover, QPushButton#pushButtonDelete:hover {\n"
"    background-color: #c5c3ff;\n"
"}\n"
"\n"
"QPushButton#pushButtonDeleteAppointment {\n"
"    background-color: #f44336;\n"
"    color: #fff;\n"
"    padding: 10px 15px;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton#pushButtonDeleteAppointment:hover {\n"
"    background-color: #da190b;\n"
"}\n"
"\n"
"QLineEdit {\n"
"   "
                        " background-color: #dedcff;\n"
"    border: 1px solid #2118d8;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font-size: 18px;\n"
"    color: #050315;\n"
"}\n"
"\n"
"QTableWidget {\n"
"    background-color: #fbfbfe;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #f0f4f8;\n"
"    color: #333;\n"
"    padding: 5px;\n"
"    border: 1px solid #ccc;\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: #050315;\n"
"    border: 1px solid #ccc;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 5px;\n"
"    border: 1px solid #ccc;\n"
"    color: #000; /* Set the text color to black */\n"
"}\n"
"\n"
"/* Dynamic table columns based on screen size */\n"
"QHeaderView::section {\n"
"    min-width: 50px;\n"
"}\n"
"\n"
"QTableWidget {\n"
"    width: 100%;\n"
"}\n"
"\n"
"QTableWidget::column {\n"
"    min-width: 50px;\n"
"    max-width: 200px;\n"
"    width: auto;\n"
"}\n"
"\n"
"@media (max-width: 1200px) {"
                        "\n"
"    QTableWidget::column {\n"
"        max-width: 150px;\n"
"    }\n"
"}\n"
"\n"
"@media (max-width: 800px) {\n"
"    QTableWidget::column {\n"
"        max-width: 100px;\n"
"    }\n"
"}\n"
"\n"
"@media (max-width: 400px) {\n"
"    QTableWidget::column {\n"
"        max-width: 75px;\n"
"    }\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(AdminWindow);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(AdminWindow);
        tabWidget->setObjectName("tabWidget");
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tableWidget = new QTableWidget(tab_2);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName("tableWidget");

        verticalLayout_2->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonAdd = new QPushButton(tab_2);
        pushButtonAdd->setObjectName("pushButtonAdd");

        horizontalLayout->addWidget(pushButtonAdd);

        pushButtonUpdate = new QPushButton(tab_2);
        pushButtonUpdate->setObjectName("pushButtonUpdate");

        horizontalLayout->addWidget(pushButtonUpdate);

        pushButtonDelete = new QPushButton(tab_2);
        pushButtonDelete->setObjectName("pushButtonDelete");

        horizontalLayout->addWidget(pushButtonDelete);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelUsername = new QLabel(tab_2);
        labelUsername->setObjectName("labelUsername");

        horizontalLayout_2->addWidget(labelUsername);

        lineEditUsername = new QLineEdit(tab_2);
        lineEditUsername->setObjectName("lineEditUsername");

        horizontalLayout_2->addWidget(lineEditUsername);

        labelAge = new QLabel(tab_2);
        labelAge->setObjectName("labelAge");

        horizontalLayout_2->addWidget(labelAge);

        lineEditAge = new QLineEdit(tab_2);
        lineEditAge->setObjectName("lineEditAge");

        horizontalLayout_2->addWidget(lineEditAge);

        labelType = new QLabel(tab_2);
        labelType->setObjectName("labelType");

        horizontalLayout_2->addWidget(labelType);

        comboBoxType = new QComboBox(tab_2);
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->setObjectName("comboBoxType");

        horizontalLayout_2->addWidget(comboBoxType);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        tableWidget_2 = new QTableWidget(tab);
        if (tableWidget_2->columnCount() < 8)
            tableWidget_2->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(7, __qtablewidgetitem10);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(10, 10, 981, 611));
        pushButtonDeleteAppointment = new QPushButton(tab);
        pushButtonDeleteAppointment->setObjectName("pushButtonDeleteAppointment");
        pushButtonDeleteAppointment->setGeometry(QRect(10, 630, 215, 31));
        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(AdminWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QDialog *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "Admin Window", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AdminWindow", "username", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AdminWindow", "age", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AdminWindow", "type", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("AdminWindow", "Add", nullptr));
        pushButtonUpdate->setText(QCoreApplication::translate("AdminWindow", "Update", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("AdminWindow", "Delete", nullptr));
        labelUsername->setText(QCoreApplication::translate("AdminWindow", "Username:", nullptr));
        labelAge->setText(QCoreApplication::translate("AdminWindow", "Age:", nullptr));
        labelType->setText(QCoreApplication::translate("AdminWindow", "Type:", nullptr));
        comboBoxType->setItemText(0, QCoreApplication::translate("AdminWindow", "Doctor", nullptr));
        comboBoxType->setItemText(1, QCoreApplication::translate("AdminWindow", "Patient", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("AdminWindow", "Users", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AdminWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("AdminWindow", "Patient name", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("AdminWindow", "Age", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("AdminWindow", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("AdminWindow", "Contact number", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("AdminWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("AdminWindow", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(7);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("AdminWindow", "Message", nullptr));
        pushButtonDeleteAppointment->setText(QCoreApplication::translate("AdminWindow", "Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("AdminWindow", "Appointments", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
