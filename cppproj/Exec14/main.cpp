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
#include "pairs.h"

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

/*template <typename T>
class beta
{
  private:
    template <typename V>           //��������� ��������� �����-����
    class hold
    {
      private:
        V val;
    public:
        hold(V v = 0) : val(v) {}
        void show() const {cout << val << endl;}
        V Value() const {return val;}
    };
    hold <T> q;                     //��������� ������
    hold <int> n;                   //��������� ������
public:
    beta(T t, int i) : q(t), n(i){}
    template<typename U>            //��������� �����
    U blab(U u, T t){return (n.Value() + q.Value())*u/t;}
    void Show() const {q.show(); n.show();}
};*/

//������� ��� ���������
/*template <template <typename T> class Thing>
class Crab
{
private:
    Thing<int> s1;
    Thing<double> s2;
public:
    Crab(){};
    bool push(int a, double x) {return s1.push(a) && s2.push(x);}
    bool pop(int &a, double &x) {return s1.pop(a) && s2.pop(x);}
};

template <typename T>
class HasFriend
{
private:
    T item;
    static int ct;
public:
    HasFriend(const T &i) : item(i) {ct++;}
    ~HasFriend(){ct--;}
    friend void counts();
    friend void reports(HasFriend<T> &);
};

template <typename T>
int HasFriend<T>::ct = 0;*/
/*void counts()
{
    cout << "int count: " << HasFriend<int>::ct << "; ";
    cout << "double count: " << HasFriend<double>::ct << endl;
}

void reports(HasFriend<int> &hf)
{
    cout << "HasFriend<int>: " << hf.item << endl;
}

void reports(HasFriend<double> &hf)
{
    cout << "HasFriend<double>: " << hf.item << endl;
}*/

//��������� ������ ��� ���������� ������
//��������� ��������
/*template <typename T> void counts();
template <typename T> void reports(T &);

//��������� �����
template <typename TT>
class HasFriendT
{
private:
    TT item;
    static int ct;
public:
    HasFriendT(const TT &i) : item(i) {ct++;}
    ~HasFriendT() {ct--;}
    friend void counts<TT>();
    friend void reports<>(HasFriendT<TT> &);
};

template <typename T>
int HasFriendT<T>::ct = 0;

//����������� ������������� ������� ��� �������
template <typename T>
void counts()
{
    cout << "������ �������: " << sizeof(HasFriendT<T>) << "; ";
    cout << "counts() �� �������: " << HasFriendT<T>::ct << endl;
}

template <typename T>
void reports(T &hf)
{
    cout << hf.item << endl;
}*/

//����������� ��������� �������, ������������� ���������� ������
template <typename T>
class ManyFriend
{
private:
    T item;
public:
    ManyFriend(const T &i): item(i) {}
    template <typename C, typename D> friend void show2(C &, D &);
};

template <typename C, typename D> void show2(C &c, D &d)
{
    cout << c.item << ", " << d.item << endl;
}

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
    cout << "\n������ ���������:\n";;
    for (i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;
    cout << "\n������:\n";
    for (i = 0; i < pupils; i++)
    {
        cout << endl << ada[i];
        cout << "������� ������: " << ada[i].Average() << endl;
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
        cout << "������� ��������� ���������:\n"
             << "w - ��������, s - �����, t - ������ ��������, q - ����������\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "����������, ������� w, s, t ��� q: ";
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

    cout << "\n����� ������ ����������:\n";
    int i;
    for (int i = 0; i < ct; i++)
    {
        cout << endl;
        lolas[i]->Show();
    }

    for (int i = 0; i < ct; i++)
        delete lolas[i];*/

    //Listing
    /*Stack<int> kernels;         //�������� ����� ��� �������� int
    Stack<string> colonels;     //�������� ����� ��� �������� string

    using std::cin;
    using std::cout;
    //Stack<std::string> st;      //�������� ������� �����
    Stack<char *> st;
    char ch;
    char * po;
    cout << "������� � - ����� �������� �����, � - ���������� �����,"
            "Q - ���������.\n";
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
            cout << "������� ����� ��� ����������: ";
            cin >> po;
            if (st.isfull())
                cout << "���� ��� �����\n";
            else
               st.push(po);
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                cout << "���� ��� ����\n";
            else
            {
                st.pop(po);
                cout << "PO #" << po << "������\n";
            }
            break;
        default:
            break;
        }
        cout << "������� � - ����� �������� �����, � - ���������� �����,"
                "Q - ���������.\n";
    };*/

    //Listing 14.16
    /*std::srand(std::time(0));
    using std::cin;
    using std::cout;

    cout << "������� ������ �����: ";
    int stacksize;
    std::cin >> stacksize;

    Stack<const char *> st(stacksize);

    //������� ����
    const char * in[Num] = {
        " 1: Hank Gilgamesh", " 2: Kiki Ishtar",
        " 3: Betty Rocker", " 4: Ian Flagranti",
        " 5: Wolfgang Kibble", " 6: Portia Koop",
        " 7: Joy Almondo", " 8: Xaverie Paprika",
        " 9: Juan Moore", " 10: Misha Mache"
    } ;

    //�������� ����
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
    /*using std::cin;
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
    }*/

    //Listing 14.19
    /*using std::endl;
    using std::cout;
    using std::string;
    Pair<string, int> ratings[4] =
    {
        Pair<string, int>("The Purpled Duck", 5),
        Pair<string, int>("Frisco Al Fresco", 4),
        Pair<string, int>("Cafe Souffle", 5),
        Pair<string, int>("Bertie's Eats", 3)
    };

    int joints = sizeof(ratings) / sizeof(Pair<string, int>);
    cout << "������� ����������:\n";
    for (int i = 0; i < joints; i++)
        cout << ratings[i].second() << ":\t "
             << ratings[i].first() << endl;

    cout << "�������������� �������:\n";
    ratings[3].first() = "Berty's Fab Eats";
    ratings[3].second() = 6;

    for (int i = 0; i < joints; i++)
        cout << ratings[i].second() << ":\t "
             << ratings[i].first() << endl;*/

    //Listing 14.20 - �������-�����
    /*beta<double> guy(3.5, 3);
    cout << "T ���������� � double\n";
    guy.Show();
    cout << "V ���������� � T, ������� double, ����� V ���������� � int\n";
    cout << guy.blab(10, 2.3) << endl;
    cout << guy.blab(10.0, 2.3) << endl;*/

    //Listing 14.21 - ������� ��� ���������
    /*Crab<Stack> nebula;
    int ni;
    double nb;
    cout << "������� ���� ����� int � double:\n";
    while (cin >> ni >> nb && ni > 0 && nb > 0) {
        if (!nebula.push(ni, nb))
            break;
    }

    while (nebula.pop(ni, nb))
        cout << ni << ", " << nb << endl;*/

    //Listing 14.22 - ��������� ����� � ������������ ��������
    /*cout << "������� ���� �� ���������\n";
    counts();

    HasFriend<int> hfi1(10);
    cout << "Int 1 declared: ";
    counts();

    HasFriend<int> hfi2(10);
    cout << "Int 2 declared: ";
    counts();

    HasFriend<double> hfdb(10.5);
    cout << "Double declared: ";
    counts();

    reports(hfi1);
    reports(hfi2);
    reports(hfdb);*/

    //Listing 14.23 - ��������� ������ ��� ���������� ������
    /*counts<int>();
    counts<double>();
    HasFriendT<int> hfi1(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);
    reports(hfi1);
    reports(hfi2);
    reports(hfdb);
    counts<int>();
    counts<double>();*/

    //Listing 14.24 - ����������� ��������� �������, �������������
    //                ���������� ������
    ManyFriend<int> hfi1(10);
    ManyFriend<int> hfi2(20);
    ManyFriend<double> hfdb(10.5);
    show2(hfi1, hfi2);
    show2(hfdb, hfi2);

    cout << "Bye.\n";

    return 0;
}

void set(Student &sa, int n)
{
    cout << "����������, ������� ��� ��������: ";
    getline(cin, sa);
    cout << "����������, ������� " << n << " ������:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];
    while (cin.get() != '\n')
        continue;
}
