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
        cout << "������������� ����� �� �����������.\n";
    else
        balance+=amt;
}

void AcctABC::Withdraw(double amt)
{
    balance-=amt;
}

//���������� ������ ��� ��������������
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

//������ Brass
void Brass::Withdraw(double amt)
{
    if (amt < 0)
        cout << "��������� ����� ������ ���� �������������\n";
    else if (amt <= Balance())
        AcctABC::Withdraw(amt);
    else
        cout << "��������� ����� ��������� ������� ������.\n";
}

void Brass::ViewAct() const
{
    Formatting f = SetFormat();
    cout << "Brass ������: " << Fullname() << endl;
    cout << "����� �����: " << AcctNum() << endl;
    cout << "������: $" << Balance() << endl;
    Restore(f);
}

//������ BrassPlus
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
    cout << "BrassPluss ������: " << Fullname() << endl;
    cout << "����� �����: " << AcctNum() << endl;
    cout << "������: $" << Balance() << endl;
    cout << "������������ ����: $" << maxLoan << endl;
    cout << "���� �����: $" << owesBank << endl;
    cout.precision(3);
    cout << "������� �� ����: " << 100 * rate << "%" << endl;
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
        cout << "����� �����: $" << advance << endl;
        cout << "���� �����: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else
        cout << "��������� ����� ��������� ������� ������.\n";
    Restore(f);
}




