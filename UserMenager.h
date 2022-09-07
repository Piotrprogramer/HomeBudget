#ifndef UZYTKOWNIKMENAGER_H
#define UZYTKOWNIKMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"


using namespace std;

class UserMenager {
    int idZalogowanegoUzytkownika;
    vector <User> uzytkownicy;
    FileWithUsers fileWithUsers;

    //User podajDaneNowegoUzytkownika();
    //int pobierzIdNowegoUzytkownika();
    //bool czyIstniejeLogin(string login);

   // MetodyPomocnicze metodyPomocnicze;

public:
    UserMenager(string FileNameWithUsers): fileWithUsers(FileNameWithUsers) {
       // wczytajUzytkownikowZPliku();
    };

    //void rejestracjaUzytkownika();
    //void wczytajUzytkownikowZPliku();
    //int logowanieUzytkownika();
    //void wylogujUzytkownika();
    //void zmienHasloZalogowanegoUzytkownika();
    //int pobierzIdZalogowanegoUzytkownika();
};
#endif
