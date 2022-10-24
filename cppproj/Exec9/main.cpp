#include <iostream>
#include "coordin.h"
#include <string>
#include <cstring>
#include <new>
#include "namesp.h"
#include "golf.h"
#include <ctype.h>
#include <stdlib.h>
#include <cstdlib>
#include "sales.h"

void other(void);
void another(void);

const int BUF = 512;
const int N = 5;
char buffer[BUF];

const int ArSize = 10;
void strcount(const char *str);
void strcount(std::string str);

struct chaff
{
    char dross[20];
    int slag;
};

char buffer1[50];
char buffer2[BUF];
using namespace std;

int main()
{
    //Listing 9.3
    /*rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit):";
    }
    cout << "Done!\n";*/

    //Listing 9.9
    //static local
    /*using namespace std;
    char input[ArSize];
    char next;
    cout << "Enter a line: \n";
    cin.get(input, ArSize);
    while (cin)
    {
        cin.get(next);
        while (next != '\n')
            cin.get(next);
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        cin.get(input, ArSize);
    }
    cout << "Bye\n"*/

    //Listing 9.10
    //Использование операции new с размещением
    /*double *pd1, *pd2;
    int i;

    pd1 = new double[N];            //использование кучи
    pd2 = new (buffer) double[N];   //использование массива buffer

    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 20.0 *i;
    cout << "Memory addresses:\n heap: " << pd1 << " static: "
         << (void *) buffer << endl;
    cout << "Memory contens:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    //2
    double *pd3, *pd4;
    pd3 = new double[N];            //использование кучи
    pd4 = new (buffer) double[N];   //использование массива buffer

    for (i = 0; i < N; i++)
        pd4[i] = pd3[i] = 1000 + 40.0 *i;
    cout << "Memory addresses:\n heap: " << pd3 << " static: "
         << (void *) buffer << endl;
    cout << "Memory contens:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd3[i] << " at " << &pd3[i] << "; ";
        cout << pd4[i] << " at " << &pd4[i] << endl;
    }

    //3
    delete [] pd1;
    pd1 = new double[N];            //использование кучи
    pd2 = new (buffer + N * sizeof(double)) double[N];   //использование массива buffer

    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 60.0 *i;
    cout << "Memory addresses:\n heap: " << pd1 << " static: "
         << (void *) buffer << endl;
    cout << "Memory contens:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    delete [] pd1;
    delete [] pd3;*/

    //Listing 9.11 - 9.13
    //Пример пространства имен
    /*using debts::Debt;
    using debts::showDebt;
    Debt golf = {{"Denny", "Goatsderf"}, 120.0};
    showDebt(golf);
    other();
    another();*/

    //Упражнение 1
    /*golf ann;
    setgolf(ann, "Ann Birdfree", 24);
    showgolf(ann);

    golf andy;
    std::cout << setgolf(andy) << std::endl;
    showgolf(andy);

    handycap(andy, 123);
    showgolf(andy);*/

    //Упражнение 2
    /*using namespace std;
    std::string str;
    cout << "Enter a line: \n";
    getline(cin, str);
    while (cin)
    {
        strcount(str);
        if (str == "")
            break;
        cout << "Enter next line (empty line to quit):\n";
        getline(cin, str);
    }
    cout << "Bye\n";*/

    //Упражнение 3
     /*chaff *p1, *p2;
     p1 = new chaff; //помещение структуры в кучу
     p2 = new (buffer2) chaff; //помещение структуры в область buffer2*/

    /*chaff *p[2];
    chaff *a[2];
    a[0] = new chaff;
    a[1] = new chaff;*/

    //использование статического массива
    /*p[0] = new (buffer2) chaff;
    p[1] = new (buffer2 + sizeof(chaff)) chaff;

    strcpy( p[0]->dross, "Hikklkd");
    p[0]->slag = 123;

    strcpy(p[1]->dross, "GHJHH");
    p[1]->slag = 547;

    for (int i = 0; i < 2; i++)
        cout << p[i]->dross  << " " << p[i]->slag << endl;

    strcpy( a[0]->dross, "jhhfjh");
    a[0]->slag = 200;
    strcpy(a[1]->dross, "wwwrt");
    a[1]->slag = 100;

    //использование операции new для выделения памяти под буфер
    chaff *buffer = new chaff[2];
    for (int i = 0; i < 2; i++)
    {
        strcpy(buffer[i].dross, "hi");
        buffer[i].slag = i;
        //buffer[i].slag = "#" + std::to_string(i);
        cout << buffer[i].dross << " " << buffer[i].slag << endl;
    }*/

    //Упражнение 4
    using SALES::Sales;
    Sales s1;
    Sales s2;

    const double ar[4] = {5.0, 3.0, 1.5, 6.8};

    //SALES::setSales(s1, ar, 2);
    //SALES::showSales(s1);

    SALES::setSales(s2);
    SALES::showSales(s2);


    return 0;
}

void strcount(std::string str)
{
    using namespace std;
    static int total = 0;
    int count = 0;
    cout << "\"" << str << "\" contains ";
    count = str.size();
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}

void strcount(const char *str)
{
    using namespace std;
    static int total = 0;
    int count = 0;
    cout << "\"" << str << "\" contains ";
    while (*str++)
        count++;
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}

void other()
{
    using std::cout;
    using std::endl;
    using namespace debts;
    Person dg = {"Doodles", "Glister"};
    showPerson(dg);
    cout << endl;
    Debt zippy[3];
    int i;
    for (i = 0; i < 3; i++)
        getDebt(zippy[i]);
    for (i = 0; i < 3; i++)
        showDebt(zippy[i]);
    cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
}

void another()
{
    using pers::Person;
    Person collector = {"Milo", "Rihhtsift"};
    pers::showPerson(collector);
    std::cout << std::endl;
}











