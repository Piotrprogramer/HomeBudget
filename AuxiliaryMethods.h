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
    static string converteIntToString(int integer);
    static string converteDoubleToString(double amount);
    static string getLine();
    static int converteStringToInt(string integer);
    static int getDate(string date, int position);
    static double getDoubleTypeOfNumber();
    static double converteStringToDouble(string number);
    static char getChar();
    static bool isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);

    //static int wczytajLiczbeCalkowita();
    //static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
};
#endif
