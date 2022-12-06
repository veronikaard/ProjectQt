#ifndef QUEUE_H
#define QUEUE_H

class Customer
{
private:
    long arrive;            //момент появления клиента
    int processtime;        //время обслуживания клиента
public:
    Customer() {arrive = processtime = 0;}
    void set(long when);
    long when() const {return arrive;}
    int ptime() const {return processtime;}
};

typedef Customer Item;

class Queue
{
private:
    enum {Q_SIZE = 10};
    struct Node {Item item; struct Node *next;};

    //Закрытые члены класса
    Node *front;                        //Указатель на начало
    Node *rear;                         //Указатель на конец
    int items;                          //Текущее количество элементов
    const int qsize;                    //Максимальное количество элементов

    Queue(const Queue &q) : qsize(0) {} //упреждающее определение
    Queue & operator=(const Queue &q) {return *this;}

public:
    Queue(int qs = Q_SIZE);             //Создание очереди с предельным размером qs
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item &item);     //Добавление элемента в конец очереди
    bool dequeue(Item &item);           //Удаление элемента из начала очереди
};

#endif // QUEUE_H
