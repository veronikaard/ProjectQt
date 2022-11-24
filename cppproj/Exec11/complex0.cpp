#include "complex0.h"

Complex::Complex(double rl, double imgnr)
{
    real = rl;
    imaginary = imgnr;
}

Complex::Complex()
{
    real = imaginary = 0;
}

Complex Complex::operator~() const
{
    Complex complex;
    complex.real = real;
    complex.imaginary = -1 * imaginary;
    return complex;
}

Complex Complex::operator+(Complex &cmpx) const
{
    Complex complex;
    complex.real = real + cmpx.real;
    complex.imaginary = imaginary + cmpx.imaginary;
    return complex;
}

Complex Complex::operator-(Complex &cmpx) const
{
    Complex complex;
    complex.real = real - cmpx.real;
    complex.imaginary = imaginary - cmpx.imaginary;
    return complex;
}

Complex Complex::operator*(Complex &cmpx) const
{
    Complex complex;
    complex.real = real * cmpx.real - imaginary * cmpx.imaginary;
    complex.imaginary = real * cmpx.imaginary + imaginary * cmpx.real;
    return complex;
}

Complex Complex::operator*(double n) const
{
    Complex complex;
    complex.real = real * n;
    complex.imaginary = imaginary * n;
    return complex;
}

std::ostream & operator<<(std::ostream &os, const Complex &cm)
{
    os << "(" << cm.real << ", " << cm.imaginary << "i)";
    return os;
}

std::istream & operator>>(std::istream &is, Complex &cm)
{
    using std::cout;
    cout << "real: ";
    is >> cm.real;
    cout << "imaginary: ";
    is >> cm.imaginary;
    return is;
}
