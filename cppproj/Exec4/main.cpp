#include <iostream>
#include <clocale>
#include <cstring>      //библиотека обработки строк в стиле С
#include <string>       //обеспечение доступа к классу string

using namespace std;

struct inflatable
{
    string name;
    float volume;
    double price;
};

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
    //использование класса С++ string
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

    //Listing 4.8
    //присваивание, сложение, добавление
    /*string s1 = "penguin";
    string s2, s3;
    s2 = s1;
    cout << s1 << " " << s2 << endl;
    s2 = "buzzard";
    cout << s2 << endl;
    s3 = s1 + s2;
    cout << s3 << endl;
    s1 += s2;
    cout << s1 << endl;
    s2 += " for a day";
    cout << s2 << endl;*/

    //Listing 4.9
    //дополнительные ср-ва класса string
    /*char charr1[20];
    char charr2[20] = "jaguar";
    string str1;
    string str2 = "panther";
    str1 = str2;
    strcpy(charr1, charr2);

    str1 += " paste";
    strcat(charr1, " juice");

    int len1 = str1.size();
    int len2 = strlen(charr1);

    cout << "str1 = " << str1 << len1 << endl;
    cout << "charr1 = " << charr1 << len2 << endl;*/

    //Listing 4.10
    //ввод строки с пробелами
    /*char charr[20];
    string str;
    cout << strlen(charr) << endl;
    cout << str.size() << endl;
    cin.getline(charr, 20);
    cout << charr << endl;
    getline(cin, str);
    cout << str << endl;
    cout << strlen(charr) << endl;
    cout << str.size() << endl;*/

    //Listing 4.11
    //простая структура
    /*inflatable guest { "Glorious Gloria", 1.88, 29.99 };
    inflatable pal { "Audacious Arthur", 3.12, 32.99 };
    inflatable choice;

    choice = guest;
    cout << guest.name << endl;
    cout << pal.name << endl;
    cout << choice.name << endl;
    cout << guest.price + pal.price << endl;*/

    //Listing 4.13
    //массив структур
    /*inflatable guests[2] =
    {
        {"Glorious Gloria", 1.88, 29.99},
        {"Audacious Arthur", 3.12, 32.99}
    };

    cout << guests[0].name << endl;
    cout << guests[1].name << endl;
    cout << guests[0].price + guests[1].price << endl;

    cout << &guests[0].name << endl;*/

    /*int val = 6;
    int *p_val;

    p_val = &val;

    cout << val << endl;
    *p_val += 1;
    cout << *p_val << endl;
    cout << val << endl;*/

    //Listing 4.17
    //использование операции new
    /*int nights = 1001;
    int *pt = new int;
    *pt = 1001;

    cout << nights << " " << &nights << endl;
    cout << *pt << " " << pt << endl;

    double *pd = new double;
    *pd = 10000001.0;
    cout << *pd << " " << pd << " " << &pd << endl;

    cout << sizeof(pt) << " " << sizeof(*pt) << endl;
    cout << sizeof(pd) << " " << sizeof(*pd) << endl;*/

    //Listing 4.18
    //использование операции new для массивов
    /*double *p3 = new double [3];
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;

    cout << p3[1] << endl;
    p3 += 1;
    cout << p3[0] << " " << p3[1] << endl;
    p3 -= 1;
    cout << p3[0] << " " << p3[1] << endl;
    delete [] p3;*/

    //Listing 4.19
    //сложение указателей
    /*double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};

    double *pw = wages;
    short *ps = &stacks[0];

    cout << pw << " " << *pw << endl;
    pw += 1;
    cout << pw << " " << *pw << endl;
    cout << ps << " " << *ps << endl;
    ps += 1;
    cout << ps << " " << *ps << endl;

    cout << stacks[0] << " "
         << stacks[1] << " "
         << stacks[2] << endl;

    cout << *stacks << " "
         << *(stacks + 1) << " "
         << *(stacks + 2) << endl;

    cout << sizeof(wages) << endl;
    cout << sizeof(pw) << endl;*/

    //Listing 4.20
    //использование указателей на строки
    char animal[20] = "bear";
    const char *bird = "wren";
    char *ps;
    cout << animal << " " << bird << endl;



    return 0;
}








