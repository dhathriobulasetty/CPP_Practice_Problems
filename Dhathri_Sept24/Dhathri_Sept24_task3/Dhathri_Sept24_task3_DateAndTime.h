#ifndef DATEANDTIME_H
#define DATEANDTIME_H

class DateAndTime {
public:
    // Constructor with default values
    DateAndTime(int m = 1, int d = 1, int y = 2000,
                int h = 0, int min = 0, int s = 0);

    // Set functions
    void setDate(int m, int d, int y);   // set month, day, year
    void setTime(int h, int m, int s);   // set hour, minute, second

    // Increment time by 1 second
    void tick();

    // Print functions
    void printUniversal() const;  // print in 24-hour format
    void printStandard() const;   // print in 12-hour format

private:
    // Data members
    int month;
    int day;
    int year;
    int hour;
    int minute;
    int second;

    bool isLeapYear(int y) const;       // check leap year
    int daysInMonth(int m, int y) const; // return number of days in a month
    void nextDay();                     // go to next day
};

#endif
