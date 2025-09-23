#include "Dhathri_Sept23_task1_DuplicateElimination.h"

// Check if number is already in uniqueNumbers
bool DuplicateElimination::isDuplicate(int number) const {
    for (int num : uniqueNumbers) {
        if (num == number) {
            return true;
        }
    }
    return false;
}

// Add number if not duplicate
void DuplicateElimination::addNumber(int number) {
    if (!isDuplicate(number)) {
        uniqueNumbers.push_back(number);
    }
}

// Return unique numbers
const std::vector<int>& DuplicateElimination::getUniqueNumbers() const {
    return uniqueNumbers;
}
