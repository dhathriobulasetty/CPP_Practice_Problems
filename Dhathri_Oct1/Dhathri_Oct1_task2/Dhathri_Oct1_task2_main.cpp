#include "Dhathri_Oct1_task2_BatteryMonitor.h"
#include <iostream>

int main()
{
    // Create two BatteryMonitor objects
    BatteryMonitor s1("SCT101", 300, 4.0F, 5.0F, true, 3);  // 80% health
    BatteryMonitor s2("SCT202", 150, 3.5F, 5.0F, true, 2);  // 70% health

    // Populate trips using []
    s1[0] = 12; s1[1] = 18; s1[2] = 25;
    s2[0] = 10; s2[1] = 15;

    // Display both using <<
    std::cout << "Scooter 1:\n" << s1 << "\n";
    std::cout << "Scooter 2:\n" << s2 << "\n";

    // Use > and < to compare battery health
    if (s1 > s2)
    {
        std::cout << "Scooter 1 has better battery health.\n\n";
    }
    else if (s1 < s2)
    {
        std::cout << "Scooter 2 has better battery health.\n\n";
    }
    else
    {
        std::cout << "Both scooters have equal battery health.\n\n";
    }

    // Use += to simulate 50 charge cycles
    s1 += 50;
    std::cout << "Scooter 1 after 50 more cycles:\n" << s1 << "\n";

    // Use ! to check inactive status
    if (!s1)
    {
        std::cout << "Scooter 1 is inactive.\n\n";
    }
    else
    {
        std::cout << "Scooter 1 is active.\n\n";
    }

    // Use = to copy one scooter to another
    BatteryMonitor s3("TEMP", 0, 0.0F, 0.0F, false, 0);
    s3 = s2; // assignment operator
    std::cout << "Scooter 3 (copied from Scooter 2):\n" << s3 << "\n";

    // Destructor will be called automatically when objects go out of scope
    return 0;
}
