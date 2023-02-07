#include "workermi.h"
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

void Worker::Data() const
{
    cout << "Имя и Фамилия работника: " << fullname << endl;
    cout << "Идентификатор: " << id << endl;
}

void Worker::Get()
{
    getline(cin, fullname);
    cout << "Введите идентификатор работника: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}

void Waiter::Set()
{
    cout << "Введите имя и фамилию официанта: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const
{
    cout << "Категория: официант\n";
    Worker::Data();
    Data();
}

void Waiter::Data() const
{
    cout << "Индекс элегантности: " << panache << endl;
}

void Waiter::Get()
{
    cout << "Введите индекс элегантности официанта: ";
    cin >> panache;
    while (cin.get() != '\n')
        continue;
}

char * Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Set()
{
    cout << "Введите имя и фамилию певца: ";
    Worker::Get();
    Get();
    //while (cin >> voice && (voice < 0 || voice >= Vtypes))
    //    cout << "Введите значение в диапазоне от 0 до " << Vtypes - 1 << endl;
}

void Singer::Show() const
{
    cout << "Категория: певец\n";
    Worker::Data();
    Data();
}

void Singer::Data() const
{
    cout << "Вокальный диапазон: " << pv[voice] << endl;
}

void Singer::Get()
{
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
    cin >> voice;
    while (cin.get() != '\n')
        continue;
}

void SingingWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Get()
{
    Waiter::Get();
    Singer::Get();
}

void SingingWaiter::Set()
{
    cout << "Введите имя и фамилию поющего официанта: ";
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const
{
    cout << "Категория: поющий официант\n";
    Worker::Data();
    Data();
}
