#include <iostream>
#include "stringbad.h"

using namespace std;

void callme1(StringBad &);  //Передача по ссылке
void callme2(StringBad);    //Передача по значению

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Начало\n" << endl;
    StringBad headline1("at Midnight");
    StringBad headline2("Lettuce");
    StringBad sports("for Dollars");

    cout << "headline1 = " << headline1 << endl;
    cout << "headline2 = " << headline2 << endl;
    cout << "sports = " << sports << endl;

    callme1(headline1);
    cout << "headline1 = " << headline1 << endl;

    callme2(headline2);
    cout << "headline2 = " << headline2 << endl;

    StringBad sailor = sports;
    cout << "sailor = " << sailor << endl;

    StringBad knot;
    knot = headline1;
    cout << "knot = " << knot << endl;

    return 0;
}

void callme1(StringBad &rsb)
{
    cout << "Строока, переданная по ссылке: ";
    cout << rsb << "\n";
}

void callme2(StringBad sp)
{
    cout << "Строка, переданная по значению: ";
    cout << sp << endl;
}
