#include <iostream>
#include <ctime>

using namespace std;
const int Cities = 5;
const int Years = 4;

int main()
{
    int x;

    //Listing 5.3
    //значения выражений
    /*cout << (x=100) << endl;
    cout << (x<3) << endl;
    cout << (x>3) << endl;
    cout.setf(ios_base::boolalpha);
    cout << (x<3) << endl;
    cout << (x>3) << endl;*/

    //Listing 5.8
    //использование блока
    /*double number;
    double sum = 0.0;
    for (int i = 1; i <=5; i++)
    {
        cout << "Value " << i << ": ";
        cin >> number;
        sum += number;
    }

    cout << sum << " " << sum/5 << endl;*/

    //Listing 5.14
    //использование clock() в цикле временной задержки
    /*float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;
    cout << "starting\a\n";
    clock_t start = clock();
    while (clock() -  start < delay)
        ;
    cout << "done \a\n";*/

    //Listing 5.15
    //цикл с проверкой на выходе
    /*int n;
    do
    {
        cin >> n;
    }while (n != 7);*/

    //Listing 5.16
    //чтение символов в цикле while
    /*char ch;
    int count = 0;
    //cin >> ch;
    cin.get(ch);
    while (!cin.fail()) {
        cout << ch;
        ++count;
        //cin >> ch;
        cin.get(ch);
    }

    cout << endl << count << endl;*/

    //Listing 5.20
    //вложенные циклы и двумерный массив
    const char *cities[Cities] =
    {
        "Gribble City",
        "Gribbletown",
        "New Gribble",
        "san Gribble",
        "Gribble Vista"
    };

    int maxtemps[Years][Cities] =
    {
        {96, 100, 87,  101, 105},
        {96, 98, 91, 107, 104},
        {97, 101, 93, 108, 107},
        {98, 108, 95, 109, 108}
    };

    for (int city = 0; city < Cities; ++city)
    {
        cout << cities[city] << ":\t";
        for (int year = 0; year < Years; ++year)
            cout << maxtemps[year][city] << "\t";
        cout << endl;
    }

    return 0;
}










