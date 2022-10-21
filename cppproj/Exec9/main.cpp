#include <iostream>
#include "coordin.h"
#include <new>

const int BUF = 512;
const int N = 5;
char buffer[BUF];

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

    //Listing 9.11
    //Пример пространства имен


    return 0;
}












