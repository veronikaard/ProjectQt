#include "stringbad.h"
using std::cout;

//������������� ������������ ����� ������
int StringBad::num_strings = 0;

StringBad::StringBad(const char *s)
{
    len = std::strlen(s);                   //��������� �������
    str = new char[len + 1];                //��������� ������
    std::strcpy(str, s);                    //������������� ���������
    num_strings++;                          //������� ��������
    cout << num_strings << ": \"" <<
            str << "\" ������ ������\n";
}

StringBad::StringBad()
{
    len = 4;                                //��������� �������
    str = new char[4];                      //��������� ������
    std::strcpy(str, "C++");                //������ �� ���������
    num_strings++;                          //������� ��������
    cout << num_strings << ": \"" <<
            str << "\" ������ �� ��������� ������\n";
}

std::ostream & operator<<(std::ostream &os, const StringBad &st)
{
    os << st.str;
    return os;
}

StringBad::~StringBad()
{
    cout << "\"" << str << "\" ������ ������, ";
    --num_strings;
    cout << num_strings << " ��������\n";
    delete [] str;
}
