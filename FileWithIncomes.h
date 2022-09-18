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
    const int userId;
    Income getNewIncomeData();
    void saveIncomeToFile(Income income);
    void displayIncome(Income income);
    vector <Income> allIncomes;

public:
    FileWithIncomes(string name_of_file, int USERID);
    void addIncome();
    vector <Income> getIncomesOfDateRange(int startYear , int startMonth, int startDay, int endYear, int endMonth, int endDay);
    vector <Income> getAllIncomes();
    void showAllIncomes(vector <Income> incomes);
    double getTotalIncomesAmount(vector <Income> incomes);

};
#endif
