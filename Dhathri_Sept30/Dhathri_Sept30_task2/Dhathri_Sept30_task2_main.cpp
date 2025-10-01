#include "Dhathri_Sept30_task2_QuickSort.h"

#include <iostream>

int main()
{
    std::vector<int> arrayValues = {37, 2, 6, 4, 89, 8, 10, 12, 68, 45};

    std::cout << "Original Array: ";
    for (int value : arrayValues)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Apply quicksort
    quickSort(arrayValues, 0, arrayValues.size() - 1);

    std::cout << "Sorted Array: ";
    for (int value : arrayValues)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
