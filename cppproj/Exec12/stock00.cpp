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
        std::cout << "Количество пакетов не может быть отрицательным " << company
                  << "устанавливается в 0." << std::endl;
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
        std::cout << "Количество пакетов не может быть отрицательным " << company
                  << "устанавливается в 0." << std::endl;
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
        std::cout << "Количество приобретенных пакетов не может быть "
                     "отрицательным. Транзакция прервана.\n";
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
        cout << "Количество продаваемых пакетов не может быть отрицательным"
                ". Транзакция прервана.\n";
    }
    else if (num > shares)
    {
        cout << "Нельзя продавать больше, чем находится во владении."
                " Транзакция прервана.\n";
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
    std::cout << "Компания: " << company
              << "\n\tКоличество пакетов: " << shares
              << "\n\tЦена пакета: $" << share_val
              << "\n\tОбщая стоимость: $" << total_val << std::endl;
}*/

std::ostream & operator<<(std::ostream &os, const Stock &st)
{
    os << "Компания: " << st.company
              << "\n\tКоличество пакетов: " << st.shares
              << "\n\tЦена пакета: $" << st.share_val
              << "\n\tОбщая стоимость: $" << st.total_val << std::endl;
}

Stock::~Stock()
{
    delete [] company;
    //std::cout << "Buy, " << company << "!\n";
}
