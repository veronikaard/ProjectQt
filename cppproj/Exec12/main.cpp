#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stringbad.h"
#include "string1.h"
#include "vect.h"
#include "queue.h"

using namespace std;

void callme1(StringBad &);  //�������� �� ������
void callme2(StringBad);    //�������� �� ��������

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
    /*cout << "������\n" << endl;
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

    //������� 12.6
    //������������� ������������ ������ String
    /*String name;
    cout << "Hi, wat's your name?\n";
    cin >> name;
    cout << name << ", ����������, ������� " << ArSize << " �������� ���� (��� ������ "
                                                          "������ ��� ����������):\n";
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
        cout << "����� ���������:\n";
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
        cout << "����� �������� ���������:\n" << saying[shortest] << endl;
        cout << "������ �� ��������\n" << saying[first] << endl;
        cout << "���������� ������������ ��������\n" << String::HowMany()
             << " String ��������. ���!\n";
    }
    else
        cout << "������ �� ���� �������!\n";*/

    /*using VECTOR::Vector;

    Vector force1(50, 60);
    Vector force2(10, 70);
    Vector max;
    max = Max(force1, force2);*/

    //������� 12.7
    //������������� ���������� �� �������
    /*String name;
    cout << "Hi, wat's your name?\n";
    cin >> name;
    cout << name << ", ����������, ������� " << ArSize << " �������� ���� (��� ������ "
                                                          "������ ��� ����������):\n";
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
        cout << "����� ���������:\n";
        for (int i = 0; i < total; i++)
            cout << saying[i][0] << ": " << saying[i] << endl;

        //��������� ��� ������������ ���������� � ������ ������
        String *shortest = &saying[0];      //������������� ������ ��������
        String *first = &saying[0];

        for (int i = 1; i < total; i++)
        {
            if (saying[i].length() < shortest->length())
                shortest = &saying[i];
            if (saying[i] < *first)
                first = &saying[i];
        }
        cout << "����� �������� ���������:\n" << *shortest << endl;
        cout << "������ �� ��������\n" << *first << endl;

        srand(time(0));
        int choice = rand() % total;

        String *favorite = new String(saying[choice]);
        cout << "�������� ���������: " << *favorite << endl;
        delete favorite;

        cout << "���������� ������������ ��������\n" << String::HowMany()
             << " String ��������. ���!\n";
    }
    else
        cout << "������ �� ���� �������!\n";*/

    //Listing 12.12
    //������������� ���������� queue
    srand(time(0));
    cout << "������� ������������ ������ �������: ";
    int qs;
    cin >> qs;
    Queue line(qs);
    cout << "������� ���������� ����������� �����: ";
    int hours;
    cin >> hours;

    long cyclelimit = MIN_PER_HR * hours;
    cout << "������� ���������� �������� � ���: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;    //������� ����� ����� �����������
    min_per_cust = MIN_PER_HR / perhour;
    Item temp;              //������ ������ �������
    long turnaways = 0;     //�� �������� � ������ �������
    long customers = 0;     //������������ � �������
    long served = 0;        //��������� �� ����� ��������
    long sum_line = 0;      //����� ����� �������
    int wait_time = 0;      //����� ��� ������������ ���������
    long line_wait = 0;     //������ ����� � �������

    //������ �������������
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))  //���� ���������� ������
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
            line.dequeue(temp);                 //������������ ���� �������
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }

        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();
    }

    //����� �����������
    if (customers > 0)
    {
        cout << "������� ��������: " << customers << endl;
        cout << "��������� ��������: " << served << endl;
        cout << "�� ������� ��������: " << turnaways << endl;
        cout << "������� ������ �������: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << double (sum_line/cyclelimit) << endl;
        cout << "������� ����� �������� " << double (line_wait / served ) << " �����\n";
    }
    else
        cout << "��� �����������!\n";


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
    cout << "�������, ���������� �� ������: ";
    cout << rsb << "\n";
}

void callme2(StringBad sp)
{
    cout << "������, ���������� �� ��������: ";
    cout << sp << endl;
}
