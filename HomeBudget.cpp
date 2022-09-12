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
    cout<<"1- Dodaj przychod"<<endl;
    cout<<"2- Dodaj wydatek"<<endl;
    cout<<"3- Bilans z bieaccego miesiaca"<<endl;
    cout<<"4- Bilans z poprzedniego miesiaca"<<endl;
    cout<<"5- Bilans z wybranego okresu"<<endl;
    cout<<"6- Zmien haslo"<<endl;
    cout<<"0- Wyloguj sie"<<endl;
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
