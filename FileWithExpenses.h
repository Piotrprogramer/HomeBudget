#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include "Markup.h"
#include "FileXml.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "Calendar.h"
//#include <cstring>

using namespace std;

class FileWithExpenses: public FileXml {
    int userId;
    Expense getNewExpenseData();
    void saveExpenseToFile(Expense expense);
public:
    FileWithExpenses(string name_of_file, int userId);
    void addExpense();
    vector <Expense> getVectorWithExpensesOfDateRange();
    string getExpense();

};
#endif

