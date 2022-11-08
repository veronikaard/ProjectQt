#include <iostream>
#include "stock00.h"
#include "stack.h"
#include "bankaccount.h"
#include "person.h"
#include "golf.h"
#include "sales.h"
#include "Move.h"
#include "plorg.h"
#include "list.h"

using namespace std;

void addition(ItemList &il);

int main()
{
    setlocale(LC_ALL, "Rus");
    /*Stock fluffy_the_cat("Nanosmart", 20, 12.5);
    fluffy_the_cat.show();

    Stock food = Stock("World Cabbage", 250, 1.25);
    food.show();

    food = fluffy_the_cat;
    food.show();

    Stock *cloth = new Stock("Zara", 50, 2.35);
    cloth->show();
    delete cloth;

    food = Stock("hjdj", 10, 0.2);
    food.show();

    Stock harry;
    harry.show();*/

    //������ ��������
    /*const int ST = 4;
    Stock stocks[ST] =
    {
        Stock("NanoSmart", 12.5, 20),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolohd", 130, 3.25),
        Stock("Fleep beep", 60, 6.5)
    };

    for (int i = 0; i < ST; i++)
        stocks[i].show();

    //��������� ��������� �� ������ �������
    const Stock *top = &stocks[0];

    for (int i = 1; i < ST; i++)
        top = &top->topval(stocks[i]);

    std::cout << "����� ������ ����� �����:\n";
    top->show();*/

    //������������ ������ Stack
    /*using std::cin;
    using std::cout;
    Stack st;
    char ch;
    unsigned long po;
    cout << "������� � - ����� �������� �����, � - ���������� �����,"
            "Q - ���������.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        };
        switch (ch) {
        case 'A':
        case 'a':
            cout << "������� ����� ��� ����������: ";
            cin >> po;
            if (st.isfull())
                cout << "���� ��� �����\n";
            else
               st.push(po);
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                cout << "���� ��� ����\n";
            else
            {
                st.pop(po);
                cout << "PO #" << po << "������\n";
            }
            break;
        default:
            break;
        }
        cout << "������� � - ����� �������� �����, � - ���������� �����,"
                "Q - ���������.\n";
    };
    cout << "Bye!\n";*/

    //���������� 1
    /*BankAccount lisa("���������", "1234", 1200);
    lisa.show();
    lisa.deposit(7500);
    lisa.show();
    lisa.withdraw(7500);
    lisa.show();

    BankAccount petr("����", "2145");
    petr.show();*/

    //���������� 2
    /*Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");

    one.Show();
    one.FormalShow();
    two.Show();
    two.FormalShow();
    three.Show();
    three.FormalShow();*/

    //���������� 3
    /*Golf Ann;
    Ann.Show();
    Ann.setgolf();
    Ann.Show();*/

    //���������� 4
    /*double mass[] = {12.6, 7.8, 8.9, 0.512};
    SALES::Sales sal(mass, 4);
    sal.showSales();
    sal.setSales();
    sal.showSales();*/

    //���������� 5
    /*using std::cin;
    using std::cout;
    Stack st;
    char ch;
    //unsigned long po;
    customer po;
    double total = 0.0;
    cout << "������� � - ����� �������� ���������, � - �������,"
            "Q - ���������.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        };
        switch (ch) {
        case 'A':
        case 'a':
            cout << "������� ��� ��������� ��� ����������: ";
            cin.getline(po.fullname, 35);
            cout << "������� �������� ��������� ��� ����������: ";
            cin >> po.payment;
            if (st.isfull())
                cout << "���� ��� �����\n";
            else
            {
                st.push(po);
                total += po.payment;
            }
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                cout << "���� ��� ����\n";
            else
            {
                st.pop(po);
                total -= po.payment;
                cout << po.fullname << " ������, ����� ����� = " << total << endl;
            }
            break;
        default:
            break;
        }
        cout << "������� � - ����� �������� ���������, � - �������,"
                "Q - ���������.\n";
    };
    cout << "Bye!\n";*/

    //���������� 6
    /*Move pos(12.2, 45.3);
    pos.showmove();
    //pos.reset(4, 99);
    //pos.showmove();
    Move posit(2, 7);
    posit.showmove();

    Move test = pos.add(posit);
    test.showmove();*/

    //���������� 7
    /*Plorg one;
    one.Show();

    Plorg two("Veron", 150);
    two.Show();

    two.setCI(10);
    two.Show();*/

    //���������� 8
    List l1;

    if (l1.isEmpty())
        cout << "List is empty\n";
    else
        cout << "List not empty\n";

    if (l1.AddElement(12))
        cout << "added element\n";
    else
        cout << "not added\n";
    l1.AddElement(0);
    l1.AddElement(45);
    l1.AddElement(3);

    l1.visit(addition);

    return 0;
}

void addition(ItemList &il)
{
    ItemList test = 5;
    il += test;
}

