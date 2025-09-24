#include "Dhathri_Sept24_task2_Date.h"
#include <iostream>

int main() {
    std::cout << "Testing nextDay function:\n\n";

    // Case a: Incrementing into the next month
    Date d1(1, 31, 2023); 
    std::cout << "Start date: "; d1.print(); 
    std::cout << std::endl;
    d1.nextDay();
    std::cout << "After increment: "; 
    d1.print();
    std::cout<<std::endl;

    // Case b: Incrementing into the next year
    Date d2(12, 31, 2023);
    std::cout << "\nStart date: "; d2.print(); std::cout<< std::endl;
    d2.nextDay();
    std::cout << "After increment: "; d2.print(); std::cout<< std::endl;

    // Extra: Leap year case
    Date d3(2, 28, 2024); 
    std::cout << "\nStart date: "; d3.print(); std::cout<< std::endl;
    d3.nextDay();
    std::cout << "After increment: "; d3.print(); std::cout<< std::endl;

    // Loop test: printing multiple increments
    std::cout << "\nLoop test starting from 2/27/2024:\n";
    Date d4(2, 27, 2024);
    for (int i = 0; i < 5; i++) {
        d4.print();
        std::cout << std::endl;
        d4.nextDay();
    }

    return 0;
}
