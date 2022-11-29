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

StringBad::StringBad(const StringBad &s)
{
    num_strings++;              //обновление статического члена
    len = s.len;                //та же самая длина
    str = new char[len+1];      //выделение памяти
    std::strcpy(str, s.str);    //копироование строки в новое место
    cout << num_strings << ": \"" <<
            str << "\" объект создан\n";
}

StringBad & StringBad::operator=(const StringBad &s)
{
    if (this == &s)             //присваивание объекта самому себе
        return *this;
    delete [] str;              //освобождение старой строки
    len = s.len;                //та же самая длина
    str = new char[len+1];      //выделение памяти для новой строки
    std::strcpy(str, s.str);    //копироование строки в новое место
    return *this;               //возврат ссылки на вызывающий объект
}

StringBad::~StringBad()
{
    cout << "\"" << str << "\" объект удален, ";
    --num_strings;
    cout << num_strings << " осталось\n";
    delete [] str;
}
