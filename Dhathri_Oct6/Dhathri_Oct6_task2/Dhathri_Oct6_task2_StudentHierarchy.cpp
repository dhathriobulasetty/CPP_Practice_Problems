#include "Dhathri_Oct6_task2_StudentHierarchy.h"

// Base Class: Student
// Function to display details of a student
void Student::displayDetails() const
{
    std::cout << "Name: " << studentName << "\n"
              << "ID: " << studentID << "\n"
              << "Department: " << department << "\n"
              << "Age: " << age << "\n"
              << "GPA: " << gpa << "\n";
}


// Derived Class: UndergraduateStudent
// Displays details specific to undergraduate students.
void UndergraduateStudent::displayDetails() const
{
    Student::displayDetails();
    std::cout << "Major: " << major << "\n"
              << "Year: " << year << "\n";
}

// Function for club registration activity
void UndergraduateStudent::registerForClubs() const
{
    std::cout << studentName << " has registered for college clubs.\n";
}

// Function for internship application activity
void UndergraduateStudent::applyForInternship() const
{
    std::cout << studentName << " has applied for an internship.\n";
}


// Derived Class: GraduateStudent
// Displays details specific to graduate students.
void GraduateStudent::displayDetails() const
{
    Student::displayDetails();
    std::cout << "Research Topic: " << researchTopic << "\n"
              << "Advisor: " << advisorName << "\n";
}

// Function to simulate thesis submission.
void GraduateStudent::submitThesis() const
{
    std::cout << studentName << " has submitted the thesis on '" << researchTopic << "'.\n";
}

// Function to represent assisting a professor 
void GraduateStudent::assistProfessor() const
{
    std::cout << studentName << " is assisting " << advisorName << " in research work.\n";
}


// Subclasses of UndergraduateStudent

void Freshman::displayDetails() const
{
    std::cout << "\n[Freshman Details]\n";
    UndergraduateStudent::displayDetails();
}

void Sophomore::displayDetails() const
{
    std::cout << "\n[Sophomore Details]\n";
    UndergraduateStudent::displayDetails();
}

void Junior::displayDetails() const
{
    std::cout << "\n[Junior Details]\n";
    UndergraduateStudent::displayDetails();
}

void Senior::displayDetails() const
{
    std::cout << "\n[Senior Details]\n";
    UndergraduateStudent::displayDetails();
}


// Subclasses of GraduateStudent

void MastersStudent::displayDetails() const
{
    std::cout << "\n[Masters Student Details]\n";
    GraduateStudent::displayDetails();
}

void DoctoralStudent::displayDetails() const
{
    std::cout << "\n[Doctoral Student Details]\n";
    GraduateStudent::displayDetails();
}


