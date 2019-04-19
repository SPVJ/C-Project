#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include <iostream>
#include <string>
#include <QString>
#include "banktype.h"
using namespace std;


class SavingAccount{
public:
    SavingAccount(double amount=0,QString ID="unknown",QString owner="unknown",QString bankname="unknown",QString imageurl="",double inrate=0);
    double getAmount() { return total;}
    QString getId() {return id;}
    QString getName() { return name;}
    void setAmount(double NewAmount) { total = NewAmount;}
    void setName (QString NewName) {name =NewName;}
    BankType bank;
private:
    double total;
    QString id,name;


};



#endif // SAVINGACCOUNT_H
