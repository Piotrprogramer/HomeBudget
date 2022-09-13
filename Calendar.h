#ifndef CALENDAR_h
#define CALENDAR_h

#include <iostream>
#include <ctime>
#include <iostream>

using namespace std;

class Calendar {
    struct tm data;
    static bool isLeap(int year);

public:
    static bool isValidDate(int d, int m, int y);
    static tm getCurrentDate();
    static int getCurrentMonth();
};
#endif
