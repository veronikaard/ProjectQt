#ifndef COMPLEX0_H
#define COMPLEX0_H
#include <iostream>

class Complex
{
    double real;            //Действительная часть
    double imaginary;       //Мнимая часть
public:
    Complex(double rl, double imgnr);
    Complex();

    //Перегруженные функции
    Complex operator~() const;
    Complex operator+(Complex &cmpx) const;
    Complex operator-(Complex &cmpx) const;
    Complex operator*(Complex &cmpx) const;
    Complex operator*(double n) const;

    //Дружесственные функции
    friend std::ostream & operator<<(std::ostream &os, const Complex &cm);
    friend std::istream & operator>>(std::istream &is, Complex &cm);
    friend Complex operator*(double n, const Complex &cmpx){return cmpx * n;}
};

#endif // COMPLEX0_H
