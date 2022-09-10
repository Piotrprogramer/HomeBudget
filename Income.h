#ifndef INCOMES_h
#define INCOMES_h

#include <iostream>
#include <time.h>
#include "AuxiliaryMethods.h"


using namespace std;

class Income {
    double amount = 0;
    int year, month, day;
    string incomeReason = "";
    int userId = 0;

public:
    Income(int userId,string incomeReason, double amount, int year, int month, int day);

    bool operator<(const Income &r) const{
        if ( ((year * 10000) + (month * 100) + day) != ((r.year * 10000) + (r.month * 100) + r.day)) {
            return ((year * 10000) + (month * 100) + day) < ((r.year * 10000) + (r.month * 100) + r.day);
        }
    }

    double getAmount();
    string getIncomeReason();
    string getDate();
    int getYear();
    int getMonth();
    int getDay();

    void setAmount(double amount);
    void setDate(int year, int month, int day);
    void setIncomeReason(string incomeReason);

    void display();
};
#endif
