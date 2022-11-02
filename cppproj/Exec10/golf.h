#ifndef GOLF_H
#define GOLF_H

#include <iostream>
#include <string.h>

class Golf
{
private:
    static const int Len = 40;
    struct golf
    {
        char fullname[Len];
        int handicap;
    };

    golf g;
public:
    Golf() {g.fullname[0] = '\0'; g.handicap = 0;}
    Golf(const char *name, int hc);
    void handicap(int hc);
    void Show(void) const;
    int setgolf();
};

#endif // GOLF_H
