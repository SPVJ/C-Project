#include "savingaccount.h"

using namespace std;
SavingAccount::SavingAccount(double amount, QString ID, QString owner,QString bankname,QString imageurl,double inrate):total(amount),id(ID),name(owner),bank(bankname,imageurl,inrate){

}

