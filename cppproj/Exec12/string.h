#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <cstring>

using std::istream;
using std::ostream;

class String
{
    char *str;                          //указатель на строку
    int len;                            //длина строки
    static int num_strings;             //количество объектов
    static const int CINLIM = 80;       //предел ввода дл€ cin
public:
    String(const char *s);              //конструктор
    String(const String &s);            //явный конструктор копировани€
    String();
    ~String();

    int length() const {return len;}

    //ƒружественные ф-и
    friend ostream & operator<<(ostream &os, const String &st);
    friend istream & operator>>(istream &is, String &st);
    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);

    //ѕерегруженные ф-и
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);               //предоставл€ют доступ к отдельным символам
    const char & operator[](int i) const;   //строки в виде массива

    static int HowMany(){return num_strings;}
};

#endif // STRING_H
