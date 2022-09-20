#ifndef USER_h
#define USER_h

#include <iostream>

using namespace std;

class User {
    int userId;
    string login;
    string password;
    string userName;
    string lastName;

public:
User(int id, string login, string password, string userName, string lastName){
    this->userId = id;
    this->login = login;
    this->password = password;
    this->userName = userName;
    this->lastName = lastName;
}

int getUserId();
string getLogin();
string getPassword();
string getUserName();
string getLastName();

void setLogin(string login);
void setPassword(string password);
void setUserName(string userName);
void setLastName(string lastName);

};
#endif
