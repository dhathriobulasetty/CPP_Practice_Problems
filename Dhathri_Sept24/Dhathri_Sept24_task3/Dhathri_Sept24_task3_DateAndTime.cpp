#include "Dhathri_Sept24_task3_DateAndTime.h"
#include <iostream>
#include <iomanip>

// Constructor 
DateAndTime::DateAndTime(int m, int d, int y, int h, int min, int s) {
    setDate(m, d, y);
    setTime(h, min, s);
}

// Date functions
void DateAndTime::setDate(int m, int d, int y) {
    // Validate month (1–12)
    month = (m >= 1 && m <= 12) ? m : 1;

    // Validate year 
    year = (y >= 0) ? y : 2000;

    // Validate day according to month and year
    int maxDay = daysInMonth(month, year);
    day = (d >= 1 && d <= maxDay) ? d : 1;
}

// Check if year is a leap year
bool DateAndTime::isLeapYear(int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

// Return number of days in a given month
int DateAndTime::daysInMonth(int m, int y) const {
    static const int daysPerMonth[12] =
        {31,28,31,30,31,30,31,31,30,31,30,31};

    // February → check leap year
    if (m == 2 && isLeapYear(y)) return 29;

    return daysPerMonth[m - 1];
}

// Move to next day
void DateAndTime::nextDay() {
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;  // new year
        }
    }
}

//Time functions
void DateAndTime::setTime(int h, int m, int s) {
    hour   = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}

// Increment time by 1 second
void DateAndTime::tick() {
    second++;
    if (second == 60) {   // new minute
        second = 0;
        minute++;
        if (minute == 60) {  // new hour
            minute = 0;
            hour++;
            if (hour == 24) {  // new day
                hour = 0;
                nextDay();
            }
        }
    }
}

// Print functions 
// Format: MM/DD/YYYY HH:MM:SS
void DateAndTime::printUniversal() const {
    std::cout << std::setfill('0')
              << std::setw(2) << month << "/"
              << std::setw(2) << day << "/"
              << year << "  "
              << std::setw(2) << hour << ":"
              << std::setw(2) << minute << ":"
              << std::setw(2) << second;
}

// Print in 12-hour format with AM/PM
// Format: MM/DD/YYYY HH:MM:SS AM/PM
void DateAndTime::printStandard() const {
    int displayHour = (hour == 0 || hour == 12) ? 12 : hour % 12;
    std::cout << std::setfill('0')
              << std::setw(2) << month << "/"
              << std::setw(2) << day << "/"
              << year << "  "
              << displayHour << ":"
              << std::setw(2) << minute << ":"
              << std::setw(2) << second
              << (hour < 12 ? " AM" : " PM");
}
