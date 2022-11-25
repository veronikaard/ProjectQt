#ifndef STRINGBAD_H
#define STRINGBAD_H
#include <iostream>
#include <cstring>

class StringBad
{
private:
    char *str;                  //��������� �� ������
    int len;                    //����� ������
    static int num_strings;     //���������� ��������
public:
    StringBad(const char *s);   //�����������
    StringBad();                //����������� �� ���������
    ~StringBad();               //����������

    //������������� �-�
    friend std::ostream & operator<<(std::ostream &os, const StringBad &st);
};

#endif // STRINGBAD_H
