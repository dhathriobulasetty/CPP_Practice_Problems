#ifndef DATE_H
#define DATE_H

class Date {
public:
    Date(int m = 1, int d = 1, int y = 2000); // constructor with validation
    void print() const;                       // print date mm/dd/yyyy
    void nextDay();                           // increment date by one day

private:
    int month;
    int day;
    int year;

    bool isLeapYear(int y) const;             // check leap year
    int daysInMonth(int m, int y) const;      // get days in given month/year
    void validateDate();                      // ensure date is valid
};

#endif // DATE_H
