//Классы банковских счетов
#ifndef ACCTABC_H
#define ACCTABC_H

#include <iostream>
#include <string>

//Абстрактный базовый класс
class AcctABC
{
private:
    std::string fullname;
    long acctNum;
    double balance;
protected:
    struct Formatting
    {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string & Fullname() const {return fullname;}
    long AcctNum() const {return acctNum;}
    Formatting SetFormat() const;
    void Restore(Formatting &f) const;
public:
    AcctABC(const std::string &s = "Nullbody", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt) = 0;      //Чистая виртуальная функция
    double Balance() const {return balance;}
    virtual void ViewAct() const = 0;           //Чистая виртуальная функция
    virtual ~AcctABC() {}
};

//Класс счета Brass Account
class Brass : public AcctABC
{
public:
    Brass(const std::string &s = "Nullbody", long an = -1, double bal = 0.0) : AcctABC(s, an, bal){}
    virtual void Withdraw(double amt);
    virtual void ViewAct() const;
    virtual ~Brass() {}
};

//Класс счета Brass Plus
class BrassPlus : public AcctABC
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string &s = "Nullbody", long an = -1, double bal = 0.0,
              double m1 = 500, double r = 0.10);
    BrassPlus(const Brass &ba, double m1 = 500, double r = 0.10);
    virtual void ViewAct()const;
    virtual void Withdraw(double amt);
    void ResetMax(double m){maxLoan = m;}
    void ResetRate(double r){rate = r;}
    void ResetOwes() {owesBank = 0;}
};

#endif // ACCTABC_H
