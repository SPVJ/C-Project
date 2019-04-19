#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <fstream>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <string>
#include <sstream>
#include "selectacc.h"
#include "savingaccount.h"
#include "accountlink.h"
#include "editacc.h"
#include "calculate.h"
#include <vector>


using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Saving Account Calculator");
    if (allAcc.AllAccount.empty()){
        ui->showAccountNO->setText("Unkown");
        ui->showAmount->setText("Unknown");
        ui->BankName->setText("Unknown");
        ui->ShowIR->setText("Unknow");
        ui->showowner->setText("Unknown");

    }
    setStyleSheet("background-image :url(://img//mainbg.png)");
    ui->updateerror->hide();
    ui->deperror->hide();
    ui->saveloaderror->hide();

    //ui->updateerror->setStyleSheet("background-color: rgba(0,0,0)");
    //ui->showAccountNO->setStyleSheet("background-color: rgba(0,0,0)");
    //ui->showAmount->setStyleSheet("background-color: rgba(0,0,0)");
    //ui->showowner->setStyleSheet("background-color: rgba(0,0,0)");
   // ui->ShowIR->setStyleSheet("background-color: rgba(0,0,0)");
    //ui->selectpls->setStyleSheet("background-color: rgba(0,0,0)");
   // ui->BankName->setStyleSheet("background-color: rgba(0,0,0)");
    //ui->BankLogoImg->setStyleSheet("background-color: rgba(0,0,0)");
    //ui->selectpls->setStyleSheet("background-color: rgba(0,0,0)");

}

MainWindow::~MainWindow()
{
    delete ui;
    for (int i =0;i < allAcc.AllAccount.size();i++){
        delete allAcc.AllAccount[i];
    }
}



void MainWindow::on_AddAccButton_clicked()
{
    SelectAcc test(allAcc,ui->accnoinput);
    test.setWindowTitle("Add New Account");
    test.setModal(true);
    test.exec();
}
void MainWindow::on_update_clicked()
{

    int pos;
    int i=0;
    if (allAcc.AllAccount.size()==0){
        ui->updateerror->show();
         return;
    }

     pos = ui->accnoinput->currentIndex();
     ui->showAccountNO->setText(allAcc.AllAccount[pos]->getId());
     ui->showAmount->setText(QString::number(allAcc.AllAccount[i]->getAmount(),'f',2));
     ui->showowner->setText(allAcc.AllAccount[pos]->getName());
     ui->ShowIR->setText(QString::number(allAcc.AllAccount[i]->bank.getInterest(),'f',2)+" %");
     ui->BankName->setText(allAcc.AllAccount[pos]->bank.getName());
     ui->BankLogoImg->setStyleSheet(allAcc.AllAccount[pos]->bank.getImage());

     ui->updateerror->hide();
     return;



}

void MainWindow::on_depwitbutton_clicked()
{
    if (allAcc.AllAccount.size()==0){
         ui->deperror->show();
         return;
    }
    ui->deperror->hide();
    editacc edit(allAcc);
    edit.setWindowTitle("Deposit / Withdraw");
    edit.setModal(true);
    edit.exec();
}

void MainWindow::on_pushButton_clicked()
{
    if (allAcc.AllAccount.size()==0){
         ui->deperror->show();
         return;
    }
    calculate cal(allAcc);
    cal.setModal(true);
    cal.exec();
}



void MainWindow::on_Save_clicked()
{
    if (allAcc.AllAccount.size()==0){
        return;
    }
    QFile file("C:\\Users\\KeppaKleb\\Desktop\\Files\\coding1\\c++project\\FinalProject\\data.txt");
    if (!file.exists()){
        ui->saveloaderror->show();
        return;
    }
    file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream txtstream(&file);
        string fullbank ;
        QString outbank;
        for (int i =0; i< allAcc.AllAccount.size();i++){
            outbank = allAcc.AllAccount[i]->bank.getName();
            fullbank = outbank.toStdString();
            fullbank.erase(remove(fullbank.begin(),fullbank.end(),' '),fullbank.end());
            outbank = QString::fromStdString(fullbank);

            txtstream << allAcc.AllAccount[i]->getAmount() <<" "
                      << allAcc.AllAccount[i]->getId() <<" "
                      << allAcc.AllAccount[i]->getName() <<" "
                      << allAcc.AllAccount[i]->bank.getImage()<<" "
                      << allAcc.AllAccount[i]->bank.getInterest()<<" "
                      << outbank ;


            if(i !=allAcc.AllAccount.size()-1){
                txtstream <<endl;
            }
        }
        file.close();

}

void MainWindow::on_pushButton_2_clicked()
{
   QFile file("://img/data.txt");
   if (!file.exists()){
        ui->saveloaderror->show();
        return;
    }
    file.open(QIODevice::ReadOnly | QIODevice::Text);
        string add;
        QTextStream qstream(&file);
        QString line;
        string nline;
        istringstream stream(nline);
        QStringList alladd;
        while(!qstream.atEnd()){
           line = qstream.readLine();
            alladd = line.split(" ");
            if(alladd[5]=="KrungthepBank")
                alladd[5] = "Krungthep Bank";
            else if(alladd[5]=="KrungsriBank")
                alladd[5] = "Krungsri Bank";
            else if(alladd[5]=="KrungthaiBank")
                alladd[5] = "Krungthai Bank";
            else if(alladd[5]=="SiamCommercialBank")
                alladd[5] = "Siam Commercial Bank";
            else if(alladd[5]=="GovermentSavingBank")
                alladd[5] = "Goverment Saving Bank";
            else if(alladd[5]=="ThanachartBank")
                alladd[5] = "Thanachart Bank";
            else if(alladd[5]=="TMBBank")
                alladd[5] = "TMB Bank";
            else if(alladd[5]=="KasikornBank")
                alladd[5] = "Kasikorn Bank";
            allAcc.AllAccount.push_back(new SavingAccount(alladd[0].toDouble(),alladd[1],alladd[2],alladd[5],alladd[3],alladd[4].toDouble()));
        }
        file.close();
        if(allAcc.AllAccount.size()!=0){
            for(int j=0;j<allAcc.AllAccount.size();j++){
                ui->accnoinput->addItem(allAcc.AllAccount[j]->getId());
        }
  }
}
