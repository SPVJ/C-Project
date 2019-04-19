#ifndef EDITACC_H
#define EDITACC_H

#include <QDialog>
#include "accountlink.h"
using namespace std;
namespace Ui {
class editacc;
}

class editacc : public QDialog
{
    Q_OBJECT

public:
    explicit editacc(AccountLink& Transfer,QWidget *parent = 0);
    ~editacc();

private slots:
    void on_ConfirmButton_clicked();

private:
    Ui::editacc *ui;
    AccountLink* PointToAcc;
};

#endif // EDITACC_H
