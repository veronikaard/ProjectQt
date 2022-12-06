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
    Node *add = new Node;       //�������� ����
    add->item = item;           //��������� ���������� �� ����
    add->next = nullptr;
    items++;
    if (front == nullptr)       //���� ������� �����,
        front = add;            //������� ���������� � ������
    else
        rear = add;             //����� �� ���������� � �����
    rear = add;
    return true;
}

bool Queue::dequeue(Item &item)
{
    if (front == nullptr)
        return false;
    item = front->item;     //� item ��������� ������ ������� �� �������
    items--;
    Node *temp = front;     //���������� �������������� ������� ��������
    front = front->next;    //����� ��������� ������ �� ��������� �������
    delete temp;            //�������� ����������� ������� ��������
    if (items == 0)
        rear = nullptr;
    return true;
}

Queue::~Queue()
{
    Node *temp;
    while (front != nullptr)        //���� ������� �� �����
    {
        temp = front;               //���������� ������ ���������� ��������
        front = front->next;        //������������� ��������� �� ��������� �������
        delete temp;                //�������� ����������� ���������� ��������
    }
}
