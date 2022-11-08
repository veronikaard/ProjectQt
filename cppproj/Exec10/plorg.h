#ifndef PLORG_H
#define PLORG_H
#include <iostream>
#include <string.h>

class Plorg
{
    static const int LEN = 19;
    char name[LEN];
    int ContentIndex;
public:
    Plorg(const char *nm = "Plorga", int ci = 50);
    void Show() const;
    void setCI(int ci);
};

#endif // PLORG_H
