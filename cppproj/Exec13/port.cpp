#include "port.h"
#include <cstring>

using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;
/* Методы Port*/
Port::Port(const char *br, const char *st, int b)
{
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    brand[strlen(br)] = '\0';
    strcpy(style, st);
    bottles = b;
}

Port::Port(const Port &p)
{
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    brand[strlen(p.brand)] = '\0';
    strcpy(style, p.style);
    bottles = p.bottles;
}

Port & Port::operator=(const Port &p)
{
    if (this == &p)
        return *this;

    delete [] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    brand[strlen(p.brand)] = '\0';
    strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;
}

Port & Port::operator-=(int b)
{
    if (b < bottles)
        bottles -= b;
    else cout << "У нас нет столько бутылок!\n";
}

void Port::Show() const
{
    cout << "Бренд: " << brand << endl;
    cout << "Стиль: " << style << endl;
    cout << "Бутылок: " << bottles << endl;
}

std::ostream &operator<<(std::ostream &os, const Port &p)
{
    cout << p.brand << ", " << p.style << ", " << p.bottles;
}

/* Методы VintagePort*/
VintagePort::VintagePort(const char *br, int b, const char *nn, int y)
    : Port(br, "Vintage", b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    nickname[strlen(nn)] = '\0';

    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) : Port(vp)
{
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    nickname[strlen(vp.nickname)] = '\0';

    year = vp.year;
}

VintagePort::VintagePort() : Port()
{
    nickname = new char[5];
    strcpy(nickname, "none");
    nickname[4] = '\0';
    year = 0;
}

VintagePort & VintagePort::operator=(const VintagePort &vp)
{
    if (this == &vp)
        return *this;
    Port::operator=(vp);
    delete [] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    nickname[strlen(vp.nickname)] = '\0';

    year = vp.year;
}

void VintagePort::Show() const
{
    Port::Show();
    cout << "Персональное имя: " << nickname << endl;
    cout << "Год: " << year << endl;
}

std::ostream &operator<<(std::ostream &os, const VintagePort &vp)
{
    os << (const Port &)vp;
    os << ", " << vp.nickname << ", " << vp.year;
    return os;
}





