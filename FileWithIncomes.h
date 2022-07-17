#ifndef FILEWITHINCOMES_h
#define FILEWITHINCOMES_h

#include <iostream>
#include <vector>
#include "Markup.h"
#include "FileXml.h"
#include "Income.h"

using namespace std;

class FileWithIncomes :public FileXml {
public:
    FileWithIncomes(string name_of_file): FileXml(name_of_file) {};

    vector <Income> loadIncomeFromFile();
    void saveIncomesToFile();
};
#endif
