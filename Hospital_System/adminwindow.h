#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class AdminWindow; }
QT_END_NAMESPACE

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
    void loadUserList();
    void saveUserList();
    const QString defaultPassword = "123";
};

#endif // ADMINWINDOW_H
