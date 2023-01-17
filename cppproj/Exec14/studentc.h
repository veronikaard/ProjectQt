#ifndef STUDENTC_H
#define STUDENTC_H

#include <iostream>
#include <string>
#include <valarray>

using std::string;

class Student : private std::string, private std::valarray<double>
{
private:
    typedef std::valarray<double> ArrayDb;

    //Закрытый метод для вывода оценок
    std::ostream &arr_out(std::ostream &os) const;
public:
    Student() : string("Null Student"), ArrayDb(){}
    explicit Student(const std::string &s)
        : string(s), ArrayDb() {}
    explicit Student(int n) : string("Nully"), ArrayDb(n) {}
    Student (const std::string &s, int n)
        : string(s), ArrayDb(n) {}
    Student(const std::string &s, const ArrayDb &a)
        : string(s), ArrayDb(a) {}
    Student (const char *str, const double *pd, int n)
        : string(str), ArrayDb(pd, n) {}
    ~Student() {}
    double Average() const;
    const std::string &Name() const;
    double & operator[](int i);
    double operator[](int i) const;

    //Друзья
    //Ввод
    friend std::istream &operator>>(std::istream &is, Student &stu);
    friend std::istream &getline(std::istream &is, Student &stu);
    friend std::ostream &operator<<(std::ostream &os, Student &stu);
};

/*class Student
{
private:
    typedef std::valarray<double> ArrayDb;
    std::string name;
    ArrayDb scores;

    //Закрытый метод для вывода оценок
    std::ostream &arr_out(std::ostream &os) const;
public:
    Student() : name("Null Student"), scores(){}
    explicit Student(const std::string &s)
        : name(s), scores() {}
    explicit Student(int n) : name("Nully"), scores(n) {}
    Student (const std::string &s, int n)
        : name(s), scores(n) {}
    Student(const std::string &s, const ArrayDb &a)
        : name(s), scores(a) {}
    Student (const char *str, const double *pd, int n)
        : name(str), scores(pd, n) {}
    ~Student() {}
    double Average() const;
    const std::string &Name() const;
    double & operator[](int i);
    double operator[](int i) const;

    //Друзья
    //Ввод
    friend std::istream &operator>>(std::istream &is, Student &stu);
    friend std::istream &getline(std::istream &is, Student &stu);
    friend std::ostream &operator<<(std::ostream &os, Student &stu);
};*/

#endif // STUDENTC_H
