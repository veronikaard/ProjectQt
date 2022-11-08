#include "Move.h"

Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::showmove() const
{
    using std::cout;
    using std::endl;
    cout << "x = " << x << ", y = " << y << endl;
}

Move Move::add(const Move &m)
{
    x += m.getX();
    y += m.getY();

    return *this;
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}
