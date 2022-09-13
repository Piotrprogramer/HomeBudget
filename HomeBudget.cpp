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

void HomeBudget::userMenu(){
    char choice;
    while(choice != '0'){
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
            break;
        }
        case '6': {
            //<<"6- Zmien haslo
            break;
        }
        case '0':{}
           // 0- Wyloguj sie
        }
    }
};
