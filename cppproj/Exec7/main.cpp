#include <iostream>

using namespace std;
const int ArSize = 8;

int sum_arr(int arr[], int n);
double average(double, double);

unsigned int c_in_str(const char *str, char ch);
char *buildstr(char ch, int n);
int main()
{
    //Listing 7.5
    /*int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    cout << cookies << endl;
    cout << sizeof cookies << endl;

    int sum = sum_arr(cookies, ArSize);
    cout << "sum = " << sum << endl;*/

    //Listing 7.9
    //функция со строковым аргументом
    /*char mmm[15] = "minimum";
    char *wail = "ululate";
    unsigned int ms = c_in_str(mmm, 'm');
    unsigned int us = c_in_str(wail, 'u');

    cout << ms << endl;
    cout << us << endl;*/

    //Listing 7.10
    //функция, возвращающая указатель на char
    int times;
    char ch;
    cin >> ch;
    cin >> times;
    char *ps = buildstr(ch, times);
    cout << ps << endl;
    delete [] ps;

    //Упражнение 1
    /*double x, y;
    cout << "Enter 2 number: ";
    cin >> x;
    cin >> y;

    while (x != 0 && y != 0) {
        cout << "Enter 2 number: ";
        cin >> x;
        cin >> y;
        if (x > 0 && y > 0)
            cout << average(x, y) << endl;

    };

    cout << "Done!" << endl;*/
    return 0;
}

char *buildstr(char ch, int n)
{
    char *pstr = new char[n+1];
    pstr[n] = '\0';
    while (n-- > 0) {
        pstr[n] = ch;
    };
    return pstr;
}

unsigned int c_in_str(const char *str, char ch)
{
    unsigned int count = 0;
    while (*str) {
        if (*str == ch)
            count++;
        str++;
    }
    return count;
}

double average(double x, double y)
{
    return (2.0 * x * y)/(x + y);
}

int sum_arr(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    return total;
}
