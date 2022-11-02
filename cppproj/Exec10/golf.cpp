#include "golf.h"

Golf::Golf(const char *name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

void Golf::handicap(int hc)
{
    g.handicap = hc;
}

void Golf::Show() const
{
    std::cout << g.fullname << " " << g.handicap << std::endl;
}

int Golf::setgolf()
{
    using std::cout;
    using std::cin;
    using std::endl;
    int result = 0;
    golf gf;
    memset(gf.fullname, 0x00, sizeof(gf.fullname));
    cout << "Enter name player: ";
    cin.get(gf.fullname, Len);

    cout << ", enter handycap players: ";
    cin >> gf.handicap;

    Golf temp(gf.fullname, gf.handicap);
    *this = temp;

    if (strlen(gf.fullname) > 0)
        result = 1;
    else result = 0;
    return result;
}
