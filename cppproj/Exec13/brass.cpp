#include "brass.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

//Для целей форматирования
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(const std::string &s, long an, double bal) : fullname(s), acctNum(an), balance(bal)
{
}

void Brass::Deposit(double amt)
{
    if (amt < 0)
        cout << "Отрицательный вклад не допускается.\n";
    else
        balance+=amt;
}

void Brass::Withdraw(double amt)
{
    //Установка формата ###.##
    format initialState = setFormat();
    precis prec = cout.precision(2);
    if (amt < 0)
        cout << "Снимаемая сумма должна быть положительной.\n";
    else if (amt <= balance)
        balance -= amt;
    else
        cout << "Снимаемая сумма превышает текущий баланс.\n";
    restore(initialState, prec);
}

double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Клиент: " << fullname << endl;
    cout << "Номер счета: " << acctNum << endl;
    cout << "Баланс: $" << balance << endl;
    restore(initialState, prec);                    //Восстановление исходного формата
}

//Методы BrassPlus
BrassPlus::BrassPlus(const std::string &s, long an, double bal, double m1, double r)
    :Brass(s, an, bal), maxLoan(m1), rate(r), owesBank(0.0)
{}

BrassPlus::BrassPlus(const Brass &ba, double m1, double r)
    : Brass(ba), maxLoan(m1), rate(r), owesBank(0.0)
{}

//Переопределение реализации метода Withdraw(double amt)
void BrassPlus::Withdraw(double amt)
{
    //Установка формата ###.##
    format initialState = setFormat();
    precis prec = cout.precision(2);
    double bal = Balance();
    if (amt < 0)
        Brass::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Аванс банка: $" << advance << endl;
        cout << "Долг банку: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else
        cout << "Снимаемая сумма превышает текущий баланс.\n";
    restore(initialState, prec);
}

//Переопределение реализации метода ViewAcct()
void BrassPlus::ViewAcct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);
    Brass::ViewAcct();                      //Отоображение базовой части
    cout << "Максимальный заем: $" << maxLoan << endl;
    cout << "Долг банку: $" << owesBank << endl;
    cout.precision(3);
    cout << "Процент на заем: " << 100 * rate << "%" << endl;
    restore(initialState, prec);
}

format setFormat()
{
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}









