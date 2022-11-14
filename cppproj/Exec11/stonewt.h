#ifndef STONEWT_H
#define STONEWT_H


class Stonewt
{
private:
    enum {Lbs_per_stn = 14};        //фунтов на стоун
    int stone;                      //полных стоунов
    double pds_left;                //дробное число фунтов
    double pounds;                  //общий вес в фунтах
public:
    Stonewt(double lbs);            //конструктор для значения в фунтах
    Stonewt(int stn, double lbs);   //конструктор для значения в соунах и фунтах
    Stonewt();                      //конструктор по умолчанию
    ~Stonewt();                     //деструктор
    void show_lbs() const;          //отображение веса в формате фунтов
    void show_stn() const;          //отображение веса в формате стоунов
    explicit operator int() const;
    explicit operator double() const;
 };

#endif // STONEWT_H
