#ifndef STOCK00_H
#define STOCK00_H
#include <cstring>
#include <stdlib.h>
#include <iostream>

class Stock //���������� ������
{
private:
    //std::string company;    //�������� ��������
    char *company;         //�������� ��������
    long shares;            //���������� �������
    double share_val;       //���� ������
    double total_val;       //����� ���� �����
    void set_tot(){total_val = shares * share_val;}
public:
    Stock();    //����������� �� ���������
    //Stock(const std::string &co, long n = 0, double pr = 0.0);    //����������� �����
    Stock(const  char *co, long n = 0, double pr = 0.0);    //����������� �����
    ~Stock();   //����������
   // void acquare(const std::string &co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    //void show() const; //const ���� ��������, ��� �� ����� ������ ������
    const Stock & topval(const Stock &s) const;

    friend std::ostream & operator<<(std::ostream &os, const Stock &st);
};

#endif // STOCK00_H
