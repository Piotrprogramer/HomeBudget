#include "Income.h"

Income::Income(int userId,string incomeReason, double amount, int year, int month, int day) {
    this->userId = userId;
    this->amount = amount;
    this->incomeReason = incomeReason;
    this->year = year;
    this->month = month;
    this->day = day;
}

double Income::getAmount() {
    return amount;
};

string Income::getDate() {
    string date = "";
    date = AuxiliaryMethods::converteIntToString(year);
    date+= "|" + AuxiliaryMethods::converteIntToString(month);
    date+= "|" + AuxiliaryMethods::converteIntToString(day);

    return date;
};

int Income::getYear(){
    return year;
}

int Income::getMonth(){
    return month;
}

int Income::getDay(){
    return day;
}

string Income::getIncomeReason(){
    return incomeReason;
}

void Income::setAmount(double amount) {
    this->amount = amount;
};

void Income::setDate(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
};

void Income::setIncomeReason(string incomeReason){
    this->incomeReason = incomeReason;
}

void Income::display() {
    //cout<<"Kwota: "<< amount << "PLN  - " <<endl<<"Data: "<<date.tm_year << "/" << date.tm_mon << "/" << date.tm_mday <<endl;
    cout<<"Kwota: "<< amount << "PLN  - " <<endl<<"Data: "<<year << "/" << month << "/" << day <<endl;
    cout<<"Powod: " <<incomeReason<<endl;
}
