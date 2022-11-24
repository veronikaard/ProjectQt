#include "stonewt.h"
#include <cmath>
using std::cout;

Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;
    pds_left = lbs;
    pounds = lbs;
    state = pouFlo;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    state = Stn;
}

Stonewt::Stonewt()
{
    stone = pds_left = pounds = 0;
}

std::ostream & operator<<(std::ostream &os, const Stonewt &st)
{
    switch (st.state) {
    case st.pouFlo:
        os << "\t" << st.pounds << " pounds\n";
        break;
    case st.Stn:
        os << "\t\t" << st.stone << " stone, " << st.pds_left << " pounds\n";
        break;
    case st.pouInt:
        os << "\t" << int(st.pounds) << " pounds\n";
        break;
    default:
        break;
    }
    return os;
}

/*void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}*/

Stonewt Stonewt::operator *(double num) const
{
    Stonewt st;
    int total = pds_left * num  + stone * num * Lbs_per_stn;
    st.stone = total / Lbs_per_stn;
    st.pds_left = total % Lbs_per_stn;
    st.pounds = pounds * num;
    return st;
}

Stonewt Stonewt::operator+(Stonewt &st) const
{
    Stonewt temp(pounds + st.pounds);
    return temp;
}

Stonewt Stonewt::operator-(Stonewt &st) const
{
    Stonewt temp(pounds - st.pounds);
    return temp;
}

/*Stonewt::operator int() const
{
    return int (pounds + 0.5);
}

Stonewt::operator double() const
{
    return pounds;
}*/

/*Stonewt operator+(const Stonewt &st1, const Stonewt &st2)
{
    double pds = st1.pounds + st2.pounds;
    Stonewt sum(pds);
    return sum;
}*/

Stonewt::~Stonewt()
{

}
