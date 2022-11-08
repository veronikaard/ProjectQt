#ifndef LIST_H
#define LIST_H
#include <iostream>

typedef int ItemList;

class List
{
    enum {MAX = 10};    //���������, ����������� ��� ������
    ItemList items[MAX];    //������ �������� ������
    int top;            //������ ������� ������
public:
    List();
    bool isEmpty() const;   //���������, ������ �� ������
    bool isFull() const;
    bool AddElement(const ItemList &item);    //��������� ������� � ����
    void visit(void (*pf)(ItemList &el));
};

#endif // LIST_H
