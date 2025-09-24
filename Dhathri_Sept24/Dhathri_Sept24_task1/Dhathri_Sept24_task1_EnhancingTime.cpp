#include "Dhathri_Sept24_task1_EnhancingTime.h"
#include <iostream>
#include <iomanip>
 
// Time constructor initializes each data member to zero;
// ensures that Time objects start in a consistent state 
Time::Time(int hr, int min, int sec)
{
    setTime(hr, min, sec); // validate and set time
} // end Time constructor      

// set new Time value using universal time; ensure that
// the data remains consistent by setting invalid values to zero
void Time::setTime(int h, int m, int s)
{
    setHour(h);   // set private field hour
    setMinute(m); // set private field minute
    setSecond(s); // set private field second
} // end function setTime

// set hour value
void Time::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0; // validate hour
} // end function setHour

// set minute value
void Time::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0; // validate minute
} // end function setMinute

// set second value
void Time::setSecond(int s)
{
    second = (s >= 0 && s < 60) ? s : 0; // validate second
} // end function setSecond

// return hour value
int Time::getHour()
{
    return hour;
} // end function getHour

// return minute value
int Time::getMinute()
{
    return minute;
} // end function getMinute

// return second value
int Time::getSecond()
{
    return second;
} // end function getSecond

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal()
{
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":"
              << std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond();
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard()
{
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
              << ":" << std::setfill('0') << std::setw(2) << getMinute()
              << ":" << std::setw(2) << getSecond()
              << (hour < 12 ? " AM" : " PM");
} // end function printStandard

// increment time by one second
void Time::tick()
{
    second++;

    if (second == 60)
    {
        second = 0;
        minute++;

        if (minute == 60)
        {
            minute = 0;
            hour++;

            if (hour == 24)
            {
                hour = 0; // next day
            }
        }
    }
} // end function tick
