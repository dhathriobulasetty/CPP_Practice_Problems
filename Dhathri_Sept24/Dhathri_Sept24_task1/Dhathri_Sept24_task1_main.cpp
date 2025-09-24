#include "Dhathri_Sept24_task1_EnhancingTime.h"
#include <iostream>

int main()
{
    Time t1(12, 30, 58); // Case A: Incrementing into the next minute
    std::cout << "Case A: Incrementing into the next minute\n";
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Universal: ";
        t1.printUniversal();
        std::cout << "   Standard: ";
        t1.printStandard();
        std::cout << std::endl;
        t1.tick();
    }

    std::cout << "\nCase B: Incrementing into the next hour\n";
    Time t2(1, 59, 58); 
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Universal: ";
        t2.printUniversal();
        std::cout << "   Standard: ";
        t2.printStandard();
        std::cout << std::endl;
        t2.tick();
    }

    std::cout << "\nCase C: Incrementing into the next day\n";
    Time t3(23, 59, 58); 
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Universal: ";
        t3.printUniversal();
        std::cout << "   Standard: ";
        t3.printStandard();
        std::cout << std::endl;
        t3.tick();
    }

    return 0;
}
