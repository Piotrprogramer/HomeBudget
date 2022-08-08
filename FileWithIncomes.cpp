#include "FileWithIncomes.h"

FileWithIncomes::FileWithIncomes(string name_of_file, int userId): FileXml(name_of_file) {
    //CMarkup xml;
    this->userId = userId;
    bool fileExists = xml.Load( getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(getFileName());
    }
};

Income FileWithIncomes::getNewIncomeData(){
    char answer = {0};
    string incomeReason = "";
    double amount = 0;
    int year, month, day;
    struct tm date;
    bool isValidDate = false;
    cout<< "Is this income today <y / n>?" <<endl;
    do {
            answer = AuxiliaryMethods::getChar();
            if(answer != 'y' && answer != 'n') cout<<"There is no '"<< answer << "' option"<<endl;
    }
    while(answer != 'y' && answer != 'n');
    if(answer == 'y') date = Calendar::getCurrentDate();
    else{
        do{
        cout<<"Date format:  rrrr-mm-dd";
        cout<<endl<<"Give the date: ";
        cin>>year>>month>>day;
        isValidDate = Calendar::isValidDate(day,month,year);
        if(!isValidDate) cout<<"Incorrect date. Try again."<<endl<<endl;
        }
        while(!isValidDate);
    }

    cout<< "Enter the income reason: ";
    cin.sync();
    incomeReason = AuxiliaryMethods::getLine();

    cout<< "Enter the amount of income: ";
    amount = AuxiliaryMethods::getDoubleTypeOfNumber();
    Income newIncome(userId,incomeReason, amount, date.tm_year, date.tm_mon, date.tm_mday );

    return newIncome;
};

vector <Income> FileWithIncomes::loadIncomeFromFile() {};

void FileWithIncomes::addIncome() {

    Income newIncome = getNewIncomeData();
    newIncome.display();

};

void FileWithIncomes::deleteIncome() {

    //CMarkup xml;
    //xml.SetDoc(  () );

    xml.FindElem(); // ORDER element is root
    xml.IntoElem(); // inside ORDER
    while ( xml.FindElem("Income") ) {
        //xml.FindChildElem( "UserId" );
        xml.RemoveChildElem();
        xml.RemoveElem();
         //   cout<<amount<<endl;
        //if ( xml.GetChildData() == csFindSN )
           // break; // found
        xml.Save(getFileName());
    }
};

string FileWithIncomes::getIncome(){
    string amount ;
    xml.FindElem(); // ORDER element is root
    xml.IntoElem(); // inside ORDER
    while ( xml.FindElem("Income") ) {
        xml.FindChildElem( "Amount" );
        amount = xml.GetChildData();
            cout<<amount<<endl;
        //if ( xml.GetChildData() == csFindSN )
           // break; // found
    }
    return amount;
};



void FileWithIncomes::saveIncomesToFile() {
    /*
        CMarkup xml;

        bool fileExists = xml.Load( getFileName());

        if (!fileExists){
            xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            xml.AddElem(getFileName());
        }
    */
// CMarkup xml;
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("UserId", "2");
    xml.AddElem("Date", "date");
    xml.AddElem("Amount", "amount");

    //xml.OutOfElem(); // back to level up

    xml.Save(getFileName());
    xml.ResetPos();

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("UserId", "2");
    xml.AddElem("Date", "date");
    xml.AddElem("Amount", "amount");

    xml.Save(getFileName());

};
