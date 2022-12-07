#ifndef STRING1_H
#define STRING1_H
#include <iostream>
#include <cctype>
using std::istream;
using std::ostream;

class String
{
    char *str;                          //указатель на строку
    int len;                            //длина строки
    static int num_strings;             //количество объектов

public:
    String(const char *s);              //конструктор
    String(const String &s);            //явный конструктор копировани€
    String();
    ~String();
    static const int CINLIM = 80;       //предел ввода дл€ cin
    int length() const {return len;}
    void stringlow();
    void stringup();
    int timesChar(char ch);

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
    friend String operator+(const String &s1, const String &s2);

    static int HowMany();
};

#endif // STRING1_H
