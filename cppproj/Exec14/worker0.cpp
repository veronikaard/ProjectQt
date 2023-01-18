#include "worker0.h"
#include <iostream>
//������ ������� ����������

using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {}

void Worker::Set()
{
    cout << "������� ��� � ������� ���������: ";
    getline(cin, fullname);
    cout << "������� ������������� ���������: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}

void Worker::Show() const
{
    cout << "��� � ������� ���������: " << fullname << endl;
    cout << "�������������: " << id << endl;
}

void Waiter::Set()
{
    Worker::Set();
    cout << "������� ������ ������������ ���������: ";
    cin >> panache;
    while (cin.get() != '\n')
        continue;
}

void Waiter::Show() const
{
    cout << "���������: ��������\n";
    Worker::Show();
    cout << "������ ������������: " << panache << endl;
}

char * Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Set()
{
    Worker::Set();
    cout << "���� ������ ���������� ��������� �����: ";
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
        cout << "������� �������� � ��������� �� 0 �� " << Vtypes - 1 << endl;

    while (cin.get() != '\n')
        continue;
}

void Singer::Show() const
{
    cout << "���������: �����\n";
    Worker::Show();
    cout << "��������� ��������: " << pv[voice] << endl;
}
