#include "worker0.h"
#include <iostream>
//методы классов работников

using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {}

void Worker::Set()
{
    cout << "Введите имя и фамилию работника: ";
    getline(cin, fullname);
    cout << "Введите идентификатор работника: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}

void Worker::Show() const
{
    cout << "Имя и Фамилия работника: " << fullname << endl;
    cout << "Идентификатор: " << id << endl;
}

void Waiter::Set()
{
    Worker::Set();
    cout << "Введите индекс элегантности официанта: ";
    cin >> panache;
    while (cin.get() != '\n')
        continue;
}

void Waiter::Show() const
{
    cout << "Категория: официант\n";
    Worker::Show();
    cout << "Индекс элегантности: " << panache << endl;
}

char * Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Set()
{
    Worker::Set();
    cout << "Ввод номера вокального диапазона певца: ";
    int i;
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << pv[i] << " ";
        if (i%4 == 3)
            cout << endl;
    }

    if (i % 4 != 0)
        cout << endl;

    while (cin >> voice && (voice < 0 || voice >= Vtypes))
        cout << "Введите значение в диапазоне от 0 до " << Vtypes - 1 << endl;

    while (cin.get() != '\n')
        continue;
}

void Singer::Show() const
{
    cout << "Категория: певец\n";
    Worker::Show();
    cout << "Вокальный диапазон: " << pv[voice] << endl;
}
