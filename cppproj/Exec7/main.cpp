#include <iostream>
#include <cmath>

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

travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);
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
    box b = {"box", 101.2, 45.8, 5.3, 456.8};
    show_box(b);
    box_volume(&b);
    show_box(b);

    return 0;
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
