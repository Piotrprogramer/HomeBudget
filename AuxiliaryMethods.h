#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

class AuxiliaryMethods{

    public:
    static string converteIntToString(int integer);                         //checked
    static string converteDoubleToString(double amount);                         //checked
    static string getLine();                                            //checked
    static int converteStringToInt(string integer);                         //checked
    static char getChar();                                               //checked
    static int wczytajLiczbeCalkowita();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static double getDoubleTypeOfNumber();
};
#endif
