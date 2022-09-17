#include "HomeBudget.h"

void HomeBudget::startMenu(){
    userMenager.mainMenu();
    if (userMenager.getIdLoggedUser() > 0) {
        loadIncomesAndExpenses();
        userMenu();
    }
};

void HomeBudget::loadIncomesAndExpenses(){
    fileWithIncomes = new FileWithIncomes(fileWithIncomesName,userMenager.getIdLoggedUser());
    fileWithExpenses = new FileWithExpenses(fileWithExpensesName,userMenager.getIdLoggedUser());
};

void HomeBudget::logOut(){
    userMenager.logOutUser();
    delete fileWithIncomes;
    fileWithIncomes = NULL;
    delete fileWithExpenses;
    fileWithExpenses = NULL;

    startMenu();
};

void HomeBudget::getBalanceSheetOfCurrentMonth(){
    tm date = Calendar::getCurrentDate();

    int startMonth = date.tm_mon, startYear = date.tm_year;
    int endMonth = date.tm_mon, endYear = date.tm_year;

    double totalIncomeAmount = 0;
    double totalExpensesAmount = 0;

    bool isValidDate;

    vector<Income> incomes;
    vector<Expense> expenses;

    system("cls");
    incomes = fileWithIncomes->getIncomesOfDateRange( startYear , startMonth, 1, endYear, endMonth, 31);
    expenses = fileWithExpenses->getExpensesOfDateRange( startYear , startMonth, 1, endYear, endMonth, 31);

    fileWithIncomes->showAllIncomes(incomes);
    fileWithExpenses->showAllExpences(expenses);

    totalIncomeAmount = fileWithIncomes->getTotalIncomesAmount(incomes);
    totalExpensesAmount = fileWithExpenses->getTotalExpensesAmount(expenses);

    cout<<"Total amount of incomes: "<<AuxiliaryMethods::converteDoubleToString(totalIncomeAmount)<<endl;
    cout<<"Total amount of expenses: "<<AuxiliaryMethods::converteDoubleToString(totalExpensesAmount)<<endl;
    cout<<"The ratio of income to expenses: "<<  AuxiliaryMethods::converteDoubleToString(totalIncomeAmount - totalExpensesAmount)<<endl<<endl;

    system("pause");
};

void HomeBudget::getBalanceSheetOfLastMonth(){
    tm date = Calendar::getCurrentDate();

    int startMonth = date.tm_mon - 1, startYear = date.tm_year;
    int endMonth = date.tm_mon - 1, endYear = date.tm_year;

    if(startMonth == 0){
        startMonth = 12, startYear -= 1;
        endMonth = 12, endYear -= 1;
    }

    double totalIncomeAmount = 0;
    double totalExpensesAmount = 0;

    bool isValidDate;

    vector<Income> incomes;
    vector<Expense> expenses;

    system("cls");
    incomes = fileWithIncomes->getIncomesOfDateRange( startYear , startMonth, 1, endYear, endMonth, 31);
    expenses = fileWithExpenses->getExpensesOfDateRange( startYear , startMonth, 1, endYear, endMonth, 31);

    fileWithIncomes->showAllIncomes(incomes);
    fileWithExpenses->showAllExpences(expenses);

    totalIncomeAmount = fileWithIncomes->getTotalIncomesAmount(incomes);
    totalExpensesAmount = fileWithExpenses->getTotalExpensesAmount(expenses);

    cout<<"Total amount of incomes: "<<AuxiliaryMethods::converteDoubleToString(totalIncomeAmount)<<endl;
    cout<<"Total amount of expenses: "<<AuxiliaryMethods::converteDoubleToString(totalExpensesAmount)<<endl;
    cout<<"The ratio of income to expenses: "<<  AuxiliaryMethods::converteDoubleToString(totalIncomeAmount - totalExpensesAmount)<<endl<<endl;

    system("pause");
};

void HomeBudget::getBalanceSheetOfSetPeriod() {
    int startDay, startMonth, startYear;
    int endDay, endMonth, endYear;
     //startDay = 15, startMonth=1, startYear=2000;
     //endDay = 15, endMonth=1, endYear=3000;

    double totalIncomeAmount = 0;
    double totalExpensesAmount = 0;

    bool isValidDate;

    vector<Income> incomes;
    vector<Expense> expenses;

    do {
        cout<<"Date format:  rrrr mm dd";
        cout<<endl<<"Give the start date: ";
        cin>>startYear>>startMonth>>startDay;
        isValidDate = Calendar::isValidDate(startDay,startMonth,startYear);
        if(!isValidDate) cout<<"Incorrect date. Try again."<<endl<<endl;
    } while(!isValidDate);

    do {
        cout<<"Date format:  rrrr mm dd";
        cout<<endl<<"Give the end date: ";
        cin>>endYear>>endMonth>>endDay;
        isValidDate = Calendar::isValidDate(endDay,endMonth,endYear);
        if(!isValidDate) cout<<"Incorrect date. Try again."<<endl<<endl;
    } while(!isValidDate);

    system("cls");
    incomes = fileWithIncomes->getIncomesOfDateRange( startYear , startMonth, startDay, endYear, endMonth, endDay);
    expenses = fileWithExpenses->getExpensesOfDateRange( startYear , startMonth, startDay, endYear, endMonth, endDay);

    fileWithIncomes->showAllIncomes(incomes);
    fileWithExpenses->showAllExpences(expenses);

    totalIncomeAmount = fileWithIncomes->getTotalIncomesAmount(incomes);
    totalExpensesAmount = fileWithExpenses->getTotalExpensesAmount(expenses);

    cout<<"Total amount of incomes: "<<AuxiliaryMethods::converteDoubleToString(totalIncomeAmount)<<endl;
    cout<<"Total amount of expenses: "<<AuxiliaryMethods::converteDoubleToString(totalExpensesAmount)<<endl;
    cout<<"The ratio of income to expenses: "<<  AuxiliaryMethods::converteDoubleToString(totalIncomeAmount - totalExpensesAmount)<<endl<<endl;

    system("pause");
};

void HomeBudget::userMenu() {
    char choice = 'x';
    while(choice != 0) {
        cin.sync();
        system("cls");
        cout<<"1- Add income"<<endl;
        cout<<"2- Add Expenses"<<endl;
        cout<<"3- Balance sheet for the current month"<<endl;
        cout<<"4- Balance sheet for the last  month"<<endl;
        cout<<"5- Balance sheet for the set period time"<<endl;
        cout<<"6- Change password"<<endl;
        cout<<"0- Log out"<<endl;
        cout<<"====================="<<endl;
        choice = AuxiliaryMethods::getChar();
        switch(choice) {
        case '1': {
            fileWithIncomes->addIncome();
            break;
        }
        case '2': {
            fileWithExpenses->addExpense();
            break;
        }
        case '3': {
            getBalanceSheetOfCurrentMonth();
            break;
        }
        case '4': {
            getBalanceSheetOfLastMonth();
            break;
        }
        case '5': {
            getBalanceSheetOfSetPeriod();
            break;
        }
        case '6': {
            userMenager.changePasswordLoggedUser();

            break;
        }
        case '0': {
            logOut();
        }
        }
    }
};
