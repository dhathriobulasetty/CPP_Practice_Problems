#include <iostream>
#include "Dhathri_Sept26_task4_RationalNumber.h"

int main() {
    RationalNumber r1(3, 4);   // 3/4
    RationalNumber r2(2, 5);   // 2/5

    std::cout << "r1 = " << r1 << "\n";
    std::cout << "r2 = " << r2 << "\n\n";

    std::cout << "r1 + r2 = " << (r1 + r2) << "\n";
    std::cout << "r1 - r2 = " << (r1 - r2) << "\n";
    std::cout << "r1 * r2 = " << (r1 * r2) << "\n";
    std::cout << "r1 / r2 = " << (r1 / r2) << "\n\n";

    std::cout << "Comparisons:\n";
    std::cout << "r1 == r2: " << (r1 == r2) << "\n";
    std::cout << "r1 != r2: " << (r1 != r2) << "\n";
    std::cout << "r1 < r2: " << (r1 < r2) << "\n";
    std::cout << "r1 <= r2: " << (r1 <= r2) << "\n";
    std::cout << "r1 > r2: " << (r1 > r2) << "\n";
    std::cout << "r1 >= r2: " << (r1 >= r2) << "\n\n";

    std::cout << "Enter a rational number (format n/d): ";
    RationalNumber r3;
    std::cin >> r3;

    if (!std::cin.fail()) {
        std::cout << "You entered: " << r3 << "\n";
    } else {
        std::cout << "Invalid input.\n";
    }

    return 0;
}
