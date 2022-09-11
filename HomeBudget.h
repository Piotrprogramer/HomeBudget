#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include "FileWithUsers.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "UserMenager.h"

using namespace std;

class HomeBudget {
    const string fileWithIncomesName;
    const string fileWithExpensesName;

    UserMenager userMenager;
    FileWithIncomes *fileWithIncomes;
    FileWithExpenses *fileWithExpenses;

public:
    HomeBudget(string FILEWITHUSERS, string FILEWITHINCOMES, string FILEWITHEXPENSES)
        :userMenager(FILEWITHUSERS),  fileWithIncomesName(FILEWITHINCOMES),  fileWithExpensesName(FILEWITHEXPENSES) {
        userMenager.mainMenu();
        };
};

#endif
