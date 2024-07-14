#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void on_pushButtonRegister_clicked();

private:
    Ui::RegisterWindow *ui;
    bool userExists(const QString &username);
    void registerUser(const QString &username, const QString &password, const QString &role, int age);
};

#endif // REGISTERWINDOW_H
