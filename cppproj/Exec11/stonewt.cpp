#include "stonewt.h"
#include <cmath>
using std::cout;

Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;
    pds_left = lbs;
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
    stone = pds_left = pounds = 0;
}

void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

Stonewt Stonewt::operator *(double num) const
{
    Stonewt st;

    int total = pds_left * num  + stone * num * Lbs_per_stn;

    st.stone = total / Lbs_per_stn;
    st.pds_left = total % Lbs_per_stn;

    st.pounds = pounds * num;

    return st;
}

/*Stonewt::operator int() const
{
    return int (pounds + 0.5);
}

Stonewt::operator double() const
{
    return pounds;
}*/

Stonewt operator+(const Stonewt &st1, const Stonewt &st2)
{
    double pds = st1.pounds + st2.pounds;
    Stonewt sum(pds);
    return sum;
}

Stonewt::~Stonewt()
{

}
