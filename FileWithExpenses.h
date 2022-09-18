#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include "Markup.h"
#include "FileXml.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "Calendar.h"

using namespace std;

class FileWithExpenses: public FileXml {
    const int userId;
    Expense getNewExpenseData();
    void saveExpenseToFile(Expense expense);
    void displayExpenses(Expense expense);
    vector<Expense> allExpense;

public:
    FileWithExpenses(string name_of_file, int USERID);
    void addExpense();
    vector <Expense> getExpensesOfDateRange(int startYear , int startMonth, int startDay, int endYear, int endMonth, int endDay);
    vector <Expense> getAllExpenses();
    void showAllExpences(vector <Expense> expenses);
    double getTotalExpensesAmount(vector <Expense> expenses);
};
#endif

