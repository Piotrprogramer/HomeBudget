#include "FileWithExpenses.h"

FileWithExpenses::FileWithExpenses(string name_of_file, int userId): FileXml(name_of_file) {
    CMarkup xml;
    this->userId = userId;
    bool fileExists = xml.Load( getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(getFileName());
    }
};

void FileWithExpenses::addExpense() {
    Expense newExpense = getNewExpenseData();
    saveExpenseToFile(newExpense);
};

Expense FileWithExpenses::getNewExpenseData() {
    char answer = {0};
    string expenseReason = "";
    double amount = 0;
    int year, month, day;
    struct tm date;
    bool isValidDate = false;

    cout<< "Is this Expense today <y / n>?" <<endl;
    do {
        answer = AuxiliaryMethods::getChar();
        if(answer != 'y' && answer != 'n') cout<<"There is no '"<< answer << "' option"<<endl;
    } while(answer != 'y' && answer != 'n');

    if(answer == 'y') {
        date = Calendar::getCurrentDate();
        year = date.tm_year;
        month = date.tm_mon;
        day = date.tm_mday;
    } else {
        do {
            cout<<"Date format:  rrrr-mm-dd";
            cout<<endl<<"Give the date: ";
            cin>>year>>month>>day;
            isValidDate = Calendar::isValidDate(day,month,year);
            if(!isValidDate) cout<<"Incorrect date. Try again."<<endl<<endl;
        } while(!isValidDate);
    }

    cout<< "Enter the Expense reason: ";
    cin.sync();
    expenseReason = AuxiliaryMethods::getLine();

    cout<< "Enter the amount of Expense: ";
    amount = AuxiliaryMethods::getDoubleTypeOfNumber();
    Expense newExpense(userId,expenseReason, amount, year, month, day );

    return newExpense;
};

void FileWithExpenses::saveExpenseToFile(Expense Expense){
    CMarkup xml;
    bool fileExists = xml.Load( getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(getFileName());
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("UserId", AuxiliaryMethods::converteIntToString(userId));
    xml.AddElem("expenseReason", Expense.getExpenseReason());
    xml.AddElem("Amount", AuxiliaryMethods::converteDoubleToString(Expense.getAmount()));
    xml.AddElem("Date", Expense.getDate() );

    xml.Save(getFileName());

};

string FileWithExpenses::getExpense(){
    string amount ;
    CMarkup xml;
    bool fileExists = xml.Load( getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(getFileName());
    }
    xml.FindElem(); // ORDER element is root
    xml.IntoElem(); // inside ORDER
    while ( xml.FindElem("Expense") ) {
        xml.FindChildElem( "Amount" );
        amount = xml.GetChildData();
            cout<<amount<<endl;
    }
    return amount;
};

