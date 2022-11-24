#ifndef TIME_H
#define TIME_H
#include <iostream>

class Time
{
    int hours;
    int minutes;

public:
    Time();
    Time(int h, int m = 0);

    void AddMin(int min);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);    
    void Show() const;

    //������������� �������
    //Time operator+(const Time &t) const;
    //Time operator-(const Time &t) const;
    //Time operator*(double n) const;

    //������������� �������
    friend Time operator+(const Time &t1, const Time &t2);
    friend Time operator-(const Time &t1, const Time &t2);
    friend Time operator*(const Time &t, double n);
    friend Time operator*(double n, const Time &t){return t * n;}
    friend std::ostream & operator<<(std::ostream &os, const Time &t);
};

#endif // TIME_H
