#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

void simon(int n);
int stonetolb(int);
float lighttoastr(float);

void showstr1();
void showstr2();
void showtime(int, int);
int main()
{    
    setlocale(LC_ALL, "Rus");
    //Listing 2.1
    //выводит сообщение на экран
    /*cout << "Come up and C++ me some time." << endl;
    cout << "You won't regret it!" << endl;*/

    //Listing 2.2
    //использует и отображает переменную
    /*int carrots;
    carrots = 25;
    cout << "I have ";
    cout << carrots;
    cout << " carrots.";
    cout << endl;
    carrots = carrots -1;
    cout << "Crunch, crunch. Now I have " << carrots << " carrots." << endl;
*/
    //Listing 2.3
    //ввод и вывод
    /*int carrots;
    cout << "How many carrots do you have?" << endl;
    cin >> carrots;
    cout << "Here are two more. ";
    carrots = carrots +2;
    cout << "How you have " << carrots << " carrots." << endl;*/

    //Listing 2.4
    //использование ф-и sqrt()
    /*double area;
    cout << "Enter the floor area, in square feet, of your home: ";
    cin >> area;
    double side;
    side = sqrt(area);
    cout << "That's the equivalent of a square " << side
         << " feet to the side." << endl;
    cout << "How fascinating!" << endl;*/

    //Listing 2.5
    //определение собственной функции
    /*simon(3);
    cout << "Pick an integer: ";
    int count;
    cin >> count;
    simon(count);
    cout << "Done!" << endl;*/

    //Listing 2.6
    //преобразует стоуны в фунты
    /*int stone;
    cout << "Enter the weight in stone: ";
    cin >> stone;
    int pounds = stonetolb(stone);
    cout << stone << " stone = ";
    cout << pounds << " pounds." << endl;*/

    //Exec 1
    //cout << "Вероника: Енисейская, д.13, кв.67 " << endl;

    //Exec 2
    /*int farlongs;
    cout << "Введите расстояние в фарлонгах: " ;
    cin >> farlongs;
    cout << "Расстояние в ярдах: " << farlongs*220<< endl;*/

    //Exec 3
    /*showstr1();
    showstr1();
    showstr2();
    showstr2();*/

    //Exec 4
    /*int age;
    cout << "Введите свой возраст в годах: ";
    cin >> age;
    cout << "Вам " << age*12 << " месяцев." << endl;*/

    //Exec 5
    /*int temp;
    cout << "Please enter a Celsius value: ";
    cin >> temp;
    cout << temp << " degrees Celsius is " << 1.8 *temp +32
         << " degrees Fahrenheit.";*/

    //Exec 6
    /*float light_year;
    cout << "Enter the number of light years: ";
    cin >> light_year;
    cout << light_year << " light years = " << lighttoastr(light_year)
         << " astronomical units.";*/

    //Exec 7
    int hours, minutes;
    cout << "Enter the number of hours: ";
    cin >> hours;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    showtime(hours, minutes);

    return 0;
}

void showtime(int h, int m)
{
    cout << "Time: " << h << ":" << m;
}

float lighttoastr(float years)
{
    return years*63240;
}

void showstr1()
{
    cout << "Three blind mice" << endl;
}

void showstr2()
{
    cout << "See how they run" << endl;
}

int stonetolb(int sts)
{
    return 14*sts;
}

void simon(int n)
{
    cout << "Simon says touch your toes " << n << " times." << endl;
}

