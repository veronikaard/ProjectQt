#ifndef STOCK00_H
#define STOCK00_H
#include <string>

class Stock //���������� ������
{
public:
    Stock();    //����������� �� ���������
    Stock(const std::string &co, long n, double pr);    //����������� �����

    ~Stock();   //����������
private:
    std::string company;    //�������� ��������
    long shares;            //���������� �������
    double share_val;       //���� ������
    double total_val;       //����� ���� �����
    void set_tot(){total_val = shares * share_val;}
public:
   // void acquare(const std::string &co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const; //const ���� ��������, ��� �� ����� ������ ������
};

#endif // STOCK00_H
