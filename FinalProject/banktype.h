#ifndef BANKTYPE_H
#define BANKTYPE_H


#include <QString>
#include <string>
#include <iostream>
using namespace std;
class BankType{
public:
    BankType(QString bname,QString imagelocate,double inrate);
    QString getName(){return name;}
    QString getImage(){return image;}
    double getInterest(){return ir;}
    void setIr(double newir){ir=newir;}
private:
    QString name,image;
    double ir;
};

#endif // BANKTYPE_H
