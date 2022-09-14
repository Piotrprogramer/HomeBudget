#ifndef FILEWITHINCOMES_h
#define FILEWITHINCOMES_h

#include <iostream>
#include "Markup.h"
#include "FileXml.h"
#include "Income.h"
#include "AuxiliaryMethods.h"
#include "Calendar.h"

using namespace std;

class FileWithIncomes :public FileXml {
    int userId;
    Income getNewIncomeData();
    void saveIncomeToFile(Income income);
    vector <Income> allIncomes;

public:
    FileWithIncomes(string name_of_file, int userId);
    void addIncome();
    vector <Income> getIncomesOfDateRange();
    vector <Income> getAllIncomes();
};
#endif
