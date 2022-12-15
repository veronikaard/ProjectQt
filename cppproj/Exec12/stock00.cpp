#include "stock00.h"
#include <iostream>

using std::strlen;
using std::strcpy;

Stock::Stock(const char *co, long n, double pr)
{
    //company = co;
    company = new char [strlen(co) + 1];
    strcpy(company, co);

    if (n < 0)
    {
        std::cout << "���������� ������� �� ����� ���� ������������� " << company
                  << "��������������� � 0." << std::endl;
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

Stock::Stock()
{
    //company = "no name";
    company = new char[1];
    shares = 0;
    share_val = 0;
    total_val = 0;
}

/*void Stock::acquare(const std::string &co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        std::cout << "���������� ������� �� ����� ���� ������������� " << company
                  << "��������������� � 0." << std::endl;
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}*/

const Stock& Stock::topval(const Stock &s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "���������� ������������� ������� �� ����� ���� "
                     "�������������. ���������� ��������.\n";
    }
    else
    {
        shares +=num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "���������� ����������� ������� �� ����� ���� �������������"
                ". ���������� ��������.\n";
    }
    else if (num > shares)
    {
        cout << "������ ��������� ������, ��� ��������� �� ��������."
                " ���������� ��������.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

/*void Stock::show() const
{
    std::cout << "��������: " << company
              << "\n\t���������� �������: " << shares
              << "\n\t���� ������: $" << share_val
              << "\n\t����� ���������: $" << total_val << std::endl;
}*/

std::ostream & operator<<(std::ostream &os, const Stock &st)
{
    os << "��������: " << st.company
              << "\n\t���������� �������: " << st.shares
              << "\n\t���� ������: $" << st.share_val
              << "\n\t����� ���������: $" << st.total_val << std::endl;
}

Stock::~Stock()
{
    delete [] company;
    //std::cout << "Buy, " << company << "!\n";
}
