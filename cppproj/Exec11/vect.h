#ifndef VECT_H
#define VECT_H
#include <iostream>
#include <cmath>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
    class Vector
    {
    public:
        enum Mode {RECT, POL};
    private:
        double x;               //�������������� ��������
        double y;               //������������ ��������
        //double mag;             //����� �������
        //double ang;             //����������� ������� � ��������
        Mode mode;              //RECT ��� POL

        /*�������� ������ ��� ��������� ��������*/
        //void set_mag();
        //void set_ang();
        void set_x(double mod, double ang);
        void set_y(double mod, double ang);
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const {return x;}         //�������� �������� �
        double yval() const {return y;}         //�������� �������� �
        double magval() const //�������� ������
        {
             return sqrt(x*x + y*y);
        }
        double angval() const
        {
            if (x == 0.0 && y == 0.0)
                    return 0.0;
                else
                    return atan2(y, x);
        }     //�������� ����
        void polar_mode();                      //������������� ����� POL
        void rect_mode();                       //������������� ����� RECT

        //���������� ��������
        Vector operator+(const Vector &b) const;
        Vector operator-(const Vector &b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        //������
        friend Vector operator*(double n, const Vector &a);
        friend std::ostream & operator<<(std::ostream &os, const Vector &v);

        //������� ��������������
        operator double() const;
    };
}
#endif // VECT_H
