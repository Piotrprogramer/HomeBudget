#ifndef UZYTKOWNIKMENAGER_H
#define UZYTKOWNIKMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"


using namespace std;

class UserMenager {
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

    MetodyPomocnicze metodyPomocnicze;

public:
    UzytkownikMenager(string nazwaPlikuZUzytkownikami): plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
        wczytajUzytkownikowZPliku();
    };

    void rejestracjaUzytkownika();
    void wczytajUzytkownikowZPliku();
    int logowanieUzytkownika();
    void wylogujUzytkownika();
    void zmienHasloZalogowanegoUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
};
#endif
