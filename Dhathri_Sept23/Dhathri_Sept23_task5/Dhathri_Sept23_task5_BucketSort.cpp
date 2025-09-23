#include "Dhathri_Sept23_task5_BucketSort.h"
#include <iostream>

void BucketSort::sort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int maxDigits = getMaxDigits(arr);

    // Process each digit place: 1 (ones), 10 (tens), 100 (hundreds), etc.
    for (int place = 1; place <= maxDigits; place *= 10) {
        countingPass(arr, place);
    }
}

int BucketSort::getMaxDigits(const std::vector<int>& arr) {
    // Find maximum element to know how many digits we need
    int maxVal = *std::max_element(arr.begin(), arr.end());

    // Count digits of maxVal
    int digits = 0;
    while (maxVal > 0) {
        ++digits;
        maxVal /= 10;
    }
    return digits;
}

void BucketSort::countingPass(std::vector<int>& arr, int place) {
    int n = arr.size();

    // 10 buckets (0–9), each can hold up to n elements
    std::vector<std::vector<int>> buckets(10, std::vector<int>());

    // Distribution pass: place elements into buckets based on digit
    for (int num : arr) {
        int digit = (num / place) % 10;
        buckets[digit].push_back(num);
    }

    // Gathering pass: copy elements back into arr row by row
    int index = 0;
    for (int i = 0; i < 10; ++i) {
        for (int num : buckets[i]) {
            arr[index++] = num;
        }
    }
}
