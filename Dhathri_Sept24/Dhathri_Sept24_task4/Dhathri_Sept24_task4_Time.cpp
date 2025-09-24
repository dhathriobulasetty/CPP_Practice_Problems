#include "Dhathri_Sept24_task4_Time.h"
#include <iostream>
#include <iomanip>

// Constructor
Time::Time(int hr, int min, int sec) {
    setTime(hr, min, sec);
}

// Set time (returns false if any part is invalid)
bool Time::setTime(int h, int m, int s) {
    bool okHour   = setHour(h);
    bool okMinute = setMinute(m);
    bool okSecond = setSecond(s);
    return okHour && okMinute && okSecond;
}

// Set hour with validation
bool Time::setHour(int h) {
    if (h >= 0 && h < 24) {
        hour = h;
        return true;
    } else {
        hour = 0;
        return false;
    }
}

// Set minute with validation
bool Time::setMinute(int m) {
    if (m >= 0 && m < 60) {
        minute = m;
        return true;
    } else {
        minute = 0;
        return false;
    }
}

// Set second with validation
bool Time::setSecond(int s) {
    if (s >= 0 && s < 60) {
        second = s;
        return true;
    } else {
        second = 0;
        return false;
    }
}

// Get functions
int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }

// Print universal time (24-hour)
void Time::printUniversal() const {
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":"
              << std::setw(2) << getMinute() << ":"
              << std::setw(2) << getSecond();
}

// Print standard time (12-hour with AM/PM)
void Time::printStandard() const {
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
              << ":" << std::setfill('0') << std::setw(2) << getMinute()
              << ":" << std::setw(2) << getSecond()
              << (hour < 12 ? " AM" : " PM");
}
