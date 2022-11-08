#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <stdlib.h>

class Move
{
private:
    double x;
    double y;
public:
    Move(double a = 0, double b = 0);
    void showmove() const;
    Move add(const Move &m);
    void reset(double a=0, double b=0);
    double getX() const {return x;}
    double getY() const {return y;}
};

#endif // MOVE_H
