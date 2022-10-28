#ifndef STOCK00_H
#define STOCK00_H
#include <string>

class Stock //ќбъ€вление класса
{
public:
    Stock();    //конструктор по умолчанию
    Stock(const std::string &co, long n, double pr);    //конструктор €вный

    ~Stock();   //ƒеструктор
private:
    std::string company;    //название компании
    long shares;            //количество пакетов
    double share_val;       //цена пакета
    double total_val;       //обща€ цена акций
    void set_tot(){total_val = shares * share_val;}
public:
   // void acquare(const std::string &co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const; //const дает гарантию, что не будет мен€ть данные
};

#endif // STOCK00_H
