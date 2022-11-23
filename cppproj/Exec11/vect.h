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
        double x;               //горизонтальное значение
        double y;               //вертикальное значение
        //double mag;             //длина вектора
        //double ang;             //направление вектора в градусах
        Mode mode;              //RECT или POL

        /*Закрытые методы для установки значений*/
        //void set_mag();
        //void set_ang();
        void set_x(double mod, double ang);
        void set_y(double mod, double ang);
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const {return x;}         //сообщает значение х
        double yval() const {return y;}         //сообщает значение у
        double magval() const //сообщает модуль
        {
             return sqrt(x*x + y*y);
        }
        double angval() const
        {
            if (x == 0.0 && y == 0.0)
                    return 0.0;
                else
                    return atan2(y, x);
        }     //сообщает угол
        void polar_mode();                      //устанавливает режим POL
        void rect_mode();                       //устанавливает режим RECT

        //Перегрузка операций
        Vector operator+(const Vector &b) const;
        Vector operator-(const Vector &b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        //Друзья
        friend Vector operator*(double n, const Vector &a);
        friend std::ostream & operator<<(std::ostream &os, const Vector &v);

        //Функции преобразования
        operator double() const;
    };
}
#endif // VECT_H
