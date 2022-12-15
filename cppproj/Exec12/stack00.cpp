#include "stack00.h"

Stack::Stack(int n)
{
    size = n;
    pitems = new Item1[n];           //выделяем память для n элементов
    top = 0;    
}

Stack::Stack(const Stack &st)
{
    delete [] pitems;
    size = st.size;
    pitems = new Item1[size];

    top = st.top;

    for (int i = 0; i < size; i++)
        pitems[i] = st.pitems[i];

}

Stack & Stack::operator=(const Stack &st)
{
    if (this == &st)
        return *this;
    delete [] pitems;
    size = st.size;
    pitems = new Item1[size];
    top = st.top;

    for (int i = 0; i < size; i++)
        pitems[i] = st.pitems[i];
    return *this;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item1 &item)
{
    if (top < size)
    {
        pitems[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item1 &item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
        return false;
}

ostream & operator<<(ostream &os, const Stack &st)
{
    for (int i = 0; i < st.top; i++)
        os << st.pitems[i] << "\n";

    return os;
}

Stack::~Stack()
{
    delete [] pitems;
}
