#include "stringbad.h"
using std::cout;

//Инициализация статического члена класса
int StringBad::num_strings = 0;

StringBad::StringBad(const char *s)
{
    len = std::strlen(s);                   //установка размера
    str = new char[len + 1];                //выделение памяти
    std::strcpy(str, s);                    //инициализация указателя
    num_strings++;                          //счетчик объектов
    cout << num_strings << ": \"" <<
            str << "\" объект создан\n";
}

StringBad::StringBad()
{
    len = 4;                                //установка размера
    str = new char[4];                      //выделение памяти
    std::strcpy(str, "C++");                //строка по умолчанию
    num_strings++;                          //счетчик объектов
    cout << num_strings << ": \"" <<
            str << "\" объект по умолчанию создан\n";
}

std::ostream & operator<<(std::ostream &os, const StringBad &st)
{
    os << st.str;
    return os;
}

StringBad::~StringBad()
{
    cout << "\"" << str << "\" объект удален, ";
    --num_strings;
    cout << num_strings << " осталось\n";
    delete [] str;
}
