#ifndef STOCK00_H
#define STOCK00_H
#include <string>

class Stock //Объявление класса
{
private:
    std::string company;    //название компании
    long shares;            //количество пакетов
    double share_val;       //цена пакета
    double total_val;       //общая цена акций
    void set_tot(){total_val = shares * share_val;}
public:
    void acquare(const std::string &co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

#endif // STOCK00_H
