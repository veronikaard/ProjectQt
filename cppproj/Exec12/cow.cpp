#include "cow.h"
#include <stdlib.h>

using std::cout;
using std::endl;
using std::strlen;

Cow::Cow() : weight(0)
{
    name[0] = '\0';
    hobby = new char[1];
    hobby[0] = '\0';
}

Cow::Cow(const char *nm, const char *ho, double wt)
{
    strcpy(name, nm);
    hobby = new char [strlen(ho) + 1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow &c)
{
    delete [] hobby;
    hobby = new char [strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    strcpy(name, c.name);
    weight = c.weight;
}

Cow::~Cow()
{
    delete [] hobby;
}

Cow & Cow::operator=(const Cow &c)
{
    if (this == &c)
        return *this;

    delete [] hobby;
    hobby = new char [strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    strcpy(name, c.name);
    weight = c.weight;

    return *this;
}

void Cow::ShowCow() const
{
    cout << name << " ";
    cout << hobby << " ";
    cout << weight << endl;
}
