#include "plorg.h"

Plorg::Plorg(const char *nm, int ci)
{
    strcpy(name, nm);
    ContentIndex = ci;
}

void Plorg::Show() const
{
    using std::cout;
    using std::endl;

    cout << name << " have CI = " << ContentIndex << endl;
}

void Plorg::setCI(int ci)
{
    ContentIndex = ci;
}
