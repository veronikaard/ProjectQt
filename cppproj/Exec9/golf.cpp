#include <iostream>
#include "golf.h"
#include <ctype.h>
#include <cmath>
#include <cstring>

void setgolf(golf &g, const char *name, int hc)
{
    for (int i = 0; i < strlen(name); i++)
        g.fullname[i] = name[i];
    g.fullname[strlen(name)] = '\0';
    g.handicap = hc;
}

int setgolf(golf &g)
{
    using std::cout;
    using std::cin;
    using std::endl;
    int result = 0;
    memset(g.fullname, 0x00, sizeof(g.fullname));
    cout << "Enter name player: ";
    cin.get(g.fullname, Len);


    cout << ", enter handycap players: ";
    cin >> g.handicap;
    if (strlen(g.fullname) > 0)
        result = 1;
    else result = 0;
    return result;
}

void handycap(golf &g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf &g)
{
    std::cout << g.fullname << ", " << g.handicap << std::endl;
}
