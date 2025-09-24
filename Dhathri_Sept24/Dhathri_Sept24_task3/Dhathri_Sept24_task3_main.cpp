#include "Dhathri_Sept24_task3_DateAndTime.h"
#include <iostream>

int main() {
    // Start at December 31, 2024, 11:59:58 PM
    DateAndTime dt(12, 31, 2024, 23, 59, 58);

    std::cout << "Initial (Standard): ";
    dt.printStandard();
    std::cout << "\n";

    std::cout << "Initial (Universal): ";
    dt.printUniversal();
    std::cout << "\n\n";

    // Tick forward to show crossing into next day
    for (int i = 0; i < 5; ++i) {
        dt.tick();  // increment by one second
        std::cout << "After tick " << i + 1 << " (Standard): ";
        dt.printStandard();
        std::cout << "\n";
    }

    return 0;
}
