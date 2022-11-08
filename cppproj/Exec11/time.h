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
    Time Sum(const Time &t) const;
    void Show() const;
};

#endif // TIME_H
