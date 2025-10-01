#include "Dhathri_Sept30_task2_QuickSort.h"


// Partition function: places pivot at correct position and returns its index
int partition(std::vector<int>& arrayValues, int startIndex, int endIndex)
{
    // Select the first element as the pivot
    int pivot = arrayValues[startIndex];
    int leftIndex = startIndex;
    int rightIndex = endIndex;

    // Keep moving pointers until they meet
    while (leftIndex < rightIndex)
    {
        // Step 1: Move the right pointer leftwards until we find an element smaller than the pivot
        while ((leftIndex < rightIndex) && (arrayValues[rightIndex] >= pivot))
        {
            --rightIndex;
        }

        // If found, place it at the left pointer's position
        if (leftIndex < rightIndex)
        {
            arrayValues[leftIndex] = arrayValues[rightIndex];
            ++leftIndex; // Move left pointer forward
        }

        // Step 2: Move the left pointer rightwards until we find an element greater than the pivot
        while ((leftIndex < rightIndex) && (arrayValues[leftIndex] <= pivot))
        {
            ++leftIndex;
        }

        // If found, place it at the right pointer's position
        if (leftIndex < rightIndex)
        {
            arrayValues[rightIndex] = arrayValues[leftIndex];
            --rightIndex; // Move right pointer backward
        }
    }

    // Finally, place pivot at the correct sorted position
    arrayValues[leftIndex] = pivot;

    // Return the final position of pivot
    return leftIndex;
}

// Recursive quicksort function
void quickSort(std::vector<int>& arrayValues, int startIndex, int endIndex)
{
    // Base condition: only sort if start < end
    if (startIndex < endIndex)
    {
        // Partition the array and get pivot position
        int pivotIndex = partition(arrayValues, startIndex, endIndex);

        // Recursively sort the left subarray (elements before pivot)
        quickSort(arrayValues, startIndex, pivotIndex - 1);

        // Recursively sort the right subarray (elements after pivot)
        quickSort(arrayValues, pivotIndex + 1, endIndex);
    }
}
