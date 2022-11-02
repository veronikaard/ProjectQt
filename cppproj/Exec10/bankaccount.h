#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include <iostream>

class BankAccount
{
    std::string name;
    std::string acctnum;
    double balance;
public:
    BankAccount(const std::string &client, const std::string &num, double bal = 0.0);
    void show(void) const;
    void deposit(double cash);
    void withdraw(double cash);
};

#endif // BANKACCOUNT_H
