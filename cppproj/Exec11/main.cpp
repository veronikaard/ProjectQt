#include <iostream>
#include "time.h"
#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <locale>
#include "stonewt.h"
#include "vect.h"
#include <fstream>
#include "complex0.h"

using std::cout;
using std::endl;
using std::cin;
void display(const Stonewt &st, int n);
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
    //using VECTOR::Vector;
    //using std::cout;
    //using std::endl;
    //using std::cin;
    //using namespace std;

    //srand(time(0));

    /*double direction;
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
        continue;*/

    //Автоматические преобразования и привидения типов в классах
    /*Stonewt blossom(132.5);
    Stonewt butter(10, 2);
    Stonewt buble;
    //buble = 19.6;

    blossom.show_lbs();
    blossom.show_stn();

    butter.show_lbs();
    butter.show_stn();

    buble.show_lbs();
    buble.show_stn();*/

    //Listing 11.18
    /*Stonewt incognito = 275;
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);

    incognito.show_stn();
    wolfe.show_stn();
    taft.show_lbs();

    incognito = 276.8;
    taft = 325;
    incognito.show_stn();
    taft.show_lbs();

    display(taft, 2);
    display(422, 2);*/

    /*Stonewt poppins(9, 2.8);
    double p_wt = poppins;
    poppins.show_stn();
    poppins.show_lbs();
    cout << p_wt << "\n";
    cout << int (poppins) << "\n";*/

    /*Stonewt jenny(9, 12);
    //Stonewt benny(12, 8);
    double benny  =148.2;
    Stonewt total;
    total = jenny + benny;*/

    //Вопросы для самоконтроля 1
    /*Stonewt iam(10, 8);
    iam.show_stn();
    Stonewt garry;
    garry = 2.0 * iam;
    garry.show_stn();*/

    //Вопросы для самоконтроля 7
    /*using VECTOR::Vector;
    Vector vect(4.2, 1.0);
    double v = vect;
    cout << v;*/

    //Упражнение 1
    /*using VECTOR::Vector;
    using namespace std;
    //srand(time(0));
    ofstream fout;               //создание дескриптора файла
    fout.open("thewalk.txt");   //Открываем файл
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;

    double target;  //заданное расстояние
    double dstep;   //длина шага

    cout << "Введите заданное расстояние, q для завершения: ";

    while(cin >> target)
    {
        cout << "Введите длину шага: ";
        if (!(cin >> dstep))
            break;
        fout << "Заданное расстояние: " << target << ", длина шага: " << dstep << endl;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            fout << steps << ": (x, y) = (" << step.xval() << "," << step.yval() << ")\n";
            steps++;
        }

        cout << "После " << steps << " шагов объект имеет следующее положение: ";
        cout << result;
        fout << "После " << steps << " шагов объект имеет следующее положение: ";
        fout << result;
        result.polar_mode();
        cout << "или " << result ;
        cout << "Среднее расстояние на один метр = " << result.magval()/steps << endl;
        fout << "или " << result ;
        fout << "Среднее расстояние на один метр = " << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Введите заданное расстояние, q для завершения: ";
    }

    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    fout.close();*/       //Закрываем файл

    //Упражнение 2
    /*using VECTOR::Vector;
    using namespace std;

    //srand(time(0));
    double direction;
    int N;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;

    double target;  //заданное расстояние
    double dstep;   //длина шага

    cout << "Введите количество попыток: ";
    cin >> N;
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
            //cout << direction << " " << dstep << " " << result.magval() << endl;
            steps++;

        }

        cout << "После " << steps << " шагов объект имеет следующее положение: ";
        cout << result;
        result.polar_mode();
        cout << "или " << result ;
        cout << "Среднее расстояние на один метр = " << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Введите заданное расстояние, q для завершения: ";
    }

    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;*/

    //Упражнение 3
    /*using VECTOR::Vector;
    using namespace std;

    //srand(time(0));
    double direction;
    int N;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;

    double target = 50;  //заданное расстояние
    double dstep = 2;   //длина шага

    double MaxSteps = 0.0;
    double MinSteps;
    double AverSteps = 0.0;

    cout << "Введите количество попыток: ";
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        if (i == 0) MinSteps = steps;
        if (steps > MaxSteps) MaxSteps = steps;
        if (steps < MinSteps) MinSteps = steps;
        AverSteps += steps/N;

        cout << "После " << steps << " шагов объект имеет следующее положение: ";
        cout << result;
        result.polar_mode();
        cout << "или " << result ;
        cout << "Среднее расстояние на один метр = " << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
    }

    cout << "Максимальное к-во шагов: " << MaxSteps << endl;
    cout << "Минимальное к-во шагов: " << MinSteps << endl;
    cout << "Среднее к-во шагов: " << AverSteps << endl;


    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;*/

    //Упражнение 4
    /*Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;
    cout << "aida: " << aida << "tosca: " << tosca;
    temp = aida + tosca;
    cout << "aida + tosca = " << temp;
    cout << "aida - tosca = " << aida - tosca;
    cout << "aida * 1.17 = " << aida * 1.17;
    cout << "1.17 * aida = " << 1.17 * aida;*/

    //Упражнение 5
    /*Stonewt blossom(132.5);
    Stonewt butter(10, 2);
    blossom.SetState(blossom.pouFlo);
    butter.SetState(blossom.pouFlo);
    cout << "blossom =  " << blossom;
    cout << "butter =  " << butter;
    cout << "butter - blossom = " << butter - blossom;
    cout << "butter + blossom = " << butter + blossom;
    cout << "butter * 5.0 = " << butter * 5.0;
    cout << "5.0 * butter = " << 5.0 * butter;*/

    //Упражнение 6
    /*Stonewt array[6] =
    {
        {132.5}, {11.2}, {11.0}
    };

    Stonewt min;
    Stonewt max;

    double test;
    cout << "Введите фунты: ";
    for (int i = 3; i < 6; i++)
    {
        cin >> test;
        array[i] = Stonewt(test);
        cout << "Введите фунты: ";
    }

    cout << endl;
    min = max = array[0];
    int count = 0;
    for (int i = 0; i < 6; i++)
    {
        if (array[i] < min) min = array[i];
        if (array[i] > max) max = array[i];

        if (array[i] >= 11.0) count++;
        cout << array[i];
    }

    cout << "Min = " << min;
    cout << "Max = " << max;
    cout << "Кол-во эл-в, больших 11.0: " << count;*/

    //Упражнение 7
    Complex a(3.0, 4.0);
    Complex c;

    cout << "a = " << a << endl;
    cout << "c = " << c << endl;
    cout << "Введите комплексное число, q для завершения: ";

    while (cin >> c)
    {
        cout << "/nc = " << c << endl;
        cout << "Сопряженное число ~c = " << ~c << endl;
        cout << "a + c = " << a + c  << endl;
        cout << "a - c = " << a - c  << endl;
        cout << "a * c = " << a * c  << endl;
        cout << "c * 2 = " << c * 2  << endl;
        cout << "2 * c = " << 2 * c  << endl;
        cout << "Введите комплексное число, q для завершения: ";
    }

    return 0;
}

void display(const Stonewt &st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow! ";
        //st.show_stn();
    }

}
