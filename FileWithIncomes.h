#ifndef FILEWITHINCOMES_h
#define FILEWITHINCOMES_h

#include <iostream>
//#include <vector>
#include "Markup.h"
#include "FileXml.h"
#include "Income.h"
#include "AuxiliaryMethods.h"
#include "Calendar.h"
//#include <cstring>


using namespace std;

class FileWithIncomes :public FileXml {
    int userId;
    Income getNewIncomeData();
    void saveIncomeToFile(Income income);

public:
    FileWithIncomes(string name_of_file, int userId);
    void addIncome();
    vector <Income> getVectorWithIncomesOfDateRange();

};
#endif
