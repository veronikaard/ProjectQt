#include "string.h"
using std::cout;

//������������� ������������ ����� ������
int String::num_strings = 0;

String::String()
{
    len = 0;
    str = new char[1];
    str[0] = '\0';
}

String::String(const char *s)
{
    len = std::strlen(s);                   //��������� �������
    str = new char[len + 1];                //��������� ������
    std::strcpy(str, s);                    //������������� ���������
    num_strings++;                          //������� ��������
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
    num_strings++;              //���������� ������������ �����
    len = s.len;                //�� �� ����� �����
    str = new char[len+1];      //��������� ������
    std::strcpy(str, s.str);    //������������ ������ � ����� �����
}

String & String::operator=(const String &s)
{
    if (this == &s)             //������������ ������� ������ ����
        return *this;
    delete [] str;              //������������ ������ ������
    len = s.len;                //�� �� ����� �����
    str = new char[len+1];      //��������� ������ ��� ����� ������
    std::strcpy(str, s.str);    //������������ ������ � ����� �����
    return *this;               //������� ������ �� ���������� ������
}

String & String::operator=(const char *s)
{
    delete [] str;              //������������ ������ ������
    len = std::strlen(s);       //�� �� ����� �����
    str = new char[len+1];      //��������� ������ ��� ����� ������
    std::strcpy(str, s);        //������������ ������ � ����� �����
    return *this;               //������� ������ �� ���������� ������
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
