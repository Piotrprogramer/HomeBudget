#ifndef FILEWITHINCOMES_h
#define FILEWITHINCOMES_h

#include <iostream>
#include <vector>
#include "Markup.h"
#include "FileXml.h"
#include "Income.h"
#include "AuxiliaryMethods.h"
#include "Calendar.h"
#include <cstring>


using namespace std;

class FileWithIncomes :public FileXml {
    //vector <Income> Incomes;
    int userId;
    //CMarkup xml;
    Income getNewIncomeData();
   void saveIncomeToFile(Income income);

public:



    FileWithIncomes(string name_of_file, int userId);
    void addIncome();


    string getIncome();
    void deleteIncome();

    vector <Income> loadIncomeFromFile();
    //void saveIncomesToFile();
};
#endif
