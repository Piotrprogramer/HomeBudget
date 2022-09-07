#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H


#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "FileXml.h"
#include "User.h"
#include "AuxiliaryMethods.h"
#include "PlikTekstowy.h"


using namespace std;

class FileWithUsers :public FileXml{

    //string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(User user);
    //User pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    //int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

public:
    FileWithUsers(string FILENAMEWITHUSERS):  FileXml(FILENAMEWITHUSERS) {};

    //void dopiszUzytkownikaDoPliku(User user);
    //void zapiszWszystkichUzytkownikowDoPliku(vector <User> users);
    //vector <user> wczytajUzytkownikowZPliku();
};
#endif
