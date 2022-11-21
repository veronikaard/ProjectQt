#ifndef STONEWT_H
#define STONEWT_H
#include <iostream>

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};            //фунтов на стоун
    int stone;                          //полных стоунов
    double pds_left;                    //дробное число фунтов
    double pounds;                      //общий вес в фунтах
public:
    Stonewt(double lbs);                //конструктор для значения в фунтах
    Stonewt(int stn, double lbs);       //конструктор для значения в соунах и фунтах
    Stonewt();                          //конструктор по умолчанию
    ~Stonewt();                         //деструктор
    void show_lbs() const;              //отображение веса в формате фунтов
    void show_stn() const;              //отображение веса в формате стоунов
    //explicit operator int() const;      //функции преобразования
    //explicit operator double() const;
    Stonewt operator*(double num) const;
    friend Stonewt operator*(double num, const Stonewt &st){return st * num;}
    friend Stonewt operator+(const Stonewt &st1, const Stonewt &st2);
 };

#endif // STONEWT_H
