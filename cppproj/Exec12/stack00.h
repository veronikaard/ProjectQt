#ifndef STACK_H
#define STACK_H

#include <iostream>

using std::ostream;

/*struct customer
{
    char fullname[35];
    double payment;
};*/

//typedef unsigned long Item;
typedef unsigned long Item1;


class Stack
{
    enum {MAX = 10};    //���������, ����������� ��� ������
    Item1 *pitems;       //������ �������� �����
    int size;           //���������� ��������� � �����
    int top;            //������ ������� �����
public:
    Stack(int n = 10);  //������� ���� � n ����������
    Stack(const Stack &st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item1 &item);    //��������� ������� � ����
    bool pop(Item1 &item);           //����������� �-� � ������� �����
    Stack & operator=(const Stack &st);
    int getSize(){return size;}
    friend ostream & operator<<(ostream &os, const Stack &st);
};

#endif // STACK_H
