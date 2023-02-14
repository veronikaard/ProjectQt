#ifndef ARRAYTP_H
#define ARRAYTP_H

//Шаблон массива

#include <iostream>
#include <cstdlib>

/* Ключевое слово class объявляет T как параметр типа, или аргумент типа.
 * Ключевое слово int объявляет, что n имеет тип int. Такой вид параметра -
 * определяющий конкретный тип, а не обоющенное имя типа - называется НЕТИПИ-
 * ЗИРОВАННЫМ ПАРАМЕТРОМ, или ПАРАМЕТРОМ-ВЫРАЖЕНИЕМ.
*/

template <class T, int n>
class ArrayTP
{
private:
    T ar[n];
public:
    ArrayTP() {}
    explicit ArrayTP(const T &v);
    virtual T & operator[] (int i);
    virtual T operator[](int i) const;
};

template <class T, int n>
ArrayTP<T, n>::ArrayTP(const T &v)
{
    for (int i = 0; i < n; i++)
        ar[i] = v;
}

template <class T, int n>
T & ArrayTP<T, n>::operator[] (int i)
{
    if (i < 0 || i >= n)
    {
        std::cerr << "Выход за пределы допустимого диапазона индекса в массиве.\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

template <class T, int n>
T ArrayTP<T, n>::operator[] (int i) const
{
    if (i < 0 || i >= n)
    {
        std::cerr << "Выход за пределы допустимого диапазона индекса в массиве.\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

#endif // ARRAYTP_H
