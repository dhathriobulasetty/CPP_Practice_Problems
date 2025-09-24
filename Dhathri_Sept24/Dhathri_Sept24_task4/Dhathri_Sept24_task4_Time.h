#ifndef TIME_H
#define TIME_H

// Time class definition
class Time {
public:
    // Constructor with default values
    Time(int = 0, int = 0, int = 0);

    // Set functions (return bool for error checking)
    bool setTime(int, int, int); // set hour, minute, second
    bool setHour(int);           // set hour (validate)
    bool setMinute(int);         // set minute (validate)
    bool setSecond(int);         // set second (validate)

    // Get functions
    int getHour() const;   // return hour
    int getMinute() const; // return minute
    int getSecond() const; // return second

    // Print functions
    void printUniversal() const; // print in HH:MM:SS (24-hour)
    void printStandard() const;  // print in HH:MM:SS AM/PM

private:
    int hour;   // 0–23
    int minute; // 0–59
    int second; // 0–59
};

#endif
