#include "Expense.h"

Expense::Expense(int userId, double amount, int year, int month, int day) {
    this->userId = userId;
    this->amount = amount;

    data.tm_sec=0;
    data.tm_min=0;
    data.tm_hour=0;
    data.tm_hour=0;
    data.tm_wday=0;
    data.tm_yday=0;

    data.tm_mday  = day;
    data.tm_mon  =  month;
    data.tm_year = year;
}

double Expense::getExpense() {
    return amount;
};

tm Expense::getDate() {
    return data;
};

void Expense::setExpense(double amount) {
    this->amount = amount;
};

void Expense::setData(int year, int month, int day) {
    data.tm_mday  = day;
    data.tm_mon  =  month;
    data.tm_year = year;
};

void Expense::display() {
    cout<< amount << "PLN  - " <<data.tm_year << "/" << data.tm_mon << "/" << data.tm_mday <<endl;
}
