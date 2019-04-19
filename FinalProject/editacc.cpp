#include "editacc.h"
#include "ui_editacc.h"
#include <QString>
#include "accountlink.h"
#include <string>


editacc::editacc(AccountLink& Transfer,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editacc)
{
    PointToAcc = &Transfer;
    ui->setupUi(this);
    ui->errormsg->hide();
    for (int i =0; i < PointToAcc->AllAccount.size();i++){
        ui->box2->addItem(PointToAcc->AllAccount[i]->getId());
    }
}

editacc::~editacc()
{
    delete ui;
}
bool isdouble2(string& test){
    try{
        stod(test);
    }
    catch (invalid_argument e){
        return false;
    }
    return true;
}

void editacc::on_ConfirmButton_clicked()
{
    string Amount = ui->amounin->text().toStdString();
    double TrueAmount =0;
    //checking validity for amount input section
    if (isdouble2(Amount)){
        TrueAmount = stod(Amount);
    }
    else{
        ui->errormsg->show();
        return;
    }
    int type = ui->box1->currentIndex();
    int pos = ui->box2->currentIndex();
    if (type==1){
        if (PointToAcc->AllAccount[pos]->getAmount()<TrueAmount+500){
            ui->errormsg->show();
            return;
        }
        else{
            PointToAcc->AllAccount[pos]->setAmount(PointToAcc->AllAccount[pos]->getAmount()-TrueAmount);
            TrueAmount = PointToAcc->AllAccount[pos]->getAmount();
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
    }
    else if (type==0){
        if (TrueAmount <= 0){
            ui->errormsg->show();
            return;
        }
        else{
            PointToAcc->AllAccount[pos]->setAmount(PointToAcc->AllAccount[pos]->getAmount()+TrueAmount);
            TrueAmount = PointToAcc->AllAccount[pos]->getAmount();
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

    }
}
