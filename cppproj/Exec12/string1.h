#ifndef STRING1_H
#define STRING1_H
#include <iostream>
using std::istream;
using std::ostream;

class String
{
    char *str;                          //��������� �� ������
    int len;                            //����� ������
    static int num_strings;             //���������� ��������

public:
    String(const char *s);              //�����������
    String(const String &s);            //����� ����������� �����������
    String();
    ~String();
    static const int CINLIM = 80;       //������ ����� ��� cin
    int length() const {return len;}

    //������������� �-�
    friend ostream & operator<<(ostream &os, const String &st);
    friend istream & operator>>(istream &is, String &st);
    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);

    //������������� �-�
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);               //������������� ������ � ��������� ��������
    const char & operator[](int i) const;   //������ � ���� �������

    static int HowMany();
};

#endif // STRING1_H
