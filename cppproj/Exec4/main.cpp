#include <iostream>
#include <clocale>
#include <cstring>      //библиотека обработки строк в стиле С
#include <string>       //обеспечение доступа к классу string
#include <vector>
#include <array>
using namespace std;

/*struct inflatable
{
    string name;
    float volume;
    double price;
};*/

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

struct antarctica_years_end
{
    int year;
};

char *getname(void);

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
    //cin.getline(address, 80);
    cin >> address;
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
    /*char animal[20] = "bear";
    const char *bird = "wren";
    char *ps;
    cout << animal << " " << bird << endl;
    cin >> animal;
    ps = animal;
    cout << ps << endl;
    cout << animal << " " << (int *) animal << endl;
    cout << ps << " " << (int *) ps << endl;
    ps = new char[strlen(animal)+1];
    strcpy(ps, animal);
    cout << animal << " " << (int *) animal << endl;
    cout << ps << " " << (int *) ps << endl;
    delete [] ps;*/

    //Listing 4.21
    //использование new со структурой
    /*inflatable *ps = new inflatable;
    cin.get(ps->name, 20);
    cin >> (*ps).volume;
    cin >> ps->price;
    cout << (*ps).name << " "
         << ps->volume << " "
         << ps->price << endl;

    delete ps;*/

    //Listing 4.22
    //использование операции delete
    /*char *name;
    name = getname();
    cout << name << " " << (int*) name << endl;
    delete [] name;
    name = getname();
    cout << name << " " << (int*) name << endl;
    delete [] name;*/

    //Listing 4.23
    //некоторые комбинации типов
    /*antarctica_years_end s01, s02, s03;
    s01.year = 1998;
    antarctica_years_end *pa = &s02;
    pa->year = 1999;
    antarctica_years_end trio[3];
    trio[0].year = 2003;
    cout << trio[0].year << endl;
    const antarctica_years_end *arp[3] = {&s01, &s02, &s03};
    cout << arp[1]->year << endl;
    const antarctica_years_end **ppa = arp;
    //auto ppb = arp;
    const antarctica_years_end **ppb = arp;
    cout << (*ppa)->year << endl;
    cout << (*(ppb+1))->year << endl;*/

    //Listing 4.24
    //вариации массивов
    /*double a1[4] = {12.0, 2.3, 8.4, 1.0};
    vector<double> a2(4);
    a2[0] = 1.0/3.0;
    a2[1] = 1.0/5.0;
    a2[2] = 1.0/7.0;
    a2[3] = 1.0/9.0;

    array<double, 4> a3 = {15.0, 5.3, 3.4, 1.8};
    array<double, 4> a4;
    a4 = a3;

    cout << "a1: " << a1[0] << " " << a1[1] << " " << a1[2] << " " << a1[3] << endl;
    cout << "a2: " << a2[0] << " " << a2[1] << " " << a2[2] << " " << a2[3] << endl;
    cout << "a3: " << a3[0] << " " << a3[1] << " " << a3[2] << " " << a3[3] << endl;
    cout << "a4: " << a4[0] << " " << a4[1] << " " << a4[2] << " " << a4[3] << endl;

    a1[-2] = 20.2;
    cout << a1[-2] << " " << &a1[-2] << endl;*/

    cout  <<  ( int  * )   "Home  of  the  j olly bytes " ;


    return 0;
}

char * getname()
{
    char temp[80];
    cout << "lname: ";
    cin >> temp;
    char *pn = new char[strlen(temp)+1];
    strcpy(pn, temp);
    return pn;
}








