#include "FileWithIncomes.h"

FileWithIncomes::FileWithIncomes(string name_of_file, int userId): FileXml(name_of_file) {
    CMarkup xml;
    this->userId = userId;
    bool fileExists = xml.Load( getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(getFileName());
    }
    allIncomes = getAllIncomes();
};

void FileWithIncomes::addIncome() {
    Income newIncome = getNewIncomeData();
    allIncomes.push_back(newIncome);
    saveIncomeToFile(newIncome);
};

Income FileWithIncomes::getNewIncomeData() {
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
    } while(answer != 'y' && answer != 'n');

    if(answer == 'y') {
        date = Calendar::getCurrentDate();
        year = date.tm_year;
        month = date.tm_mon;
        day = date.tm_mday;
    } else {
        do {
            cout<<"Date format:  rrrr mm dd";
            cout<<endl<<"Give the date: ";
            cin>>year>>month>>day;
            isValidDate = Calendar::isValidDate(day,month,year);
            if(!isValidDate) cout<<"Incorrect date. Try again."<<endl<<endl;
        } while(!isValidDate);
    }

    cout<< "Enter the income reason: ";
    cin.sync();
    incomeReason = AuxiliaryMethods::getLine();

    cout<< "Enter the amount of income: ";
    amount = AuxiliaryMethods::getDoubleTypeOfNumber();
    Income newIncome(userId,incomeReason, amount, year, month, day );

    return newIncome;
};

void FileWithIncomes::saveIncomeToFile(Income income){
    CMarkup xml;
    bool fileExists = xml.Load( getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(getFileName());
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("UserId", AuxiliaryMethods::converteIntToString(userId));
    xml.AddElem("IncomeReason", income.getIncomeReason());
    xml.AddElem("Amount", AuxiliaryMethods::converteDoubleToString(income.getAmount()));
    xml.AddElem("Date", income.getDate() );

    xml.Save(getFileName());
};

vector <Income> FileWithIncomes::getIncomesOfDateRange(int startYear , int startMonth, int startDay, int endYear, int endMonth, int endDay){
    vector <Income> incomes;
    string data;

    double amount = 0;
    int year, month, day;
    string incomeReason = "";

    bool isValidDate = false;

    CMarkup xml;
    bool fileExists = xml.Load( getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(getFileName());
    }

    xml.FindElem(); // ORDER element is root
    xml.IntoElem(); // inside ORDER

    while ( xml.FindElem("Income") ) {

        int year, month, day;
        xml.FindChildElem(  );
        data = xml.GetChildData();

        xml.FindChildElem(  );
        data = xml.GetChildData();
        incomeReason = data;

        xml.FindChildElem(  );
        data = xml.GetChildData();
        amount = AuxiliaryMethods::converteStringToDouble(data);

        xml.FindChildElem(  );
        data = xml.GetChildData();

        day = AuxiliaryMethods::getDate( data, 2);
        month = AuxiliaryMethods::getDate( data, 1);
        year = AuxiliaryMethods::getDate( data, 0);

        if(AuxiliaryMethods::isDateInRange( day, month, year, startDay, startMonth, startYear, endDay, endMonth, endYear)){
        Income income( userId, incomeReason, amount, year, month, day);
        incomes.push_back(income);
        };
    }
    return incomes;
};

vector <Income> FileWithIncomes::getAllIncomes(){
    vector <Income> incomes;
    string data;

    int logedUserId;
    double amount = 0;
    string incomeReason = "";

    CMarkup xml;
    bool fileExists = xml.Load( getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(getFileName());
    }

    xml.FindElem(); // ORDER element is root
    xml.IntoElem(); // inside ORDER

    while ( xml.FindElem("Income") ) {

        int year, month, day;
        xml.FindChildElem(  );
        data = xml.GetChildData();
        logedUserId = AuxiliaryMethods::converteStringToInt(data);

        xml.FindChildElem(  );
        data = xml.GetChildData();
        incomeReason = data;

        xml.FindChildElem(  );
        data = xml.GetChildData();
        amount = AuxiliaryMethods::converteStringToDouble(data);

        xml.FindChildElem(  );
        data = xml.GetChildData();

        day = AuxiliaryMethods::getDate( data, 2);
        month = AuxiliaryMethods::getDate( data, 1);
        year = AuxiliaryMethods::getDate( data, 0);

        if(userId = logedUserId){
        Income income( userId, incomeReason, amount, year, month, day);
        incomes.push_back(income);
        }
    }
    return incomes;
};

void FileWithIncomes::displayIncome(Income income){
    cout<<income.getDate()<<endl;
    cout<<income.getAmount()<<endl;
    cout<<income.getIncomeReason()<<endl;
    cout<<"---------------"<<endl;
};

void FileWithIncomes::showAllIncomes(vector <Income> incomes){
    sort(incomes.begin(), incomes.end());
    cout<<"BALANCE SHEET OF INCOMES"<<endl;
    cout<<"==============="<<endl;
    for(auto getedIncome : incomes) displayIncome(getedIncome);
    cout<<endl;
};

double FileWithIncomes::getTotalIncomesAmount(vector <Income> incomes){
    double sum = 0;
    for(auto getedIncome: incomes) sum += getedIncome.getAmount();

    return sum;
};
