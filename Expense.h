#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>
#include <time.h>

using namespace std;

class Expense {
    double amount = 0;
    struct tm data;
    int userId = 0;

public:
    Expense(int userId, double amount, int rok, int miesiac, int dzien);

    double getExpense();
    tm getDate();

    void setExpense(double income);
    void setData(int year, int month, int day);

    void display();
};
#endif
