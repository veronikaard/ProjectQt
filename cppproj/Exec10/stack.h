#ifndef STACK_H
#define STACK_H

typedef unsigned long Item;

class Stack
{
    enum {MAX = 10};    //���������, ����������� ��� ������
    Item items[MAX];    //������ �������� �����
    int top;            //������ ������� �����
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);    //��������� ������� � ����
    bool pop(Item &item);           //����������� �-� � ������� �����
};

#endif // STACK_H
