#include <iostream>
#include <cstddef>   // for std::size_t (standard type for array sizes)

// a) Declare symbolic constant SIZE
const std::size_t SIZE = 5U;

int main()
{
    // a) Declare an array of type unsigned int called values with five elements,initialized to even integers from 2 to 10
    unsigned int values[SIZE] = {2U, 4U, 6U, 8U, 10U};

    // b) Declare a pointer vPtr that points to unsigned int
    unsigned int* vPtr = nullptr;

    // c) Use array subscript notation to print the elements
    std::cout << "Array elements using subscript notation:\n";
    for (std::size_t i = 0U; i < SIZE; ++i)
    {
        std::cout << "values[" << i << "] = " << values[i] << '\n';
    }

    // d) Assign the starting address of array values to vPtr (two ways)
    vPtr = values;       // Array name decays to address of first element
    vPtr = &values[0];   // Explicitly take address of first element

    // e) Print elements using pointer/offset notation with vPtr
    std::cout << "\nArray elements using pointer/offset notation (vPtr + i):\n";
    for (std::size_t offset = 0U; offset < SIZE; ++offset)
    {
        std::cout << "*(vPtr + " << offset << ") = " << *(vPtr + offset) << '\n';
    }

    // f) Print elements using pointer/offset notation with array name as the pointer
    std::cout << "\nArray elements using pointer/offset notation (values + i):\n";
    for (std::size_t offset = 0U; offset < SIZE; ++offset)
    {
        std::cout << "*(values + " << offset << ") = " << *(values + offset) << '\n';
    }

    // g) Print elements by subscripting the pointer
    std::cout << "\nArray elements using pointer subscript notation vPtr[i]:\n";
    for (std::size_t i = 0U; i < SIZE; ++i)
    {
        std::cout << "vPtr[" << i << "] = " << vPtr[i] << '\n';
    }

    // h) Refer to the fifth element of values in four different ways
    std::cout << "\nFifth element of values:\n";
    std::cout << "values[4] = " << values[4] << " (array subscript)\n";
    std::cout << "*(values + 4) = " << *(values + 4) << " (pointer/offset with array name)\n";
    std::cout << "vPtr[4] = " << vPtr[4] << " (pointer subscript)\n";
    std::cout << "*(vPtr + 4) = " << *(vPtr + 4) << " (pointer/offset with pointer)\n";

    // i) Address referenced by vPtr + 3 and value stored there
    std::cout << "\nAddress referenced by vPtr + 3: " << (vPtr + 3) << '\n';
    std::cout << "Value stored at that location: " << *(vPtr + 3) << '\n';

    // j) Assuming that vPtr points to values[4], evaluate vPtr -= 4
    vPtr = &values[4];  // Point to fifth element
    vPtr -= 4;          // Move back 4 positions, now points to values[0]
    std::cout << "\nAfter vPtr points to values[4] and vPtr -= 4:\n";
    std::cout << "Address referenced: " << vPtr << '\n';
    std::cout << "Value stored at that location: " << *vPtr << '\n';

    return 0;
}
