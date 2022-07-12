#ifndef USER_h
#define USER_h

#include <iostream>

using namespace std;

class User {
    int userId;
    string login;
    string password;

public:
User(){
    this->userId = 0;
    this->login = "test";
    this->password = "p";
}

User(int id, string login, string password){
    this->userId = id;
    this->login = login;
    this->password = password;
}

int getUserId();
string getLogin();
string getPassword();

int setUserId(int id);
string setLogin(string login);
string setPassword(string password);

};
#endif
