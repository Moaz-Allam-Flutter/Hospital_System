// adminwindow.h
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

private:
    Ui::AdminWindow *ui;

    void loadUserList();
};

#endif // ADMINWINDOW_H
