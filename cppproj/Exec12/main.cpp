#include <iostream>
#include "stringbad.h"
#include "string1.h"

using namespace std;

void callme1(StringBad &);  //�������� �� ������
void callme2(StringBad);    //�������� �� ��������

const int ArSize = 10;
const int MaxLen = 81;

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
    String name;
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
        cout << "������ �� ���� �������!\n";

    return 0;
}

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
