#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

// Partition function declaration
int partition(std::vector<int>& arrayValues, int startIndex, int endIndex);

// Recursive quickSort function declaration
void quickSort(std::vector<int>& arrayValues, int startIndex, int endIndex);

#endif 
