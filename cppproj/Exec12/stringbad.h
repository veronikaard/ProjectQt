#ifndef STRINGBAD_H
#define STRINGBAD_H
#include <iostream>
#include <cstring>

class StringBad
{
private:
    char *str;                      //указатель на строку
    int len;                        //длина строки
    static int num_strings;         //количество объектов
public:
    StringBad(const char *s);       //конструктор
    StringBad();                    //конструктор по умолчанию
    StringBad(const StringBad &s);  //Явный конструктор копирования
    ~StringBad();                   //деструктор


    //Дружественные ф-и
    friend std::ostream & operator<<(std::ostream &os, const StringBad &st);

    StringBad & operator=(const StringBad &);
};

#endif // STRINGBAD_H
