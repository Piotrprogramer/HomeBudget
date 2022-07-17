#ifndef INCOMES_h
#define INCOMES_h

#include <iostream>
#include <time.h>


using namespace std;

class Income {
    double amount = 0;
    struct tm data;
    int userId = 0;

public:
    Income(int userId, double amount, int year, int month, int day);

    double getIncome();
    tm getDate();

    void setIncome(double income);
    void setData(int year, int month, int day);

    void display();

};
#endif
