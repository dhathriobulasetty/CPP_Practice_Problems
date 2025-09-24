#include "Dhathri_Sept24_task4_Time.h"
#include <iostream>

int main() {
    Time t1; // default time

    std::cout << "Initial time (universal): ";
    t1.printUniversal();
    std::cout << "\nInitial time (standard): ";
    t1.printStandard();
    std::cout << "\n\n";

    // Try setting valid time
    if (!t1.setTime(13, 27, 45)) {
        std::cout << "Error: invalid time entered!\n";
    }
    std::cout << "After setting valid time:\n";
    t1.printUniversal();
    std::cout << " (Universal)\n";
    t1.printStandard();
    std::cout << " (Standard)\n\n";

    // Try setting invalid hour
    if (!t1.setHour(25)) {
        std::cout << "Error: invalid HOUR entered!\n";
    }

    // Try setting invalid minute
    if (!t1.setMinute(70)) {
        std::cout << "Error: invalid MINUTE entered!\n";
    }

    // Try setting invalid second
    if (!t1.setSecond(90)) {
        std::cout << "Error: invalid SECOND entered!\n";
    }

    std::cout << "\nTime after invalid attempts:\n";
    t1.printUniversal();
    std::cout << " (Universal)\n";
    t1.printStandard();
    std::cout << " (Standard)\n";

    return 0;
}
