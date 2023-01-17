#include <iostream>
#include <locale>
#include "studentc.h"

using std::cin;
using std::cout;
using std::endl;

void set(Student &sa, int n);
const int pupils = 3;
const int quizzes = 5;

int main()
{
    setlocale(LC_ALL, "Rus");
    Student ada[pupils] =
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
    }

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
