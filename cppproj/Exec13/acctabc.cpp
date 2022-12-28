#include "acctabc.h"
using std::cout;
using std::endl;

AcctABC::AcctABC(const std::string &s, long an, double bal)
{
    fullname = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt)
{
    if (amt < 0)
        cout << "Отрицательный вклад не допускается.\n";
    else
        balance+=amt;
}

void AcctABC::Withdraw(double amt)
{
    balance-=amt;
}

//Защищенные методы для форматирования
AcctABC::Formatting AcctABC::SetFormat() const
{
    Formatting f;
    f.flag = cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(Formatting &f) const
{
    cout.setf(f.flag, std::ios_base::floatfield);
    cout.precision(f.pr);
}

//Методы Brass
void Brass::Withdraw(double amt)
{
    if (amt < 0)
        cout << "Снимаемая сумма должна быть положительной\n";
    else if (amt <= Balance())
        AcctABC::Withdraw(amt);
    else
        cout << "Снимаемая сумма превышает текущий баланс.\n";
}

void Brass::ViewAct() const
{
    Formatting f = SetFormat();
    cout << "Brass Клиент: " << Fullname() << endl;
    cout << "Номер счета: " << AcctNum() << endl;
    cout << "Баланс: $" << Balance() << endl;
    Restore(f);
}

//Методы BrassPlus
BrassPlus::BrassPlus(const std::string &s, long an,
                     double bal, double m1, double r) : AcctABC(s, an, bal)
{
    maxLoan = m1;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass &ba, double m1, double r) : AcctABC(ba)
{
    maxLoan = m1;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAct() const
{
    Formatting f = SetFormat();
    cout << "BrassPluss Клиент: " << Fullname() << endl;
    cout << "Номер счета: " << AcctNum() << endl;
    cout << "Баланс: $" << Balance() << endl;
    cout << "Максимальный заем: $" << maxLoan << endl;
    cout << "Долг банку: $" << owesBank << endl;
    cout.precision(3);
    cout << "Процент на заем: " << 100 * rate << "%" << endl;
    Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
    Formatting f = SetFormat();
    double bal = Balance();
    if (amt <= bal)
        AcctABC::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Аванс банка: $" << advance << endl;
        cout << "Долг банку: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else
        cout << "Снимаемая сумма превышает текущий баланс.\n";
    Restore(f);
}




