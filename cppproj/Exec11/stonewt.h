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
    int state  = pouInt;                //���� ���������, ���������� � ����� ����� ���������������� ������
                                        //������, �������-� ��-� � ������ ��� � ������ � ��������� �������
public:
    enum {pouInt = 0, pouFlo, Stn};
    Stonewt(double lbs);                //����������� ��� �������� � ������
    Stonewt(int stn, double lbs);       //����������� ��� �������� � ������ � ������
    Stonewt();                          //����������� �� ���������
    ~Stonewt();                         //����������
    //void show_lbs() const;              //����������� ���� � ������� ������
    //void show_stn() const;              //����������� ���� � ������� �������

    void SetState(int stt){state = stt;}

    //������� ��������������
    //explicit operator int() const;
    //explicit operator double() const;

    //������������� �������
    Stonewt operator*(double num) const;
    Stonewt operator+(Stonewt &st) const;
    Stonewt operator-(Stonewt &st) const;

    bool operator==(Stonewt  &st) const{if (pounds == st.pounds) return true; else return false;}
    bool operator<(Stonewt  &st) const {if (pounds < st.pounds) return true; else return false;}
    bool operator>(Stonewt  &st) const {if (pounds > st.pounds) return true; else return false;}
    bool operator!=(Stonewt  &st) const{if (pounds != st.pounds) return true; else return false;}
    bool operator>=(double n) const{if (pounds >= n) return true; else return false;}
    bool operator<=(double n) const{if (pounds <= n) return true; else return false;}

    //������������� �������
    friend Stonewt operator*(double num, const Stonewt &st){return st * num;}
    //friend Stonewt operator+(const Stonewt &st1, const Stonewt &st2);
    friend std::ostream & operator<<(std::ostream &os, const Stonewt &st);
 };

#endif // STONEWT_H
