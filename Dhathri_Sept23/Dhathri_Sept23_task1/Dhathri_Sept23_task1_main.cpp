#include "Dhathri_Sept23_task1_DuplicateElimination.h"
#include <iostream>


int main() {
    DuplicateElimination de;
    int number;

    std::cout << "Enter 20 numbers between 10 and 100:\n";

    for (int i = 0; i < 20; ++i) {
        std::cin >> number;

        // Validate input
        if (number < 10 || number > 100) {
            std::cout << "Invalid number! Please enter a number between 10 and 100.\n";
            --i; // retry this iteration
            continue;
        }

        // Add if not duplicate
        de.addNumber(number);
    }

    std::cout << "\nUnique numbers entered:\n";
    for (int num : de.getUniqueNumbers()) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
