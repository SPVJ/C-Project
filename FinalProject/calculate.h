#ifndef CALCULATE_H
#define CALCULATE_H

#include <QDialog>
#include "accountlink.h"

namespace Ui {
class calculate;
}
using namespace std;
class calculate : public QDialog
{
    Q_OBJECT

public:
    explicit calculate(AccountLink& Transfer,QWidget *parent = 0);
    ~calculate();

private slots:
    void on_spinBox_valueChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_updatebutton_clicked();

private:
    AccountLink* PointToAcc;
    Ui::calculate *ui;
};

#endif // CALCULATE_H
