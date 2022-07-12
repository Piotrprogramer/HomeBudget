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

int User::setUserId(int id) {
    this->userId = id;
}

string User::setLogin(string login) {
    this->login = login;
}

string User::setPassword(string password) {
    this->password = password;
}
