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
    int idLoggedUser;

    vector <User> users;
    vector <User> getUsers();
    User getNewUserData();
    int getNewUserId();
    bool checkUsernameAvailability(string login);
    void saveUserToFile(User user);
    void registerNewUser();
    void loggingUser();

public:
    int mainMenu();
    UserMenager(string FILENAMEWITHUSERS):  FileXml(FILENAMEWITHUSERS) {
    users = getUsers();
    };



    void addUser();




    //void wczytajUzytkownikowZPliku();
   // int loggingUser();
    //void wylogujUzytkownika();
    //void zmienHasloZalogowanegoUzytkownika();
    int getIdLoggedUser();
    void displayAll();
};
#endif
