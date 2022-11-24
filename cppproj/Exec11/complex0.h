#ifndef COMPLEX0_H
#define COMPLEX0_H
#include <iostream>

class Complex
{
    double real;            //�������������� �����
    double imaginary;       //������ �����
public:
    Complex(double rl, double imgnr);
    Complex();

    //������������� �������
    Complex operator~() const;
    Complex operator+(Complex &cmpx) const;
    Complex operator-(Complex &cmpx) const;
    Complex operator*(Complex &cmpx) const;
    Complex operator*(double n) const;

    //�������������� �������
    friend std::ostream & operator<<(std::ostream &os, const Complex &cm);
    friend std::istream & operator>>(std::istream &is, Complex &cm);
    friend Complex operator*(double n, const Complex &cmpx){return cmpx * n;}
};

#endif // COMPLEX0_H
