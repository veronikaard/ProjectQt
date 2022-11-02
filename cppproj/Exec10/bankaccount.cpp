#include "bankaccount.h"

BankAccount::BankAccount(const std::string &client, const std::string &num, double bal)
{
    name = client;
    acctnum = num;
    balance = bal;
}

void BankAccount::show() const
{
    using std::cout;
    using std::endl;
    cout << "������: " << name << endl;
    cout << "\t����� �����: " << acctnum << ", ������: " << balance << endl;
}

void BankAccount::deposit(double cash)
{
    balance += cash;
}

void BankAccount::withdraw(double cash)
{
    balance -= cash;
}
