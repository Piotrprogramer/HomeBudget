#include "PlikTekstowy.h"

using namespace std;

bool PlikTekstowy::czyPlikJestPusty(){
    ifstream plikTekstowy( NAZWA_PLIKU.c_str(), ios::in);
    plikTekstowy.seekg(0, ios::end);

    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}
