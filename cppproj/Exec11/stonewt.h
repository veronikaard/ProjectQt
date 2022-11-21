#ifndef STONEWT_H
#define STONEWT_H
#include <iostream>

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};            //������ �� �����
    int stone;                          //������ �������
    double pds_left;                    //������� ����� ������
    double pounds;                      //����� ��� � ������
public:
    Stonewt(double lbs);                //����������� ��� �������� � ������
    Stonewt(int stn, double lbs);       //����������� ��� �������� � ������ � ������
    Stonewt();                          //����������� �� ���������
    ~Stonewt();                         //����������
    void show_lbs() const;              //����������� ���� � ������� ������
    void show_stn() const;              //����������� ���� � ������� �������
    //explicit operator int() const;      //������� ��������������
    //explicit operator double() const;
    Stonewt operator*(double num) const;
    friend Stonewt operator*(double num, const Stonewt &st){return st * num;}
    friend Stonewt operator+(const Stonewt &st1, const Stonewt &st2);
 };

#endif // STONEWT_H
