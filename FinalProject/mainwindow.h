#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "accountlink.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void BankLogoChange();

private slots:
    void on_AddAccButton_clicked();

    void on_update_clicked();

    void on_depwitbutton_clicked();

    void on_pushButton_clicked();

    void on_Save_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    AccountLink allAcc;
};

#endif // MAINWINDOW_H
