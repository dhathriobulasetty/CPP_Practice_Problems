#include <iostream>
#include "Dhathri_Sept24_task2_Date.h"

// constructor with validation
Date::Date(int m, int d, int y) : month(m), day(d), year(y) {
    validateDate();
}

// ensure date validity
void Date::validateDate() {
    if (month < 1 || month > 12) month = 1; // default to January if invalid
    if (year < 1) year = 2000;              // default to 2000 if invalid

    int maxDay = daysInMonth(month, year);
    if (day < 1 || day > maxDay) day = 1;   // default to 1 if invalid
}

// check if leap year
bool Date::isLeapYear(int y) const {
    return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
}

// return days in month
int Date::daysInMonth(int m, int y) const {
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(y) ? 29 : 28;
        default:
            return 31;
    }
}

// increment date by one day
void Date::nextDay() {
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

// print date mm/dd/yyyy
void Date::print() const {
    std::cout << month << '/' << day << '/' << year;
}
