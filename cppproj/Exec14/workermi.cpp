#include "workermi.h"
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

void Worker::Data() const
{
    cout << "��� � ������� ���������: " << fullname << endl;
    cout << "�������������: " << id << endl;
}

void Worker::Get()
{
    getline(cin, fullname);
    cout << "������� ������������� ���������: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}

void Waiter::Set()
{
    cout << "������� ��� � ������� ���������: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const
{
    cout << "���������: ��������\n";
    Worker::Data();
    Data();
}

void Waiter::Data() const
{
    cout << "������ ������������: " << panache << endl;
}

void Waiter::Get()
{
    cout << "������� ������ ������������ ���������: ";
    cin >> panache;
    while (cin.get() != '\n')
        continue;
}

char * Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Set()
{
    cout << "������� ��� � ������� �����: ";
    Worker::Get();
    Get();
    //while (cin >> voice && (voice < 0 || voice >= Vtypes))
    //    cout << "������� �������� � ��������� �� 0 �� " << Vtypes - 1 << endl;
}

void Singer::Show() const
{
    cout << "���������: �����\n";
    Worker::Data();
    Data();
}

void Singer::Data() const
{
    cout << "��������� ��������: " << pv[voice] << endl;
}

void Singer::Get()
{
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
    cout << "������� ��� � ������� ������� ���������: ";
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const
{
    cout << "���������: ������ ��������\n";
    Worker::Data();
    Data();
}
