#include <iostream>
#include <cmath>
#include <array>
#include <string>
#include <locale>

using namespace std;

struct travel_time
{
    int hours;
    int mins;
};

struct rect
{
    double x;
    double y;
};

struct polar
{
    double distance;
    double angle;
};

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show_box(box b);
box * box_volume(box *b);

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

const int ArSize = 8;
const int Mins_per_hr = 60;
const int SIZE = 5;
const int Seasons = 4;
const int Len = 66;
const int Divs = 6;
const std::array< std::string, Seasons> Snames =
{"Spring", "Summer", "Fall", "Winter"};

void subdivide(char ar[], int low, int high, int level);
void fill(std::array<double, Seasons> *pa);
void show(std::array<double, Seasons> da);
void display(const string sa[], int n);
void countdown(int n);
travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);
int sum_arr(int arr[], int n);
double average(double, double);

unsigned int c_in_str(const char *str, char ch);
char *buildstr(char ch, int n);

double betsy(int);
double pam(int);
void estimate(int lines, double (*pf)(int));

const double *f1(const double ar[], int n);
const double *f2(const double [], int);
const double *f3(const double *, int);

int setArray(int ar[], int size);
double aver(const int ar[], int size);
void showArray(const int ar[], int size);

long double probability(unsigned numbers, unsigned picks);

long int factorial(int n);

int Fill_array(double ar[], int size);
void Show_array(const double ar[], int size);
void Reverse_array(double *ar, int size);

double *fill_array(double *begin, double *end);
void show_array(const double *begin, const double *end);
void revalue(double r, double *begin, double *end);

int main()
{
    setlocale(LC_ALL, "Russian");
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
    /*int times;
    char ch;
    cin >> ch;
    cin >> times;
    char *ps = buildstr(ch, times);
    cout << ps << endl;
    delete [] ps;*/

    //Listing 7.11
    //использование структур с функциями
    /*travel_time day1 = {5, 45};
    travel_time day2 = {4, 55};
    travel_time trip = sum(day1, day2);
    cout << "total: ";
    show_time(trip);
    travel_time day3 = {4, 32};
    cout << "total: ";
    show_time(sum(trip, day3));*/

    //Listing 7.12
    //функции с аргументами-структурами
    /*rect rplace;
    polar pplace;
    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y) {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
    };
    cout << "Done!\n";*/

    //Listing 7.14
    //обработка массива объектов string
    /*string list[SIZE];
    cout << "Enter your astronomical sights: \n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << i+1 << ": ";
        getline(cin, list[i]);
    }

    cout << "Your list:\n";
    display(list, SIZE);*/

    //Listing 7.15
    //функции с объектами array
    array<double, Seasons> expenses;
    fill(&expenses);
    show(expenses);

    //Listing 7.16
    //использование рекурсии
    //countdown(4);

    //Listing 7.17
    //использование рекурсии для разделения линейки
    /*char ruler[Len];
    int i;
    for (i = 1; i < Len - 2; i++)
        ruler[i] = ' ';
    ruler[Len - 1] = '\0';
    int max = Len-2;
    int min = 0;
    ruler[min] = ruler[max] = '|';
    cout << ruler <<endl;
    for (i = 1; i <= Divs; i++)
    {
        subdivide(ruler, min, max, i);
        cout << ruler << endl;
        for (int j = 1; j < Len-2; j++)
            ruler[j] = ' ';
    }*/

    //Listing 7.18
    //указатели на функции
    /*int code;
    cout << "Enter lines: ";
    cin >> code;
    cout << "Betsy's estimate: ";
    estimate(code, betsy);
    cout << "\nPam's estimate: ";
    estimate(code, pam);
    cout << endl;*/

    //Listing 7.19
    //массив указателей на функции
    //double av[3] = {1112.3, 1542.6, 2227.9};

    //указатель на функцию
    /*const double *(*p1)(const double *, int) = f1;
    auto p2 = f2;

    cout << "Address value\n";
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl;

    const double *(*pa[3])(const double *, int) =
    {f1, f2, f3};

    auto pb = pa; //pb - указатель на первый эл-т pa
    for (int i = 0;  i < 3; i++)
        cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;

    for (int i = 0; i < 3; i++)
        cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;

    //Указатель на массив указателей на ф-и
    auto pc = &pa;
    cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
    const double *(*(*pd)[3])(const double *, int) = &pa;
    const double *pdb = (*pd)[1](av, 3);
    cout << pdb << ": " << *pdb << endl;
    cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;*/

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

    //Упражнение 2
    /*cout << "Введите до 10 результатов игры в гольф, для прекращения ввода "
            "нажмите q\n";
    const int size = 10;
    int golf[size];
    int nSz = setArray(golf, size);
    cout << nSz << endl;
    showArray(golf, nSz);
    cout << aver(golf, nSz) << endl;*/

    //Упражнение 3
    /*box b = {"box", 101.2, 45.8, 5.3, 456.8};
    show_box(b);
    box_volume(&b);
    show_box(b);*/

    //Упражнение 4
    /*double total, choices, tot_shans = 1.0;
    cout << "Введите общее количество номеров и количество номеров, которые нужно угадать\n";
    while ((cin >> total >> choices) && choices <= total) {
        tot_shans = tot_shans * probability(total, choices);
        //cout << probability(total, choices) << endl;
        cout << "\nМеганомер ()q для завершения: ";
    };

    cout << "Вероятность выигрыша: " << tot_shans << endl;*/

    //Упражнение 5
    /*int num;
    cout << "Введите число: ";
    cin >> num;
    cout << num << "! = " << factorial(num) << endl;*/

    //Упражнение 6
    /*const int size = 5;
    double ar[size];

    int Sz = Fill_array(ar, size);
    //cout << Sz;
    Show_array(ar, Sz);
    Reverse_array(ar, Sz);
    cout << endl;
    Show_array(ar, Sz);*/

    //Упражнение 7
    /*const int Max = 5;
    double properties[Max] = {1, 2, 3, 4, 5};
    double *end;
    end = fill_array(properties, properties + Max);
    show_array(properties, end) ;
    if ( properties  <  end )
    {
        cout  <<  " Enter  revaluation  factor :" ;
        double  factor;
        while  (!(cin >> factor ))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout  <<  "Bad input; Please enter а numЬer : ";  // повторный  запрос  на  ввод числа
        }
        revalue (factor, properties,  end) ;
        show_array (properties, end) ;
    }

    cin.get();
    cin.get();*/

    //Упражнение 8


    return 0;
}

double *fill_array(double *begin, double *end)
{
    double *k;
    int i = 0;
    for (k = begin; k < end; k++)
    {
        cout << "#" << ++i << " = ";
        cin >> *k;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input\n";
            break;
        }
        else if (*k < 0)
            break;
    }

    return k;
}

void show_array(const double *begin, const double *end)
{
    while (begin < end) {
        cout << *begin << " ";
        begin++;
    }
}

void revalue(double r, double *begin, double *end)
{
    while (begin < end) {
        *begin *= r;
        begin++;
    }
}

int Fill_array(double ar[], int size)
{
    int i;
    cout << "Введите элементы массива:\n";
    for (i = 0; i < size; i++)
    {
        cout << "ar[" << i << "] = ";
        cin >> ar[i];

        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            return i;
        }
    }

    return i;
}

void Show_array(const double ar[], int size)
{
    for (int i = 0; i < size; i++)
        cout << ar[i] << " ";
}

void Reverse_array(double *ar, int size)
{
    double temp;
    for (int i = 0, j = size-1; i < size/2; i++, j--)
    {
        temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
    }
}

long int factorial(int n)
{
    if (n > 1)
        return n * factorial(n-1);
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned p;
    for (n = numbers, p = picks; p > 0; n--, p--)
        result *= n/p;
    return result;
}

int setArray(int ar[], int size)
{
    using namespace std;
    int temp;
    int i;

    cout << "Для прекращения ввода введите отрицательное значение\n";

    for (i = 0; i < size; i++)
    {        
        cout << "#" << (i+1) << ": ";

        cin >> temp;

        if (!cin)
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            break;
        }
        else if(temp < 0)
            break;
        ar[i] = temp;
    }
    return i;
}

double aver(const int ar[], int size)
{
    double total = 0.0;
    for (int i = 0; i < size; i++)
        total += ar[i] ;
    return total/size;
}

void showArray(const int ar[], int size)
{
    for (int i = 0; i < size; i++)
        cout << ar[i] << " ";
    cout << endl;
}

const double *f1(const double ar[], int n)
{
    return ar;
}

const double *f2(const double ar[], int n)
{
    return ar + 1;
}

const double *f3(const double *ar, int n)
{
    return ar + 2;
}

double betsy(int lns)
{
    return 0.05 * lns;
}

double pam(int lns)
{
    return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int))
{
    cout << lines << " " << (*pf)(lines);
}

void subdivide(char ar[], int low, int high, int level)
{
    if (level == 0)
        return;
    int mid = (high + low) / 2;
    ar[mid] = '|';
    subdivide(ar, low, mid, level-1);
    subdivide(ar, mid, high, level-1);
}

void countdown(int n)
{
    cout << "Counting down ... " << n << " at " << &n << endl;
    if (n > 0)
        countdown(n-1);
    cout << n << " at " << &n << ": kaboom!\n" ;
}

void fill(std::array<double, Seasons> *pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Enter "<< Snames[i] << " expenses: ";
        cin >> (*pa)[i];
    }
}

void show(std::array<double, Seasons> da)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total expemses: $" << total << endl;
}

void display(const string sa[], int n)
{
    for (int i = 0; i < n; i++)
        cout << i+1 << ": " << sa[i] << endl;
}

void show_box(box b)
{
    cout << b.maker << "\t" << b.height << "\n\t" <<
            b.length << "\n\t" << b.width << "\n\t" <<
            b.volume << endl;
}

box * box_volume(box *b)
{
    b->volume = b->height * b->length * b->width;
    return b;
}

polar rect_to_polar(rect xypos)
{
    polar answer;
    answer.distance = sqrt(xypos.x * xypos.x +
                           xypos.y * xypos.y);
    answer.angle = atan2(xypos.y, xypos.x);
    return answer;
}

void show_polar(polar dapos)
{
    const double Rad_to_deg = 57.29577951;
    cout << dapos.distance << " " << dapos.angle * Rad_to_deg << endl;
}

travel_time sum(travel_time t1, travel_time t2)
{
    travel_time time;
    time.hours = t1.hours + t2.hours + (int)(t1.mins + t2.mins)/Mins_per_hr;
    time.mins = (t1.mins + t2.mins) % Mins_per_hr;
    return time;
}

void show_time(travel_time t)
{
    cout << t.hours << " " << t.mins << endl;
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
