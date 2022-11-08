#ifndef LIST_H
#define LIST_H
#include <iostream>

typedef int ItemList;

class List
{
    enum {MAX = 10};    //константа, специфичная для класса
    ItemList items[MAX];    //хранит элементы списка
    int top;            //индекс вершины списка
public:
    List();
    bool isEmpty() const;   //проверяет, пустой ли список
    bool isFull() const;
    bool AddElement(const ItemList &item);    //добавляет элемент в стек
    void visit(void (*pf)(ItemList &el));
};

#endif // LIST_H
