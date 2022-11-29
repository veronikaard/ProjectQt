#include "string.h"
using std::cout;

//Инициализация статического члена класса
int String::num_strings = 0;

String::String()
{
    len = 0;
    str = new char[1];
    str[0] = '\0';
}

String::String(const char *s)
{
    len = std::strlen(s);                   //установка размера
    str = new char[len + 1];                //выделение памяти
    std::strcpy(str, s);                    //инициализация указателя
    num_strings++;                          //счетчик объектов
}

ostream & operator<<(ostream &os, const String &st)
{
    os << st.str;
    return os;
}

istream & operator<<(istream &is, String &st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

String::String(const String &s)
{
    num_strings++;              //обновление статического члена
    len = s.len;                //та же самая длина
    str = new char[len+1];      //выделение памяти
    std::strcpy(str, s.str);    //копироование строки в новое место
}

String & String::operator=(const String &s)
{
    if (this == &s)             //присваивание объекта самому себе
        return *this;
    delete [] str;              //освобождение старой строки
    len = s.len;                //та же самая длина
    str = new char[len+1];      //выделение памяти для новой строки
    std::strcpy(str, s.str);    //копироование строки в новое место
    return *this;               //возврат ссылки на вызывающий объект
}

String & String::operator=(const char *s)
{
    delete [] str;              //освобождение старой строки
    len = std::strlen(s);       //та же самая длина
    str = new char[len+1];      //выделение памяти для новой строки
    std::strcpy(str, s);        //копироование строки в новое место
    return *this;               //возврат ссылки на вызывающий объект
}

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2.str < st1.str;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}

String::~String()
{
    --num_strings;
    delete [] str;
}
