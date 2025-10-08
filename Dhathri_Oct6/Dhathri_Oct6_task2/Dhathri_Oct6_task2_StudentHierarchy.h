#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

// Base class: Student
class Student
{
protected:
    std::string studentName;   // Stores the name of the student
    std::string studentID;     // Unique identifier for the student
    std::string department;    // Department to which the student belongs
    int age;                   // Age of the student
    double gpa;                // Grade Point Average

public:
    //  Constructor
    Student(const std::string& name, const std::string& id, const std::string& dept, int a, double g)
        : studentName(name), studentID(id), department(dept), age(a), gpa(g) {}

    // Virtual destructor 
    virtual ~Student() {}

    // Virtual function to display student details
    virtual void displayDetails() const;
};


// Derived class: UndergraduateStudent
class UndergraduateStudent : public Student
{
protected:
    std::string major;  // Major subject of the student
    int year;           // Year of study (1–4)

public:
    // Constructor initializing both base and derived class members
    UndergraduateStudent(const std::string& name, const std::string& id, const std::string& dept,
                         int a, double g, const std::string& m, int y)
        : Student(name, id, dept, a, g), major(m), year(y) {}

    // Function to display details of undergraduate students
    void displayDetails() const override;

    // Function for club registration activity
    void registerForClubs() const;

    // Function for internship application activity
    void applyForInternship() const;
};


// Derived class: GraduateStudent
class GraduateStudent : public Student
{
protected:
    std::string researchTopic;   // Research topic of the graduate student
    std::string advisorName;     // Name of the faculty advisor

public:
    // Constructor initializing both base and derived class members
    GraduateStudent(const std::string& name, const std::string& id, const std::string& dept,
                    int a, double g, const std::string& topic, const std::string& advisor)
        : Student(name, id, dept, a, g), researchTopic(topic), advisorName(advisor) {}

    // Function to display details of graduate students
    void displayDetails() const override;

    // Function to simulate thesis submission
    void submitThesis() const;

    // Function to represent assisting a professor 
    void assistProfessor() const;
};


// Subclasses of UndergraduateStudent(Freshman,Sophomore,Junior,Senior)
class Freshman : public UndergraduateStudent
{
public:
    Freshman(const std::string& name, const std::string& id, const std::string& dept,
             int a, double g, const std::string& m)
        : UndergraduateStudent(name, id, dept, a, g, m, 1) {}

    void displayDetails() const override;
};

class Sophomore : public UndergraduateStudent
{
public:
    Sophomore(const std::string& name, const std::string& id, const std::string& dept,
              int a, double g, const std::string& m)
        : UndergraduateStudent(name, id, dept, a, g, m, 2) {}

    void displayDetails() const override;
};

class Junior : public UndergraduateStudent
{
public:
    Junior(const std::string& name, const std::string& id, const std::string& dept,
           int a, double g, const std::string& m)
        : UndergraduateStudent(name, id, dept, a, g, m, 3) {}

    void displayDetails() const override;
};

class Senior : public UndergraduateStudent
{
public:
    Senior(const std::string& name, const std::string& id, const std::string& dept,
           int a, double g, const std::string& m)
        : UndergraduateStudent(name, id, dept, a, g, m, 4) {}

    void displayDetails() const override;
};


// Subclasses of GraduateStudent(MastersStudent,DoctoralStudent)
class MastersStudent : public GraduateStudent
{
public:
    MastersStudent(const std::string& name, const std::string& id, const std::string& dept,
                   int a, double g, const std::string& topic, const std::string& advisor)
        : GraduateStudent(name, id, dept, a, g, topic, advisor) {}

    void displayDetails() const override;
};

class DoctoralStudent : public GraduateStudent
{
public:
    DoctoralStudent(const std::string& name, const std::string& id, const std::string& dept,
                    int a, double g, const std::string& topic, const std::string& advisor)
        : GraduateStudent(name, id, dept, a, g, topic, advisor) {}

    void displayDetails() const override;
};

#endif
