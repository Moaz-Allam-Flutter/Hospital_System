#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <QMap>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonUpdate_clicked();
    void on_pushButtonDelete_clicked();
    void on_tableWidget_itemSelectionChanged();

private:
    Ui::AdminWindow *ui;
    QMap<QString, QString> userPasswords; // Add this line
    void loadUserList();
    void saveUserList();
};

#endif // ADMINWINDOW_H
