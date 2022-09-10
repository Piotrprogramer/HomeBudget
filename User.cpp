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

string User::setLogin(string login) {
    this->login = login;
}

string User::setPassword(string password) {
    this->password = password;
}
