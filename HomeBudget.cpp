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

void HomeBudget::getBalanceOfSetPeriod() {
    //int startDay, startMonth, startYear;
    //int endDay, endMonth, endYear;
    int startDay = 15, startMonth=1, startYear=2010;
    int endDay = 15, endMonth=1, endYear=2020;

    double totalIncomeAmount = 0;
    double totalExpensesAmount = 0;

    bool isValidDate;

    vector<Income> incomes;
    vector<Expense> expenses;
    /*
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
    */
    system("cls");
    incomes = fileWithIncomes->getIncomesOfDateRange( startYear , startMonth, startDay, endYear, endMonth, endDay);
    expenses = fileWithExpenses->getExpensesOfDateRange( startYear , startMonth, startDay, endYear, endMonth, endDay);

    fileWithIncomes->showAllIncomes(incomes);
    fileWithExpenses->showAllExpences(expenses);

    totalIncomeAmount = fileWithIncomes->getTotalIncomesAmount(incomes);
    totalExpensesAmount = fileWithExpenses->getTotalExpensesAmount(expenses);

    cout<<"Total amount of incomes: "<<totalIncomeAmount<<endl;
    cout<<"Total amount of expenses: "<<totalExpensesAmount<<endl;
    cout<<"The ratio of income to expenses: "<< totalIncomeAmount - totalExpensesAmount<<endl<<endl;

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
            //billans z biezacego misiaca
            break;
        }
        case '4': {
            //4- Bilans z poprzedniego miesiaca"
            break;
        }
        case '5': {
            //5- Bilans z wybranego okresu
            getBalanceOfSetPeriod();
            break;
        }
        case '6': {
            //<<"6- Zmien haslo
            break;
        }
        case '0': {
            logOut();
        }
        }
    }
};
