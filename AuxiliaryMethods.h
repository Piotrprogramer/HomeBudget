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
    static string converteIntToString(int integer);                     //checked
    static string converteDoubleToString(double amount);                //checked
    static string getLine();                                            //checked
    static int converteStringToInt(string integer);                     //checked
    static double converteStringToDouble(string number);                //checked
    static char getChar();                                              //checked
    static int getDate(string date, int position);                      //checked
    static bool isDateInRange(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);//checked

    static int wczytajLiczbeCalkowita();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static double getDoubleTypeOfNumber();
};
#endif
