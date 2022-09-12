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

    void startMenu();
    void userMenu();
    void loadIncomesAndExpenses();

public:
    HomeBudget(string FILEWITHUSERS, string FILEWITHINCOMES, string FILEWITHEXPENSES)
        :userMenager(FILEWITHUSERS),  fileWithIncomesName(FILEWITHINCOMES),  fileWithExpensesName(FILEWITHEXPENSES) {
        //startMenu();
        userMenu();
    };
    ~HomeBudget() {
        delete fileWithIncomes;
        fileWithIncomes = NULL;
        delete fileWithExpenses;
        fileWithExpenses = NULL;
    };
};

#endif
