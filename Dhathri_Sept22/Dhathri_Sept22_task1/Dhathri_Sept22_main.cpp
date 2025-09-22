#include "Dhathri_Sept22_GradeBook.h"
#include <iostream>

int main()
{
    // Create GradeBook object with course and instructor names
    GradeBook myGradeBook("C++ Programming", "Dr. Smith");

    // Display initial message
    myGradeBook.displayMessage();

    std::cout << "\nUpdating course and instructor names...\n" << std::endl;

    // Update course and instructor names
    myGradeBook.setCourseName("Advanced C++ Programming");
    myGradeBook.setInstructorName("Prof. Johnson");

    // Display updated message
    myGradeBook.displayMessage();

    return 0;
}

