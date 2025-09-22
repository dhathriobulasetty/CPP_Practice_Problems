#include "GradeBook.h"
#include <iostream>

// Constructor initializes courseName and instructorName
GradeBook::GradeBook(const std::string& courseName, const std::string& instructorName)
{
    setCourseName(courseName);
    setInstructorName(instructorName);
}

// Function to set the course name with validation
void GradeBook::setCourseName(const std::string& courseNameInput)
{
    if (!courseNameInput.empty())
    {
        courseName = courseNameInput;
    }
    else
    {
        courseName = "Unknown Course";
    }
}

// Function to get the course name
std::string GradeBook::getCourseName() const
{
    return courseName;
}

// Function to set the instructor name with validation
void GradeBook::setInstructorName(const std::string& instructorNameInput)
{
    if (!instructorNameInput.empty())
    {
        instructorName = instructorNameInput;
    }
    else
    {
        instructorName = "Unknown Instructor";
    }
}

// Function to get the instructor name
std::string GradeBook::getInstructorName() const
{
    return instructorName;
}

// Display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
    std::cout << "Welcome to the grade book for\n" 
              << getCourseName() << "!" << std::endl;
    std::cout << "This course is presented by: " 
              << getInstructorName() << std::endl;
}
