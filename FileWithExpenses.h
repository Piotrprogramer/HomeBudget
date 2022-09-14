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
    int userId;
    Expense getNewExpenseData();
    void saveExpenseToFile(Expense expense);
    vector<Expense> allExpense;

public:
    FileWithExpenses(string name_of_file, int userId);
    void addExpense();
    vector <Expense> getExpensesOfDateRange();
    string getExpense();
    vector <Expense> getAllExpenses();

};
#endif

