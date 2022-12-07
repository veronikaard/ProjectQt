#include "string1.h"
#include <cstring>
using std::cout;

//������������� ������������ ����� ������
int String::num_strings = 0;

String::String()
{
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const char *s)
{
    len = std::strlen(s);                   //��������� �������
    str = new char[len + 1];                //��������� ������
    std::strcpy(str, s);                    //������������� ���������
    num_strings++;                          //������� ��������
}

int String::HowMany()
{
    return num_strings;
}

ostream & operator<<(ostream &os, const String &st)
{
    os << st.str;
    return os;
}

istream & operator>>(istream &is, String &st)
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

String operator+(const String &s1, const String &s2)
{
    int lenth = s1.len + s2.len;
    char *temp = new char[lenth + 1];
    strcpy(temp, s1.str);
    strcpy(temp+s1.len, s2.str);
    temp[lenth + 1] = '\0';
    String s(temp);
    return s;
}

void String::stringlow()
{
    char temp[len + 1];
    int i = 0;
    while (i < len) {
        temp[i] = tolower(str[i]);
        //str[i] = temp;
        i++;
    }
    temp[len] = '\0';

    delete [] str;
    str = new char[len+1];
    std::strcpy(str, temp);
}

void String::stringup()
{
    char temp[len + 1];
    int i = 0;
    while (i < len) {
        temp[i] = toupper(str[i]);
        i++;
    }
    temp[len] = '\0';

    delete [] str;
    str = new char[len+1];
    std::strcpy(str, temp);
}

int String::timesChar(char ch)
{
    int count = 0;
    int i = 0;
    while (i < len) {
        if (str[i] == ch)
            count++;
        i++;
    }
    return count;
}

String::~String()
{
    --num_strings;
    delete [] str;
}
