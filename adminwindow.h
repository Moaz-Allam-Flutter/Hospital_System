#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>

namespace Ui {
class adminWindow;
}

class adminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminWindow(QWidget *parent = nullptr);
    ~adminWindow();

private:
    Ui::adminWindow *ui;
};

#endif // ADMINWINDOW_H
