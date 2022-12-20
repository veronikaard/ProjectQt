#include <iostream>
#include "tabtenn0.h"
#include "brass.h"

using namespace std;
const int CLIENTS = 4;

int main()
{
    setlocale(LC_ALL, "Rus");
    /*TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);

    RatedPlayer rplayer1(1140, "Mellory", "Duck", true);
    RatedPlayer rplayer2(4445, player2);

    TableTennisPlayer &rt = rplayer1;
    rt.Name();
    cout << endl;

    TableTennisPlayer *pt = &rplayer2;
    pt->Name();
    cout << endl;

    rplayer1.Name();
    cout << ", rating: " << rplayer1.Rating();
    cout << endl;

    rplayer2.Name();
    cout << ", rating: " << rplayer2.Rating();
    cout << endl;

    player1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    player2.Name();

    if (player2.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";*/

    //Listing 13.9
    //Тестирование классов банковских счетов
    /*
    using std::cout;
    using std::endl;
    Brass Piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;
    cout << "Вносим депозит 1000$ на Hogg Account:\n";
    Hoggy.Deposit(1000.00);
    cout << "Обновленный баланс: $" << Hoggy.Balance() << endl;
    cout << "Снимаем 200$ с Piggy Account:\n";
    Piggy.Withdraw(4200);
    cout << "Pigg account баланс: $" << Piggy.Balance() << endl;
    cout << "Снимаем 4200$ с Hogg Account:\n";
    Hoggy.Withdraw(4200);
    Hoggy.ViewAcct();*/

    //Listing 13.10
    //пример полиморфизма
    using std::cout;
    using std::endl;
    using std::cin;

    Brass *p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Введите имя клиента: ";
        getline(cin, temp);
        cout << "Введите номер счета клиента: ";
        cin >> tempnum;
        cout << "Введите начальный баланс: $";
        cin >> tempbal;
        cout << "Введите 1 - для Brass счета, 2 - для BrassPlus счета: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "Введите 1 или 2:";
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "Введите предельное значение овердрафта: $";
            cin >> tmax;
            cout << "Введите процентую ставку: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (cin.get() != '\n') {
            continue;
        }
    }

    cout << endl;

    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];
    }

    cout << "Done.\n";

    return 0;
}
