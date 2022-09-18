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

string User::setLogin(string login) {
    this->login = login;
}

string User::setPassword(string password) {
    this->password = password;
}

string User::setUserName(string userName){
    this->userName = userName;
};

string User::setLastName(string lastName){
    this->lastName = lastName;
};
