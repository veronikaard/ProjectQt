#include "time.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int min)
{
    minutes += min;
    hours += minutes /60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

/*Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes/60;
    sum.minutes %= 60;
    return sum;
}*/

Time operator+(const Time &t1, const Time &t2)
{
    Time sum;
    sum.minutes = t1.minutes + t2.minutes;
    sum.hours = t1.hours + t2.hours + sum.minutes/60;
    sum.minutes %= 60;
    return sum;
}

/*Time Time::operator-(const Time &t) const
{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 *  t.hours;
    tot2 = minutes + 60 * hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}*/

Time operator-(const Time &t1, const Time &t2)
{
    Time diff;
    int tot1, tot2;
    tot1 = t1.minutes + 60 * t1.hours;
    tot2 = t2.minutes + 60 * t2.hours;
    diff.minutes = (tot1 - tot2) % 60;
    diff.hours = (tot1 - tot2) / 60;
    return diff;
}

/*Time Time::operator *(double n) const
{
    Time result;
    long totalminutes = hours * n * 60 + minutes * n;
    result.minutes = totalminutes % 60;
    result.hours = totalminutes / 60;
    return result;
}*/

Time operator*(const Time &t, double n)
{
    Time result;
    long totalminutes = t.hours * n * 60 + t.minutes * n;
    result.minutes = totalminutes % 60;
    result.hours = totalminutes / 60;
    return result;
}

std::ostream & operator<<(std::ostream &os, const Time &t)
{
    os << t.hours << " hours, " << t.minutes << " minutes\n";
    return os;
}

void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes" << std::endl;
}
