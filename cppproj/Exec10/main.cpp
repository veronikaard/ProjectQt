#include <iostream>
#include "stock00.h"
#include "stack.h"

using namespace std;

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
    using std::cin;
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
    cout << "Bye!\n";

    return 0;
}
