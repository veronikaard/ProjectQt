#include <iostream>
//#include "tabtenn0.h"
//#include "brass.h"
#include "acctabc.h"
#include "dma.h"

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
    //������������ ������� ���������� ������
    /*
    using std::cout;
    using std::endl;
    Brass Piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;
    cout << "������ ������� 1000$ �� Hogg Account:\n";
    Hoggy.Deposit(1000.00);
    cout << "����������� ������: $" << Hoggy.Balance() << endl;
    cout << "������� 200$ � Piggy Account:\n";
    Piggy.Withdraw(4200);
    cout << "Pigg account ������: $" << Piggy.Balance() << endl;
    cout << "������� 4200$ � Hogg Account:\n";
    Hoggy.Withdraw(4200);
    Hoggy.ViewAcct();*/

    //Listing 13.10
    //������ ������������
    /*using std::cout;
    using std::endl;
    using std::cin;

    Brass *p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "������� ��� �������: ";
        getline(cin, temp);
        cout << "������� ����� ����� �������: ";
        cin >> tempnum;
        cout << "������� ��������� ������: $";
        cin >> tempbal;
        cout << "������� 1 - ��� Brass �����, 2 - ��� BrassPlus �����: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "������� 1 ��� 2:";
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "������� ���������� �������� ����������: $";
            cin >> tmax;
            cout << "������� ��������� ������: ";
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

    cout << "Done.\n";*/

    //Listing 13.13
    //����������� ������ � �������������� ������������ �������� ������
    /*using std::cout;
    using std::endl;
    using std::cin;

    AcctABC *p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "������� ��� �������: ";
        getline(cin, temp);
        cout << "������� ����� ����� �������: ";
        cin >> tempnum;
        cout << "������� ��������� ������: $";
        cin >> tempbal;
        cout << "������� 1 - ��� Brass �����, 2 - ��� BrassPlus �����: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "������� 1 ��� 2:";
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "������� ���������� �������� ����������: $";
            cin >> tmax;
            cout << "������� ��������� ������: ";
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
        p_clients[i]->ViewAct();
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];
    }*/

    //Listing 13.16
    //������������, ������ � ������������ ��������� ������

    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lacksDMA ballon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo keys", 5);
    cout << "baseDMA: \n" << shirt << endl;
    cout << "lacksDMA: \n" << ballon << endl;
    cout << "hasDMA: \n" << map << endl;

    lacksDMA ballon2(ballon);
    cout << "lacksDMA copy: \n" << ballon2 << endl;

    hasDMA map2;
    map2 = map;
    cout << "hasDMA assignment: \n" << map2 << endl;

    cout << "Done.\n";

    return 0;
}
