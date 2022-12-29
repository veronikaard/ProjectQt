#include "cd.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;

//Методы Cd
Cd::Cd(char *s1, char *s2, int n, double x)
{
    perfomers = new char[strlen(s1) + 1];
    label = new char[strlen(s2) + 1];
    strcpy(perfomers, s1);
    strcpy(label, s2);
    perfomers[strlen(s1)] = '\0';
    label[strlen(s2)] = '\0';
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d)
{
    perfomers = new char[strlen(d.perfomers) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy(perfomers, d.perfomers);
    strcpy(label, d.label);
    perfomers[strlen(d.perfomers)] = '\0';
    label[strlen(d.label)] = '\0';
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    perfomers = new char[5];
    label = new char[5];
    strcpy(perfomers, "None");
    strcpy(label, "None");
    perfomers[4] = '\0';
    label[4] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{
    delete [] perfomers;
    delete [] label;
}

void Cd::Report() const
{
    cout << "Исполнитель: " << perfomers << endl;
    cout << "Название трека: " << label << endl;
    cout << "Количество сборников: " << selections << endl;
    cout << "Время воспроизведения: " << playtime << endl;
}

Cd & Cd::operator=(const Cd &d)
{
    if (this == &d)
        return *this;

    delete [] perfomers;
    delete [] label;
    perfomers = new char[strlen(d.perfomers) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy(perfomers, d.perfomers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;

    return *this;
}

//Методы Classic
Classic::Classic(char *s1, char *s2, char *s3, int n, double x) : Cd(s1, s2, n, x)
{
    baselabel = new char[strlen(s3) + 1];
    strcpy(baselabel, s3);
    baselabel[strlen(s3)] = '\0';
}

Classic::Classic(const Classic &c) : Cd(c)
{
    baselabel = new char[strlen(c.baselabel) + 1];
    strcpy(baselabel, c.baselabel);
    baselabel[strlen(c.baselabel)] = '\0';
}

Classic::Classic() : Cd()
{
    baselabel = new char[5];
    strcpy(baselabel, "None");
    baselabel[4] = '\0';
}

Classic::~Classic()
{
    delete [] baselabel;
}

void Classic::Report() const
{
    Cd::Report();
    cout << "Основное произведение: " << baselabel << endl;
}

Classic & Classic::operator=(const Classic &c)
{
    if (this == &c)
        return *this;

    Cd::operator=(c);
    delete [] baselabel;
    baselabel = new char[strlen(c.baselabel) + 1];
    strcpy(baselabel, c.baselabel);
    baselabel[strlen(c.baselabel)] = '\0';

    return *this;
}


























