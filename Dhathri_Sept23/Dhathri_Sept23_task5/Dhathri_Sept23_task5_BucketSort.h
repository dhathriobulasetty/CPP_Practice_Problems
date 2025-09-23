#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include <vector>
#include <algorithm> // for std::max

class BucketSort {
public:
    // Perform bucket sort on the given array
    static void sort(std::vector<int>& arr);

private:
    //  To get maximum number of digits in the array
    static int getMaxDigits(const std::vector<int>& arr);

    // Perform one distribution + gathering pass based on digit place
    static void countingPass(std::vector<int>& arr, int place);
};

#endif
