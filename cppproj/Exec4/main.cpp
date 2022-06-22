#include <iostream>
#include <clocale>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    //Listing 4.2
    //сохранение строк в массиве
    /*const int Size = 15;
    char name1[Size];
    char name2[Size] = "C++owboy";
    cout << name2 << endl;
    cin >> name1;
    cout << name1 << endl;
    cout << strlen(name1) << " " << sizeof(name1) << endl;
    cout << name1[0] << endl;
    name2[3] = '\0';
    cout << name2 << endl;*/

    //Listing 4.4
    //чтение более одного слова с помощью getline
    /*const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter name\n";
    cin.getline(name, ArSize);
    cout << "Dessert:\n";
    cin.getline(dessert, ArSize);
    cout << dessert << " for " << name << endl;*/

    //Listing 4.5
    //чтение более одного слова с помощью get()
    /*const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter name\n";
    cin.get(name, ArSize).get();
    cout << "Dessert:\n";
    cin.get(dessert, ArSize).get();
    cout << dessert << " for " << name << endl;*/

    //Listing 4.6
    //строковый ввод после числового
    /*int year;
    (cin >> year).get();
    char address[80];
    cin.getline(address, 80);
    cout << year << endl;
    cout << address << endl;*/

    //Listing 4.7
    //использование класса —++ string
    /*char charr1[20];
    char charr2[20] = "jaguar";
    string str1;
    string str2 = "panther";
    cin >> charr1;
    cin >> str1;
    cout << charr1 << " " << charr2 << " "
         << str1 << " " << str2 << endl;
    cout << charr2 << " 3d element " << charr2[2] << endl;
    cout << str2 << " 3d element " << str2[2] << endl;*/



    return 0;
}








