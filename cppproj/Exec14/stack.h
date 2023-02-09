#ifndef STACK_H
#define STACK_H


struct customer
{
    char fullname[35];
    double payment;
};

//typedef unsigned long Item;
//typedef customer Item;

template <class Type>
class Stack
{
    enum {MAX = 10};    //���������, ����������� ��� ������
    Type items[MAX];    //������ �������� �����
    int top;            //������ ������� �����
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Type &item);    //��������� ������� � ����
    bool pop(Type &item);           //����������� �-� � ������� �����
};

template <class Type>
Stack<Type>::Stack()
{
    top = 0;
}

template <class Type>
bool Stack<Type>::isempty() const
{
    return top == 0;
}

template <class Type>
bool Stack<Type>::isfull() const
{
    return top == MAX;
}

template <class Type>
bool Stack<Type>::push(const Type &item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

template <class Type>
bool Stack<Type>::pop(Type &item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

#endif // STACK_H
