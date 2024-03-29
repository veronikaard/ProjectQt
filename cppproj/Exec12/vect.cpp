#include "vect.h"


namespace VECTOR {

    //��������� ���������� �������� � ����� �������
    const double Rad_to_deg = 45.0 / atan(1.0);

    Vector::Vector()
    {
        x = y = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            //set_mag();
            //set_ang();
        }
        else if (form == POL)
        {
            //mag = n1;
            //ang = n2 / Rad_to_deg;
            set_x(n1, n2);
            set_y(n1, n2);
        }
        else
        {
            cout << "������������ ������ ��������, ������ ��������������� � 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            magval();
            angval();
            //set_mag();
            //set_ang();
        }
        else if (form == POL)
        {
            //mag = n1;
            //ang = n2 / Rad_to_deg;
            set_x(n1, n2);
            set_y(n1, n2);
        }
        else
        {
            cout << "������������ ������ ��������, ������ ��������������� � 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    void Vector::polar_mode()
    {
        mode = POL;
    }

    void Vector::rect_mode()
    {
        mode = RECT;
    }

    Vector Vector::operator+(const Vector &b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector &b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n*x, n*y);
    }

    Vector operator*(double n, const Vector &a)
    {
        return a * n;
    }

    std::ostream & operator<<(std::ostream &os, const Vector &v)
    {
        if (v.mode == Vector::RECT)
            os << "(x,y) = (" << v.x << ", " << v.y << ")\n";
        else if (v.mode == Vector::POL)
            os << "(m,a) = (" << v.magval() << ", " << v.angval() * Rad_to_deg << ")\n";
        else
            os << "������������ ����� ������� Vector\n";
        return os;
    }

    /*void Vector::set_mag()
    {
        mag = sqrt(x*x + y*y);
    }*/

    /*void Vector::set_ang()
    {
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }*/

    void Vector::set_x(double mod, double ang)
    {
        x = mod * cos(ang/Rad_to_deg);
    }

    void Vector::set_y(double mod, double ang)
    {
        y = mod * sin(ang/Rad_to_deg);
    }

    Vector::operator double() const
    {
        return magval();
    }

    Vector::~Vector()
    {

    }
}
