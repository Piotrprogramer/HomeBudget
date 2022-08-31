#include "Expense.h"

Expense::Expense(int userId,string expenseReason, double amount, int year, int month, int day) {
    this->userId = userId;
    this->amount = amount;
    this->expenseReason = expenseReason;
    this->year = year;
    this->month = month;
    this->day = day;
}

Expense::Expense(int userId) {
    this->userId = userId;
    this->amount = 0;
    this->expenseReason = "";
    this->year = 2000;
    this->month = 1;
    this->day = 1;
}

double Expense::getAmount() {
    return amount;
};

string Expense::getDate() {
    string date = "";
    date = AuxiliaryMethods::converteIntToString(year);
    date+= "|" + AuxiliaryMethods::converteIntToString(month);
    date+= "|" + AuxiliaryMethods::converteIntToString(day);

    return date;
};

int Expense::getYear(){
    return year;
}

int Expense::getMonth(){
    return month;
}

int Expense::getDay(){
    return day;
}

string Expense::getExpenseReason(){
    return expenseReason;
}

void Expense::setAmount(double amount) {
    this->amount = amount;
};

void Expense::setDate(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
};

void Expense::setExpenseReason(string expenseReason){
    this->expenseReason = expenseReason;
}

void Expense::display() {
    cout<<"Kwota: "<< amount << "PLN  - " <<endl<<"Data: "<<year << "/" << month << "/" << day <<endl;
    cout<<"Powod: " <<expenseReason<<endl;
}

