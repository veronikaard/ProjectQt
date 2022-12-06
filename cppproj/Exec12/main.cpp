#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stringbad.h"
#include "string1.h"
#include "vect.h"
#include "queue.h"

using namespace std;

void callme1(StringBad &);  //Передача по ссылке
void callme2(StringBad);    //Передача по значению

using VECTOR::Vector;
Vector Max(const Vector &v1, const Vector &v2);
//const Vector & Max(const Vector &v1, const Vector &v2);

const int ArSize = 10;
const int MaxLen = 81;

const int MIN_PER_HR = 60;
bool newcustomer(double x);

int main()
{
    setlocale(LC_ALL, "Rus");
    /*cout << "Начало\n" << endl;
    StringBad headline1("at Midnight");
    StringBad headline2("Lettuce");
    StringBad sports("for Dollars");

    cout << "headline1 = " << headline1 << endl;
    cout << "headline2 = " << headline2 << endl;
    cout << "sports = " << sports << endl;

    callme1(headline1);
    cout << "headline1 = " << headline1 << endl;

    callme2(headline2);
    cout << "headline2 = " << headline2 << endl;

    StringBad sailor = sports;
    cout << "sailor = " << sailor << endl;

    StringBad knot;
    knot = headline1;
    cout << "knot = " << knot << endl;*/

    //Листинг 12.6
    //Использование расширенного класса String
    /*String name;
    cout << "Hi, wat's your name?\n";
    cin >> name;
    cout << name << ", пожалуйста, введите " << ArSize << " коротких фраз (или пустую "
                                                          "строку для завершения):\n";
    String saying[ArSize];
    char temp[MaxLen];
    int i;

    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0')
            break;
        else
            saying[i] = temp;
    }

    int total = i;
    if (total > 0)
    {
        cout << "Вывод поговорок:\n";
        for (int i = 0; i < total; i++)
            cout << saying[i][0] << ": " << saying[i] << endl;
        int shortest = 0;
        int first = 0;
        for (int i = 1; i < total; i++)
        {
            if (saying[i].length() < saying[shortest].length())
                shortest = i;
            if (saying[i] < saying[first])
                first = i;
        }
        cout << "Самая короткая поговорка:\n" << saying[shortest] << endl;
        cout << "Первая по алфавиту\n" << saying[first] << endl;
        cout << "Количество используемых объектов\n" << String::HowMany()
             << " String объектов. Бай!\n";
    }
    else
        cout << "Ничего не было введено!\n";*/

    /*using VECTOR::Vector;

    Vector force1(50, 60);
    Vector force2(10, 70);
    Vector max;
    max = Max(force1, force2);*/

    //Листинг 12.7
    //Использование указателей на объекты
    /*String name;
    cout << "Hi, wat's your name?\n";
    cin >> name;
    cout << name << ", пожалуйста, введите " << ArSize << " коротких фраз (или пустую "
                                                          "строку для завершения):\n";
    String saying[ArSize];
    char temp[MaxLen];
    int i;

    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0')
            break;
        else
            saying[i] = temp;
    }

    int total = i;
    if (total > 0)
    {
        cout << "Вывод поговорок:\n";
        for (int i = 0; i < total; i++)
            cout << saying[i][0] << ": " << saying[i] << endl;

        //Указатели для отслеживания кратчайшей и первой строки
        String *shortest = &saying[0];      //инициализация первым объектом
        String *first = &saying[0];

        for (int i = 1; i < total; i++)
        {
            if (saying[i].length() < shortest->length())
                shortest = &saying[i];
            if (saying[i] < *first)
                first = &saying[i];
        }
        cout << "Самая короткая поговорка:\n" << *shortest << endl;
        cout << "Первая по алфавиту\n" << *first << endl;

        srand(time(0));
        int choice = rand() % total;

        String *favorite = new String(saying[choice]);
        cout << "Любиамая пословица: " << *favorite << endl;
        delete favorite;

        cout << "Количество используемых объектов\n" << String::HowMany()
             << " String объектов. Бай!\n";
    }
    else
        cout << "Ничего не было введено!\n";*/

    //Listing 12.12
    //Использование интерфейса queue
    srand(time(0));
    cout << "Введите максимальный размер очереди: ";
    int qs;
    cin >> qs;
    Queue line(qs);
    cout << "Введите количество эмулируемых часов: ";
    int hours;
    cin >> hours;

    long cyclelimit = MIN_PER_HR * hours;
    cout << "Введите количество клиентов в час: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;    //среднее время между появлениями
    min_per_cust = MIN_PER_HR / perhour;
    Item temp;              //данные нового клиента
    long turnaways = 0;     //не допущены в полную очередь
    long customers = 0;     //присоединены к очереди
    long served = 0;        //обслужены во время эмуляции
    long sum_line = 0;      //общая длина очереди
    int wait_time = 0;      //время ддо освобождения банкомата
    long line_wait = 0;     //ообщее время в очереди

    //Запуск моделирования
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))  //есть подошедший клиент
        {
            if (line.isfull())
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }

        if (wait_time <= 0 && !line.isempty() )
        {
            line.dequeue(temp);                 //обслуживание след клиента
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }

        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();
    }

    //Вывод результатов
    if (customers > 0)
    {
        cout << "Принято клиентов: " << customers << endl;
        cout << "обслужено клиентов: " << served << endl;
        cout << "не принято клиентов: " << turnaways << endl;
        cout << "средний размер очереди: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << double (sum_line/cyclelimit) << endl;
        cout << "среднее время ожидания " << double (line_wait / served ) << " минут\n";
    }
    else
        cout << "Нет посетителей!\n";


    return 0;
}

bool newcustomer(double x)
{
    return (rand() * x / RAND_MAX < 1);
}

Vector Max(const Vector &v1, const Vector &v2)
{
    if (v1.magval() > v2.magval())
        return v1;
    else
        return v2;
}

/*const Vector & Max(const Vector &v1, const Vector &v2)
{
    if (v1.magval() > v2.magval())
        return v1;
    else
        return v2;
}*/

void callme1(StringBad &rsb)
{
    cout << "Строока, переданная по ссылке: ";
    cout << rsb << "\n";
}

void callme2(StringBad sp)
{
    cout << "Строка, переданная по значению: ";
    cout << sp << endl;
}
