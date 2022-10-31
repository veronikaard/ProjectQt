#ifndef STACK_H
#define STACK_H

typedef unsigned long Item;

class Stack
{
    enum {MAX = 10};    //константа, специфичная для класса
    Item items[MAX];    //хранит элементы стека
    int top;            //индекс вершины стека
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);    //добавляет элемент в стек
    bool pop(Item &item);           //выталкивает э-т с вершины стека
};

#endif // STACK_H
