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
    void registerNewUser();
    void loggingUser();
    void logOutUser();

public:
    UserMenager(string FILENAMEWITHUSERS):  FileXml(FILENAMEWITHUSERS) {
    fileWithUsers = getUsers();
    };

    void mainMenu();

    void addUser();

    int getIdLoggedUser();



    //void wczytajUzytkownikowZPliku();
   // int loggingUser();
    //void wylogujUzytkownika();
    //void zmienHasloZalogowanegoUzytkownika();

    void displayAll();
};
#endif
