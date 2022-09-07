#ifndef PLIK_TEKSTOWY_H
#define PLIK_TEKSTOWY_H

#include <fstream>
#include <iostream>

using namespace std;

class PlikTekstowy{

    protected:
    string const NAZWA_PLIKU;

    public:
    bool czyPlikJestPusty();
    PlikTekstowy(string nazwaPliku): NAZWA_PLIKU(nazwaPliku){};
};
#endif
