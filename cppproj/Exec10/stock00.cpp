#include "stock00.h"
#include <iostream>

void Stock::acquare(const std::string &co, long n, double pr)
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

void Stock::show()
{
    std::cout << "��������: " << company
              << "\n\t���������� �������: " << shares
              << "\n\t���� ������: $" << share_val
              << "\n\t����� ���������: $" << total_val << std::endl;
}
