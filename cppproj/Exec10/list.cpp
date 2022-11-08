#include "list.h"

List::List()
{
    top = 0; //пустой список
}

bool List::isEmpty() const
{
    return top == 0;
}

bool List::isFull() const
{
    return top == MAX;
}

bool List::AddElement(const ItemList &item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

void List::visit(void (*pf)(ItemList &el))
{
    for (int i = 0; i < top; i++)
    {
        std::cout << items[i] << " ";
        pf(items[i]);
        std::cout << items[i] << std::endl;
    }
}


