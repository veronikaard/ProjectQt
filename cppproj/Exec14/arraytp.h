#ifndef ARRAYTP_H
#define ARRAYTP_H

//������ �������

#include <iostream>
#include <cstdlib>

/* �������� ����� class ��������� T ��� �������� ����, ��� �������� ����.
 * �������� ����� int ���������, ��� n ����� ��� int. ����� ��� ��������� -
 * ������������ ���������� ���, � �� ���������� ��� ���� - ���������� ������-
 * ���������� ����������, ��� ����������-����������.
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
        std::cerr << "����� �� ������� ����������� ��������� ������� � �������.\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

template <class T, int n>
T ArrayTP<T, n>::operator[] (int i) const
{
    if (i < 0 || i >= n)
    {
        std::cerr << "����� �� ������� ����������� ��������� ������� � �������.\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

#endif // ARRAYTP_H
