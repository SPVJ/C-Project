
#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <string>
using namespace std;
class UserName{
public:
    UserName(string us="LUL", string pw=""){user=us;password=pw;}
    void SetPassword(string pw) {password= pw;}
    string getUser(){return user;}
    string getPassword(){return password;}
private:
    string user;
    string password;
};

#endif // LOGIN_H
