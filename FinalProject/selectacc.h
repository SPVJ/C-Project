#ifndef SELECTACC_H
#define SELECTACC_H

#include <QDialog>
#include <QComboBox>
#include "accountlink.h"

namespace Ui {
class SelectAcc;
}

class SelectAcc : public QDialog
{
    Q_OBJECT

public:
    explicit SelectAcc(AccountLink& AccTransfer,QComboBox* tranbox,QWidget *parent = 0);
    ~SelectAcc();

private slots:


    void on_confirmAdd_clicked();

private:
    Ui::SelectAcc *ui;
    QComboBox* combobox;
    AccountLink* PointToAcc;
};

#endif // SELECTACC_H
