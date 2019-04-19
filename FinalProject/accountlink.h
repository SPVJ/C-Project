#ifndef ACCOUNTLINK_H
#define ACCOUNTLINK_H

#include "savingaccount.h"
#include <vector>
using namespace std;
class AccountLink{
public:
    AccountLink(){AllAccount.clear();}
    vector<SavingAccount*> AllAccount;
};



#endif // ACCOUNTLINK_H
