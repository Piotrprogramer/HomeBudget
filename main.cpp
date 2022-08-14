#include <iostream>
#include "Markup.h"
#include "User.h"
#include "Accountant.h"

using namespace std;

int _main()
{

    return 0;
}


#include "FileWithIncomes.h"
#include "Income.h"
#include "Calendar.h"
#include "Markup.h"
//#include <span class="code-string">"Markup.h"</span>

int fileWithIncomes_main()
{
    FileWithIncomes fileWithIncomes("fileWithIncomes.xml",707);
        //cout<< fileWithIncomes.isFileEmpty()<<endl;
        // fileWithIncomes.saveIncomesToFile();
     //    fileWithIncomes.deleteIncome();
        //fileWithIncomes.addIncome();
 //fileWithIncomes.addIncome(); fileWithIncomes.addIncome();
           //Income income(fileWithIncomes.getNewIncomeData());
          // fileWithIncomes.saveIncomeToFile();
            //income.display();

       // Calendar calendar;
        //struct tm date = Calendar::getCurrentDate();
       // cout<<"Data: "<<date.tm_year << "/" << date.tm_mon << "/" << date.tm_mday <<endl;
    return 0;
}

#include "FileWithExpenses.h"
#include "Income.h"
#include "Calendar.h"
#include "Markup.h"
//#include <span class="code-string">"Markup.h"</span>

int main()
{
    FileWithExpenses fileWithExpenses("fileWithExpenses.xml",707);
        //cout<< fileWithIncomes.isFileEmpty()<<endl;
        // fileWithIncomes.saveIncomesToFile();
     //    fileWithIncomes.deleteIncome();
        //fileWithIncomes.addIncome();
 fileWithExpenses.addExpense(); fileWithExpenses.addExpense(); fileWithExpenses.addExpense();
          // fileWithIncomes.saveIncomeToFile();
            //income.display();

       // Calendar calendar;
        //struct tm date = Calendar::getCurrentDate();
       // cout<<"Data: "<<date.tm_year << "/" << date.tm_mon << "/" << date.tm_mday <<endl;
    return 0;
}
