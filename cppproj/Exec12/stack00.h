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
    enum {MAX = 10};    //константа, специфичная для класса
    Item1 *pitems;       //хранит элементы стека
    int size;           //количество элементов в стеке
    int top;            //индекс вершины стека
public:
    Stack(int n = 10);  //создает стэк с n элементами
    Stack(const Stack &st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item1 &item);    //добавляет элемент в стек
    bool pop(Item1 &item);           //выталкивает э-т с вершины стека
    Stack & operator=(const Stack &st);
    int getSize(){return size;}
    friend ostream & operator<<(ostream &os, const Stack &st);
};

#endif // STACK_H
