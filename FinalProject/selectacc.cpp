#include "selectacc.h"
#include "accountlink.h"
#include <string>
#include <QString>
#include "ui_selectacc.h"
using namespace std;
SelectAcc::SelectAcc(AccountLink& AccTransfer,QComboBox* tranbox,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectAcc)
{
    ui->setupUi(this);
    PointToAcc = &AccTransfer;
    combobox = tranbox;
    ui->ErrorMsg->hide();
    ui->ErrorMsg->setStyleSheet("color : red");

}

SelectAcc::~SelectAcc()
{
    delete ui;
}

bool isdouble(string& test){
    try{
        stod(test);
    }
    catch (invalid_argument e){
        return false;
    }
    return true;
}


void SelectAcc::on_confirmAdd_clicked()
{
    string Amount = ui->AmountInput->text().toStdString();
    double TrueAmount =0;
    string accountno = ui->AccountNoInput->text().toStdString();
    if (!isdouble(accountno)|| accountno.size() != 10){
       ui->ErrorMsg->setText("Error : Invalid Accout No.");
       ui->ErrorMsg->show();
       return;
    }

    //checking validity for amount input section
    if (isdouble(Amount)){
        TrueAmount = stod(Amount);
    }
    else{
        ui->ErrorMsg->setText("Error : Invalid Amount Input");
        ui->ErrorMsg->show();
        return;
    }
    if (TrueAmount < 500 || TrueAmount > 1000000000){
        ui->ErrorMsg->setText("Amount Value must be >500 and <1B");
        ui->ErrorMsg->show();
        return;
    }

    string owner = ui->OwnerInput->text().toStdString();

    if (isdouble(owner)){
        ui->ErrorMsg->setText("Error : Invalid Name Input");
        ui->ErrorMsg->show();
        return;
    }



    QString TrueAccNo = QString::fromStdString(accountno);

    QString TrueOwner = QString::fromStdString(owner);

    QString truebank;
    QString img;
    double trueir;

    if(ui->SelectBankCombo->currentIndex()==0){
    truebank = "Krungthep Bank";
    img = "background-image:url(://img//krungthepbank.jpg)";
    if (TrueAmount <= 50000000)
        trueir = 0.5*0.85;
    else
        trueir = 0.625*0.85;
    PointToAcc->AllAccount.push_back(new SavingAccount(TrueAmount,TrueAccNo,TrueOwner,truebank,img,trueir));
    combobox->addItem(TrueAccNo);
    close();
    return;

}
    if (ui->SelectBankCombo->currentIndex()==1){
     truebank = "Krungsri Bank";
     img = "background-image:url(://img//krungsri.jpg)";
     trueir = 0.3*0.85;
     PointToAcc->AllAccount.push_back(new SavingAccount(TrueAmount,TrueAccNo,TrueOwner,truebank,img,trueir));
     combobox->addItem(TrueAccNo);
     close();
     return;
    }

    if (ui->SelectBankCombo->currentIndex()==2){
        truebank = "Krungthai Bank";
        img = "background-image:url(://img//KrungThai.jpg)";
        trueir = 0.5*0.85;
        PointToAcc->AllAccount.push_back(new SavingAccount(TrueAmount,TrueAccNo,TrueOwner,truebank,img,trueir));
        combobox->addItem(TrueAccNo);
        close();
    return;
    }

    if (ui->SelectBankCombo->currentIndex()==3){
        truebank = "Siam Commercial Bank";
        img = "background-image:url(://img//scb.jpeg)";
        if(TrueAmount <= 100000)
            trueir = 0.5*0.85;
        else if (TrueAmount > 100000 || TrueAmount <= 500000)
            trueir = 0.75*0.85;
        else if (TrueAmount > 500000 || TrueAmount <= 10000000)
            trueir = 1.5*0.85;
        else
            trueir = 0.5*0.85;
        PointToAcc->AllAccount.push_back(new SavingAccount(TrueAmount,TrueAccNo,TrueOwner,truebank,img,trueir));
        combobox->addItem(TrueAccNo);
        close();
        return;
    }

    if (ui->SelectBankCombo->currentIndex()==4){
        truebank = "Government Saving Bank";
        img = "background-image:url(://img//govsavbank.jpg)";
        trueir = 0.6*0.85;
        PointToAcc->AllAccount.push_back(new SavingAccount(TrueAmount,TrueAccNo,TrueOwner,truebank,img,trueir));
        combobox->addItem(TrueAccNo);
        close();
        return;

    }

    if (ui->SelectBankCombo->currentIndex()==5){
        truebank = "Thanachart Bank";
        img = "background-image:url(://img//Thanachart.jpg)";
        if(TrueAmount <= 100000)
            trueir = 0.8*0.85;
        else if (TrueAmount > 100000 || TrueAmount <= 10000000)
            trueir = 1.5*0.85;
        else if (TrueAmount > 10000000 || TrueAmount <= 50000000)
            trueir = 1.3*0.85;
        else
            trueir = 0.8*0.85;
        PointToAcc->AllAccount.push_back(new SavingAccount(TrueAmount,TrueAccNo,TrueOwner,truebank,img,trueir));
        combobox->addItem(TrueAccNo);
        close();
        return;
    }

    if (ui->SelectBankCombo->currentIndex()==6){
        truebank = "TMB Bank";
        img = "background-image:url(://img//tmb.png)";
        trueir = 1.6*0.85;
        PointToAcc->AllAccount.push_back(new SavingAccount(TrueAmount,TrueAccNo,TrueOwner,truebank,img,trueir));
        combobox->addItem(TrueAccNo);
        close();
        return;
    }


    if (ui->SelectBankCombo->currentIndex()==7){
        truebank = "Kasikorn Bank";
        img ="background-image:url(://img//kks.png)";
        trueir = 0.5*0.85;
        PointToAcc->AllAccount.push_back(new SavingAccount(TrueAmount,TrueAccNo,TrueOwner,truebank,img,trueir));
        combobox->addItem(TrueAccNo);
        close();
        return;
    }


    close();
}
