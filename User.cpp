#include "User.h"

int User::getUserId() {
    return userId;
}

string User::getLogin() {
    return login;
}

string User::getPassword() {
    return password;
}

string User::getUserName(){
    return userName;
};
string User::getLastName(){
    return lastName;
};

void User::setLogin(string login) {
    this->login = login;
}

void User::setPassword(string password) {
    this->password = password;
}

void User::setUserName(string userName){
    this->userName = userName;
};

void User::setLastName(string lastName){
    this->lastName = lastName;
};
