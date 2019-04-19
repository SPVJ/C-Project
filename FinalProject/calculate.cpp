#include "calculate.h"
#include "ui_calculate.h"
#include "accountlink.h"
#include <iostream>
#include <QDebug>

using namespace std;
calculate::calculate(AccountLink& Transfer,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calculate)
{
    ui->setupUi(this);
    PointToAcc = &Transfer;
    setWindowTitle("Calculate Interest");
    for (int i =0; i < PointToAcc->AllAccount.size();i++){
        ui->accbox->addItem(PointToAcc->AllAccount[i]->getId());
    }
}

calculate::~calculate()
{
    delete ui;
}

void calculate::on_spinBox_valueChanged(const QString &arg1)
{
    int pos = ui->accbox->currentIndex();
    double val = PointToAcc->AllAccount[pos]->getAmount();
    for (int i=0; i < arg1.toInt() ; i++)
        val += (PointToAcc->AllAccount[pos]->bank.getInterest()/100) * val;
    ui->newamount->setNum(val);
    return;
}

void calculate::on_pushButton_clicked()
{
    close();
    return;
}

void calculate::on_updatebutton_clicked()
{
    int pos = ui->accbox->currentIndex();
    double newval = ui->newamount->text().toDouble();
    PointToAcc->AllAccount[pos]->setAmount(newval);
    double TrueAmount = newval;
    if(PointToAcc->AllAccount[pos]->bank.getName()=="Siam Commercial Bank"){
        if(TrueAmount <= 100000)
            PointToAcc->AllAccount[pos]->bank.setIr( 0.5*0.85);
        else if (TrueAmount > 100000 || TrueAmount <= 500000)
             PointToAcc->AllAccount[pos]->bank.setIr(0.75*0.85);
        else if (TrueAmount > 500000 || TrueAmount <= 10000000)
             PointToAcc->AllAccount[pos]->bank.setIr(1.5*0.85);
        else
             PointToAcc->AllAccount[pos]->bank.setIr(0.5*0.85);
    }
    else if (PointToAcc->AllAccount[pos]->bank.getName()=="Krungthep Bank"){
        if(TrueAmount <50000000)
            PointToAcc->AllAccount[pos]->bank.setIr(0.5*0.85);
        else
            PointToAcc->AllAccount[pos]->bank.setIr(0.625*0.85);
    }
    else if (PointToAcc->AllAccount[pos]->bank.getName()=="Krungthep Bank"){
        if(TrueAmount <50000000)
            PointToAcc->AllAccount[pos]->bank.setIr(0.5*0.85);
        else
            PointToAcc->AllAccount[pos]->bank.setIr(0.625*0.85);
    }
    else if (PointToAcc->AllAccount[pos]->bank.getName()=="Thanachart Bank"){
        if(TrueAmount <= 100000)
            PointToAcc->AllAccount[pos]->bank.setIr(0.8*0.85);
        else if (TrueAmount > 100000 || TrueAmount <= 10000000)
           PointToAcc->AllAccount[pos]->bank.setIr(1.5*0.85);
        else if (TrueAmount > 10000000 || TrueAmount <= 50000000)
            PointToAcc->AllAccount[pos]->bank.setIr(1.3*0.85);
        else
            PointToAcc->AllAccount[pos]->bank.setIr(0.8*0.85);
    }
    close();
    return;
}

