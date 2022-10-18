#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cctype>



using namespace std;
template <typename T>
void swapr(T & a, T &b);
void swapp(int *p, int *q);
void swapv(int a, int b);

template <typename T>   //шаблон
void Swap(T &a, T &b);
struct job
{
    char name[40];
    double salary;
    int floor;
};
template <> void Swap<job>(job &j1, job &j2); //явная специализация
void Show(job &j);

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
//char *left(const char *str, int n = 1);



struct debts
{
    char name[50];
    double amount;
};

template <class T>
T lesser(T a, T b)
{
    return a < b ? a:b;
}

int lesser (int a, int b)
{
    a = a < 0 ? -a:a;
    b = b < 0 ? -b:b;
    return a < b ? a:b;
}

struct CandyBar
{
    string name;
    double weight;
    int ccal;
};

struct stringy {
    char * str;     //указывает на строку
    int ct;         //длина строки
};

void set(stringy &stg, char *str);
void show(const stringy &str, int times = 1);
void show(const char *str, int times = 1);

void setStructCandy(CandyBar &candy, string nm = "Millenium Munch",
          const double w = 2.85, const int ccl = 350);
void showStructCandy(const CandyBar &candy);

void stringToUpper(string & str);

void showStr(const char *str, int n = 0);

template <typename T>
T max5(const T *arr);

template <typename T>
T maxn(T *arr, int n);

template <> char* maxn <char* > (char** str, int n);       //явная специализация

template <typename T>   //A
T SumArray(T arr[], int n);

template <typename T>   //B
T SumArray(T *arr[], int n);

int main()
{
    setlocale(LC_ALL, "Russian");
    //Listing 8.4
    //обмен значениями с помощью ссылок и указателей
    /*int wallet1 = 300;
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
    cout << " wallet2 = $" << wallet2 << endl;*/

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
    //строковая ф-я с аргументом по умолчанию
    /*char sample[ArSize];
    cout << "Enter a string: ";
    cin.get(sample, ArSize);
    char *ps = left(sample, 4);
    cout << ps << endl;
    delete [] ps;
    ps = left(sample);
    cout << ps << endl;
    delete [] ps;*/

    //Listing 8.13
    //Специализация переопределяет шаблон
    /*cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);
    cout << "Now i, j = " << i << ", " << j << ".\n";

    job Sue = {"Suesan", 73000.60, 7};
    job Sidney = {"Sidney", 78020.60, 9};
    cout << "Before job swapping:\n";
    Show(Sue);
    Show(Sidney);
    Swap(Sue, Sidney);
    cout << "After job swapping:\n";
    Show(Sue);
    Show(Sidney);*/

    //Listing 8.14
    //Перегрузка шаблонов
    /*int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };

    double *pd[3];

    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;
    cout << "Listing counts of things:\n";
    ShowArray(things, 6);

    ShowArray(pd, 3);*/

    //Listing 8.15
    //Выбор шаблона
    /*int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    cout << lesser(m,n) << endl;        //2
    cout << lesser(x,y) << endl;        //1
    cout << lesser <> (m,n) << endl;    // <> указывает использовать шаблон
    cout << lesser <int> (x,y) << endl;*/ // //-// и преобразует double -> int


    //Упражнение 1
    //showStr("Hi");
    //showStr("Ghg");
    //showStr("Wy?", 5);

    //Упражнение 2
    //CandyBar candy;
    //setStructCandy(candy);
    //showStructCandy(candy);

    //Упражнение 3
    //string str = "hi";
    //stringToUpper(str);

    //Упражнение 4
    //stringy beany;
    //char testing[] = "Reality isn't what it used too be.";
    //set(beany, testing);
    //show(beany);
    //show(beany, 2);
    //testing[0] = 'D';
    //testing[1] = 'u';
    //show(testing);
    //show(testing, 2);

    //Упражнение 5
    /*int arr_int[5] = {500, 10, 15, 45, 20};
    double arr_doub[5] = {5.5, 10.0, 15.3, 45.56, 20.895};

    cout << max5(arr_int) << "\n";
    cout << max5(arr_doub);*/

    //Упражнение 6
    /*int arr_int[6] = {500, 10, 15, 45, 20, 1024};
    double arr_doub[4] = {500.5, 100.0, 15.3, 45.56};

    char *arr_char[3] = {
        "hello",
        "my",
        "babyb",
    };

    cout << maxn(arr_int, 6) << "\n";
    cout << maxn(arr_doub, 5) << "\n";
    cout << maxn(arr_char, 3);*/

    //Упражнение 7
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };

    double *pd[3];

    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;
    cout << "Listing counts of things:\n";
    cout << SumArray(things, 6) << endl;

    cout << SumArray(pd, 3);


    return 0;
}

template <typename T>
T SumArray(T arr[], int n)
{
    T sum = 0;
    cout << "Template A\n";
    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

template <typename T>
T SumArray(T * arr[], int n)
{
    T sum = 0;
    cout << "Template B\n";
    for (int i = 0; i < n; i++)
        sum += *arr[i];
    return sum;
}

template <> char* maxn <char* > (char** str, int n)
{
    //cout << str[0];
    char * temp = str[0];
    int len = strlen(str[0]);
    for (int i = 1; i < n; i++)
        if (strlen(str[i]) > len)
            temp = str[i];
    return temp;
}

template <typename T>
T maxn(T *arr, int n)
{
    T max = arr[0];
    if (n > 0)
    {
        for (int i = 1; i < n; i++)
            if (arr[i] > max)
                max = arr[i];
        return max;
    }
    else
    {
        cout << "Error two argument\n";
        max = -1;
        return max;
    }
}

template <typename T>
T max5(const T *arr)
{
    T max = arr[0];
    for (int i = 1; i < 5; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void show(const stringy &str, int times)
{
    if (times > 0)
        for (int i = 0; i < times; i++)
            cout << str.str << " " << str.ct << "\n";
    else
        return;
}

void show(const char *str, int times)
{
    if (times > 0)
        for (int i = 0; i < times; i++)
            cout << str << "\n";
    else
        return;
}

void set(stringy &stg, char *str)
{
    stg.str = str;
    stg.ct = strlen(str);
}

void stringToUpper(string &str)
{
    for (int i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
    cout << str;
}

void setStructCandy(CandyBar &candy, string nm, const double w, const int ccl)
{
    candy.name = nm;
    candy.weight = w;
    candy.ccal = ccl;
}

void showStructCandy(const CandyBar &candy)
{
    cout << candy.name << "\n"
         << candy.weight << "\n"
         << candy.ccal << "\n";
}

void showStr(const char *str, int n)
{
    static int sum = 0;
    if (n != 0)
        for (int i = 0; i < sum; i ++)
            cout << str << endl;
    else cout << str << endl;
    sum++;
}



/*Эта функция возвращает указатель на новую строку,
состоящую из первых n символов строки str*/
/*char *left(const char *str, int n)
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
}*/

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

char *left(const char *str, int n)
{
    if (n < 0)
        n=0;
    char *p = new char[n+1];
    int i;
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i];
    while (i <= n)
        p[i++] = '\0';
    return p;
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
void Swap(T &a, T &b)       //Обобщенная версия
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <> void Swap<job>(job &j1, job &j2)       //Специализация
{
    double t1;
    int t2;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

void Show(job &j)
{
    cout << j.name << ": $" << j.salary
         << " on floor " << j.floor << endl;
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
