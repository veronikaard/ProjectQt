#include <iostream>
//#include "time.h"
#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <locale>


#include "vect.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    //Listing 11.0 - 11.6


    /*Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;
    Time diff;
    Time mult;

    cout << "planning time = ";
    planning.Show();

    cout << "coding time = ";
    coding.Show();

    cout << "fixing time = ";
    fixing.Show();

    total = coding + fixing;
    cout << "coding + fixing = ";
    total.Show();

    diff = fixing - coding;
    diff.Show();

    mult = 2 * coding;
    mult.Show();

    mult = coding * 9;
    mult.Show();*/

    /*Time trip(10, 20);
    //trip.Show();
    cout << "Time: " << trip;*/

    //Listing 11.15 Vector
    using VECTOR::Vector;
    //using std::cout;
    //using std::endl;
    //using std::cin;
    using namespace std;

    //srand(time(0));

    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;

    double target;
    double dstep;

    cout << "Введите заданное расстояние, q для завершения: ";

    while(cin >> target)
    {
        cout << "Введите длину шага: ";
        if (!(cin >> dstep))
            break;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }

        cout << "После " << steps << " шагов объект имеет следующее положение: ";
        cout << result << endl;
        result.polar_mode();
        cout << "или " << result << endl;
        cout << "Среднее расстояние на один метр = " << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Введите заданное расстояние, q для завершения: ";
    }

    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;

    return 0;
}
