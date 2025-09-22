#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>

// GradeBook class definition
class GradeBook
{
public:
    // Constructor that initializes courseName and instructorName
    GradeBook(const std::string& courseName, const std::string& instructorName);

    // Function to set the course name
    void setCourseName(const std::string& courseName);

    // Function to get the course name
    std::string getCourseName() const;

    // Function to set the instructor name
    void setInstructorName(const std::string& instructorName);

    // Function to get the instructor name
    std::string getInstructorName() const;

    // Function to display welcome message
    void displayMessage() const;

private:
    std::string courseName;     // Course name for this GradeBook
    std::string instructorName; // Instructor name for this GradeBook
};

#endif // GRADEBOOK_H
