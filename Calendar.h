#ifndef CALENDAR_h
#define CALENDAR_h

#include <iostream>
#include <time.h>


using namespace std;

class Calendar {
    const int MAX_VALID_YR = 9999;
    const int MIN_VALID_YR = 2000;
    struct tm data;

    bool isLeap(int year);

public:
    bool isValidDate(int d, int m, int y);


};
#endif
