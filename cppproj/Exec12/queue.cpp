#include "queue.h"
#include <cstdlib>

void Customer::set(long when)
{
    using namespace std;
    processtime = rand() % 3 + 1;
    arrive = when;
}

Queue::Queue(int qs) : qsize(qs), front(nullptr), rear(nullptr), items(0)
{
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

bool Queue::enqueue(const Item &item)
{
    if (isfull())
        return false;
    Node *add = new Node;       //Создание узла
    add->item = item;           //Занесение указателей на узлы
    add->next = nullptr;
    items++;
    if (front == nullptr)       //если очередь пуста,
        front = add;            //элемент помещается в начало
    else
        rear = add;             //иначе он помещается в конец
    rear = add;
    return true;
}

bool Queue::dequeue(Item &item)
{
    if (front == nullptr)
        return false;
    item = front->item;     //в item заносится первый элемент из очереди
    items--;
    Node *temp = front;     //сохранение местоположения первого элемента
    front = front->next;    //сдвиг указателя начала на следующий элемент
    delete temp;            //удаление предыдущего первого элемента
    if (items == 0)
        rear = nullptr;
    return true;
}

Queue::~Queue()
{
    Node *temp;
    while (front != nullptr)        //Пока очередь не пуста
    {
        temp = front;               //Сохранение адреса начального элемента
        front = front->next;        //переустановка указателя на следующий элемент
        delete temp;                //удаление предыдущего начального элемента
    }
}
