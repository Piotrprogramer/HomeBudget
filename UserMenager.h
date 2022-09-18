#ifndef UZYTKOWNIKMENAGER_H
#define UZYTKOWNIKMENAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Markup.h"
#include "FileXml.h"
#include "User.h"
#include "AuxiliaryMethods.h"


using namespace std;

class UserMenager: public FileXml {
    int lastUserId;
    int idLoggedUser = 0;

    vector <User> fileWithUsers;
    vector <User> getUsers();
    User getNewUserData();
    int getNewUserId();
    bool checkUsernameAvailability(string login);
    void saveUserToFile(User user);
    void saveAllUsersToFile();
    void registerNewUser();
    void loggingUser();

public:
    UserMenager(string FILENAMEWITHUSERS):  FileXml(FILENAMEWITHUSERS) {
    fileWithUsers = getUsers();
    };

    void mainMenu();
    void addUser();
    int getIdLoggedUser();
    void changePasswordLoggedUser();
    void logOutUser();
};
#endif
