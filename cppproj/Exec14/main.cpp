#include <iostream>
#include <locale>
#include <cstring>
//#include "studentc.h"
#include "studenti.h"
//#include "worker0.h"
#include "workermi.h"
#include "stack.h"
#include <cstdlib>
#include <ctime>
#include <arraytp.h>

using std::cin;
using std::cout;
using std::endl;
using std::strchr;

void set(Student &sa, int n);
const int pupils = 3;
const int quizzes = 5;

const int LIM = 4;
const int SIZE = 5;
const int Num = 10;

int main()
{
    setlocale(LC_ALL, "Rus");

    /*Student ada[pupils] =
    {
      Student(quizzes), Student(quizzes), Student(quizzes)
    };

    int i;
    for (i = 0; i < pupils; ++i)
        set(ada[i], quizzes);
    cout << "\nСписок студентов:\n";;
    for (i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;
    cout << "\nОценки:\n";
    for (i = 0; i < pupils; i++)
    {
        cout << endl << ada[i];
        cout << "средняя оценка: " << ada[i].Average() << endl;
    }*/

    /*Waiter bob("Bob Apple", 314L, 5);
    Singer bev("Beverly Hills", 522L, 3);
    Waiter w_temp;
    Singer s_temp;
    Worker *pw[LIM] = {&bob, &bev, &w_temp, &s_temp};
    int i;
    for (i = 2; i < LIM; i++)
        pw[i]->Set();
    for (i = 0; i < LIM; i++)
    {
        pw[i]->Show();
        cout << endl;
    }*/

    //Listing 14.12
    /*Worker *lolas[SIZE];
    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Введите категорию работника:\n"
             << "w - официант, s - певец, t - поющий официант, q - завершение\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Пожалуйста, введите w, s, t или q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice) {
        case 'w':
            lolas[ct] = new Waiter;
            break;
        case 's':
            lolas[ct] = new Singer;
            break;
        case 't':
            lolas[ct] = new SingingWaiter;
            break;
        default:
            break;
        }
        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nВывод списка работников:\n";
    int i;
    for (int i = 0; i < ct; i++)
    {
        cout << endl;
        lolas[i]->Show();
    }

    for (int i = 0; i < ct; i++)
        delete lolas[i];*/

    //Listing
    /*Stack<int> kernels;         //Создание стека для значений int
    Stack<string> colonels;     //Создание стека для объектов string

    using std::cin;
    using std::cout;
    //Stack<std::string> st;      //Создание пустого стека
    Stack<char *> st;
    char ch;
    char * po;
    cout << "Введите А - чтобы добавить заказ, Р - обработать заказ,"
            "Q - завершить.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        };
        switch (ch) {
        case 'A':
        case 'a':
            cout << "Введите номер для добавления: ";
            cin >> po;
            if (st.isfull())
                cout << "Стек уже полон\n";
            else
               st.push(po);
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                cout << "Стек уже пуст\n";
            else
            {
                st.pop(po);
                cout << "PO #" << po << "удален\n";
            }
            break;
        default:
            break;
        }
        cout << "Введите А - чтобы добавить заказ, Р - обработать заказ,"
                "Q - завершить.\n";
    };*/

    //Listing 14.16
    /*std::srand(std::time(0));
    using std::cin;
    using std::cout;

    cout << "Введите размер стека: ";
    int stacksize;
    std::cin >> stacksize;

    Stack<const char *> st(stacksize);

    //Входной ящик
    const char * in[Num] = {
        " 1: Hank Gilgamesh", " 2: Kiki Ishtar",
        " 3: Betty Rocker", " 4: Ian Flagranti",
        " 5: Wolfgang Kibble", " 6: Portia Koop",
        " 7: Joy Almondo", " 8: Xaverie Paprika",
        " 9: Juan Moore", " 10: Misha Mache"
    } ;

    //Выходной ящик
   const char * out[Num];
   int processed = 0;
   int nextin = 0;
   while (processed < Num)
   {
       if (st.isempty())
           st.push(in[nextin++]);
       else if (st.isfull())
               st.pop(out[processed++]);
       else if (std::rand() % 2 && nextin < Num)
           st.push(in[nextin++]);
       else
           st.pop(out[processed++]);
   }

   for (int i = 0; i < Num; i++)
       cout << out[i] << endl;*/

    //Listing 14.18
    using std::cin;
    using std::cout;

    ArrayTP<int, 10> sums;
    ArrayTP<double, 10> aves;
    ArrayTP<ArrayTP<int, 5>, 10> twodee;

    int i, j;
    for (i = 0; i < 10; i ++)
    {
        sums[i] = 0;
        for (j = 0; j < 5; j++)
        {
            twodee[i][j] = (i + 1) * (j + 1);
            sums[i] += twodee[i][j];
        }
        aves[i] = (double) sums[i] / 10;
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cout.width(2);
            cout << twodee[i][j] << ' ';
        }
        cout << ": sum = ";
        cout.width(3);
        cout << sums[i] << ", average = " << aves[i] << endl;
    }

    cout << "Bye.\n";

    return 0;
}

void set(Student &sa, int n)
{
    cout << "Пожалуйста, введите имя студента: ";
    getline(cin, sa);
    cout << "Пожалуйста, введите " << n << " оценок:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];
    while (cin.get() != '\n')
        continue;
}
