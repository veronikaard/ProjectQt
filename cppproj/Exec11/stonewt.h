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
    int state  = pouInt;                //член состояния, показывает в какой форме интерпретируются данные
                                        //стоуны, целочис-е зн-е в фунтах или в фунтах с плавающей запятой
public:
    enum {pouInt = 0, pouFlo, Stn};
    Stonewt(double lbs);                //конструктор для значения в фунтах
    Stonewt(int stn, double lbs);       //конструктор для значения в соунах и фунтах
    Stonewt();                          //конструктор по умолчанию
    ~Stonewt();                         //деструктор
    //void show_lbs() const;              //отображение веса в формате фунтов
    //void show_stn() const;              //отображение веса в формате стоунов

    void SetState(int stt){state = stt;}

    //функции преобразования
    //explicit operator int() const;
    //explicit operator double() const;

    //перегруженные функции
    Stonewt operator*(double num) const;
    Stonewt operator+(Stonewt &st) const;
    Stonewt operator-(Stonewt &st) const;

    bool operator==(Stonewt  &st) const{if (pounds == st.pounds) return true; else return false;}
    bool operator<(Stonewt  &st) const {if (pounds < st.pounds) return true; else return false;}
    bool operator>(Stonewt  &st) const {if (pounds > st.pounds) return true; else return false;}
    bool operator!=(Stonewt  &st) const{if (pounds != st.pounds) return true; else return false;}
    bool operator>=(double n) const{if (pounds >= n) return true; else return false;}
    bool operator<=(double n) const{if (pounds <= n) return true; else return false;}

    //дружественные функции
    friend Stonewt operator*(double num, const Stonewt &st){return st * num;}
    //friend Stonewt operator+(const Stonewt &st1, const Stonewt &st2);
    friend std::ostream & operator<<(std::ostream &os, const Stonewt &st);
 };

#endif // STONEWT_H
