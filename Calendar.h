#ifndef CALENDAR_h
#define CALENDAR_h

#include <iostream>
//#include <time.h>
#include <ctime>
#include <iostream>

using namespace std;

class Calendar {
 //   const int MAX_VALID_YR = 9999;
 //   const int MIN_VALID_YR = 2000;
    struct tm data;

    static bool isLeap(int year);

public:
    static bool isValidDate(int d, int m, int y);
    static tm getCurrentDate();

};
#endif
