#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>
#include <time.h>
#include "AuxiliaryMethods.h"

using namespace std;

class Expense {
    double amount = 0;
    int year, month, day;
    string expenseReason = "";
    int userId = 0;

public:
    Expense(int userId,string expenseReason, double amount, int year, int month, int day);

    double getAmount();
    string getExpenseReason();
    string getDate();
    int getYear();
    int getMonth();
    int getDay();

    void setExpense(double income);
    void setDate(int year, int month, int day);
    void setExpenseReason(string expenseReason);

    void display();

};
#endif

