#include "brass.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

//��� ����� ��������������
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
        cout << "������������� ����� �� �����������.\n";
    else
        balance+=amt;
}

void Brass::Withdraw(double amt)
{
    //��������� ������� ###.##
    format initialState = setFormat();
    precis prec = cout.precision(2);
    if (amt < 0)
        cout << "��������� ����� ������ ���� �������������.\n";
    else if (amt <= balance)
        balance -= amt;
    else
        cout << "��������� ����� ��������� ������� ������.\n";
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
    cout << "������: " << fullname << endl;
    cout << "����� �����: " << acctNum << endl;
    cout << "������: $" << balance << endl;
    restore(initialState, prec);                    //�������������� ��������� �������
}

//������ BrassPlus
BrassPlus::BrassPlus(const std::string &s, long an, double bal, double m1, double r)
    :Brass(s, an, bal), maxLoan(m1), rate(r), owesBank(0.0)
{}

BrassPlus::BrassPlus(const Brass &ba, double m1, double r)
    : Brass(ba), maxLoan(m1), rate(r), owesBank(0.0)
{}

//��������������� ���������� ������ Withdraw(double amt)
void BrassPlus::Withdraw(double amt)
{
    //��������� ������� ###.##
    format initialState = setFormat();
    precis prec = cout.precision(2);
    double bal = Balance();
    if (amt < 0)
        Brass::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "����� �����: $" << advance << endl;
        cout << "���� �����: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else
        cout << "��������� ����� ��������� ������� ������.\n";
    restore(initialState, prec);
}

//��������������� ���������� ������ ViewAcct()
void BrassPlus::ViewAcct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);
    Brass::ViewAcct();                      //������������ ������� �����
    cout << "������������ ����: $" << maxLoan << endl;
    cout << "���� �����: $" << owesBank << endl;
    cout.precision(3);
    cout << "������� �� ����: " << 100 * rate << "%" << endl;
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









