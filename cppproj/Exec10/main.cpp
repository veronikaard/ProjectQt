#include <iostream>
#include "stock00.h"
#include "stack.h"
#include "bankaccount.h"
#include "person.h"
#include "golf.h"
#include "sales.h"

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

    //массив объектов
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

    //установка указателя на первый элемент
    const Stock *top = &stocks[0];

    for (int i = 1; i < ST; i++)
        top = &top->topval(stocks[i]);

    std::cout << "Самый ценный пакет акций:\n";
    top->show();*/

    //Тестирование класса Stack
    /*using std::cin;
    using std::cout;
    Stack st;
    char ch;
    unsigned long po;
    cout << "Введите А - чтобы добавить заказ, Р - обработать заказ,"
            "Q - завершить.\n";
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
            cout << "Введите номер для добавления: ";
            cin >> po;
            if (st.isfull())
                cout << "Стек уже полон\n";
            else
               st.push(po);
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                cout << "Стек уже пуст\n";
            else
            {
                st.pop(po);
                cout << "PO #" << po << "удален\n";
            }
            break;
        default:
            break;
        }
        cout << "Введите А - чтобы добавить заказ, Р - обработать заказ,"
                "Q - завершить.\n";
    };
    cout << "Bye!\n";*/

    //Упражнение 1
    /*BankAccount lisa("Елизавета", "1234", 1200);
    lisa.show();
    lisa.deposit(7500);
    lisa.show();
    lisa.withdraw(7500);
    lisa.show();

    BankAccount petr("Петя", "2145");
    petr.show();*/

    //Упражнение 2
    /*Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");

    one.Show();
    one.FormalShow();
    two.Show();
    two.FormalShow();
    three.Show();
    three.FormalShow();*/

    //Упражнение 3
    /*Golf Ann;
    Ann.Show();
    Ann.setgolf();
    Ann.Show();*/

    //Упражнение 4
    /*double mass[] = {12.6, 7.8, 8.9, 0.512};
    SALES::Sales sal(mass, 4);
    sal.showSales();
    sal.setSales();
    sal.showSales();*/

    //Упражнение 5
    using std::cin;
    using std::cout;
    Stack st;
    char ch;
    //unsigned long po;
    customer po;
    double total = 0.0;
    cout << "Введите А - чтобы добавить заказчика, Р - удалить,"
            "Q - завершить.\n";
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
            cout << "Введите имя заказчика для добавления: ";
            cin.getline(po.fullname, 35);
            cout << "Введите зарплату заказчика для добавления: ";
            cin >> po.payment;
            if (st.isfull())
                cout << "Стек уже полон\n";
            else
            {
                st.push(po);
                total += po.payment;
            }
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                cout << "Стек уже пуст\n";
            else
            {
                st.pop(po);
                total -= po.payment;
                cout << po.fullname << " удален, общая сумма = " << total << endl;
            }
            break;
        default:
            break;
        }
        cout << "Введите А - чтобы добавить заказчика, Р - удалить,"
                "Q - завершить.\n";
    };
    cout << "Bye!\n";

    //Упражнение 6
    //Упражнение 7
    //Упражнение 8

    return 0;
}
