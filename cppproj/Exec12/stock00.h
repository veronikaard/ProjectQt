#ifndef STOCK00_H
#define STOCK00_H
#include <cstring>
#include <stdlib.h>
#include <iostream>

class Stock //ќбъ€вление класса
{
private:
    //std::string company;    //название компании
    char *company;         //название компании
    long shares;            //количество пакетов
    double share_val;       //цена пакета
    double total_val;       //обща€ цена акций
    void set_tot(){total_val = shares * share_val;}
public:
    Stock();    //конструктор по умолчанию
    //Stock(const std::string &co, long n = 0, double pr = 0.0);    //конструктор €вный
    Stock(const  char *co, long n = 0, double pr = 0.0);    //конструктор €вный
    ~Stock();   //ƒеструктор
   // void acquare(const std::string &co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    //void show() const; //const дает гарантию, что не будет мен€ть данные
    const Stock & topval(const Stock &s) const;

    friend std::ostream & operator<<(std::ostream &os, const Stock &st);
};

#endif // STOCK00_H
