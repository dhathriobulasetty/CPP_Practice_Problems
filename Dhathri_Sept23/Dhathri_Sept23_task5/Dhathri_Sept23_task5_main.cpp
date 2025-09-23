#include "Dhathri_Sept23_task5_BucketSort.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {97, 3, 100, 45, 29, 87, 12, 75};

    std::cout << "Original array:\n";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\n";

    // Perform bucket sort
    BucketSort::sort(arr);

    std::cout << "\nSorted array:\n";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
