#ifndef INCOMES_h
#define INCOMES_h

#include <iostream>
#include <time.h>


using namespace std;

class Income {
    double amount = 0;
    struct tm date;
    int year, month, day;
    string incomeReason = "";
    int userId = 0;

public:
    Income(int userId,string incomeReason, double amount, int year, int month, int day);

    double getAmount();
    string getIncomeReason();
    tm getDate();

    void setIncome(double income);
    void setDate(int year, int month, int day);
    void setIncomeReason(string incomeReason);

    void display();

};
#endif
