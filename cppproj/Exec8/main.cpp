#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;
template <typename T>
void swapr(T & a, T &b);
void swapp(int *p, int *q);
void swapv(int a, int b);

struct free_throws
{
    string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & taget, const free_throws & source);

string version1(const string & s1, const string & s2);
const string & version2(string & s1, const string & s2);
const string & version3(string & s1, const string & s2);

void file_it(ostream &os, double fo, const double fe[], int n);
const int LIMIT = 5;

const int ArSize = 80;
char *left(const char *str, int n = 1);
unsigned long left(unsigned long num, unsigned ct);

int main()
{
    setlocale(LC_ALL, "Russian");
    //Listing 8.4
    //обмен значениями с помощью ссылок и указателей
    int wallet1 = 300;
    int wallet2 = 250;
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "References:\n";
    swapr(wallet1, wallet2);
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Pointers:\n";
    swapp(&wallet1, &wallet2);
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Value:\n";
    swapv(wallet1, wallet2);
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    //Listing 8.6
    //использование ссылок на структуру
    /*free_throws one = {"Ifelsa Branch", 13, 14};
    free_throws two = {"Andor Knott", 10, 16};
    free_throws three = {"Minnie Max", 7, 9};
    free_throws four = {"Whily Looper", 5, 9};
    free_throws five = {"Long Long", 6, 14};
    free_throws team = {"Throwgoods", 0, 0};

    free_throws dup;
    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);

    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    display(team);

    dup = accumulate(team, five);
    display(team);

    display(dup);
    set_pc(four);

    accumulate(dup, five) = four;
    display(dup);*/

    //Listing 8.7
    //использование ссылок на объект, различные решения
    /*string input;
    string copy;
    string result;
    cout << "Enter a string: ";
    getline(cin, input);
    copy = input;
    result = version1(input, "***");
    cout  << result << endl;
    cout << input << endl;

    result = version2(input, "###");
    cout  << result << endl;
    cout << input << endl;

    input = copy;
    result = version3(input, "@@@");
    cout  << result << endl;
    cout << input << endl;*/

    //Listing 8.8
    //функция с параметром ofstream &
    /*ofstream fout;
    const char * fn = "ep-data.txt";
    fout.open(fn);
    if (!fout.is_open())
    {
        cout << "Can't open " << fn << ". Bye.\n";
        exit(EXIT_FAILURE);
    }

    double objective;
    cout << "Enter focus distance objective: ";
    cin >> objective;
    double eps[LIMIT];
    cout << "Enter focus distance ocular:\n";
    for (int i = 0; i < LIMIT; i++)
    {
        cout << "Eyepiece #" << i+1 << ": ";
        cin >> eps[i];
    }

    file_it(fout, objective, eps, LIMIT);
    file_it(cout, objective, eps, LIMIT);*/

    //Listing 8.9
    /*char sample[ArSize];
    cout << "Enter a string:\n";
    cin.get(sample, ArSize);
    char *ps = left(sample, 4);
    cout << ps << endl;
    delete [] ps;       //освободить старую строку
    ps = left(sample);
    cout << ps << endl;
    delete [] ps;       //освободить новую строку*/

    //Listing 8.10
    /*char *trip = "Hawaii!!";
    unsigned long n = 12345678;
    int i;
    char *temp;
    for (i = 1; i < 10; i ++)
    {
        cout << left(n, i) << endl;
        temp = left(trip, i);
        cout << temp << endl;
        delete [] temp;
    }*/

    return 0;
}
/*Эта функция возвращает указатель на новую строку,
состоящую из первых n символов строки str*/
char *left(const char *str, int n)
{
    if (n < 0)
        n = 0;
    char *p = new char[n+1];
    int i;
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i];
    while (i <= n)
        p[i++] = '\0';
    return p;
}

unsigned long left(unsigned long num, unsigned ct)
{
    unsigned digits = 1;
    unsigned long n = num;
    if (ct == 0 || num == 0)
        return 0;
    while (n /= 10)
        digits++;
    if (digits > ct)
    {
        ct = digits - ct;
        while (ct--)
            num /= 10;
        return num;
    }
    else
        return num;
}

void file_it(ostream &os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed); //сохранение исходного состояния форматирования
    os.precision(0);
    os << "Focus distance objective " << fo << " mm\n" ;
    os.setf(ios::showpoint);
    os.precision(1);
    os.width(12);
    os << "f. l. eyepiece";
    os.width(15);
    os << "magnification" << endl; //коэффициент увеличения
    for (int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int (fo/fe[i]+0.5) << endl;
    }
    os.setf(initial); //восстановление исходного состояния форматированиия
}

string version1(const string & s1, const string & s2)
{
    string temp;
    temp = s2+s1+s2;
    return temp;
}

const string & version2(string & s1, const string & s2)
{
    s1 = s2+s1+s2;
    return s1;
}

const string & version3(string & s1, const string & s2)
{
    string temp;
    temp = s2+s1+s2;
    //возврат ссылки на локальную переменную небезопасен
    return temp;
}

free_throws & accumulate(free_throws &taget, const free_throws &source)
{
    taget.attempts += source.attempts;
    taget.made += source.made;
    set_pc(taget);
    return taget;
}

void set_pc(free_throws &ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0f * float(ft.made)/float(ft.attempts);
    else
        ft.percent = 0;
}

void display(const free_throws &ft)
{
    cout << "Name: " << ft.name << '\n';
    cout << "Made: " << ft.made << '\t';
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << '\n';
}

template <typename T>
void swapr(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

void swapp(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void swapv(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
