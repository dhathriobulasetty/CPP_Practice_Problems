#include "Dhathri_Sept22_task4_HeartRates.h"

// Constructor
HeartRates::HeartRates(const std::string& firstName,
                       const std::string& lastName,
                       int birthMonth,
                       int birthDay,
                       int birthYear)
    : firstName(firstName),
      lastName(lastName),
      birthMonth(birthMonth),
      birthDay(birthDay),
      birthYear(birthYear)
{
}

// Setters 
void HeartRates::setFirstName(const std::string& fname)
{
    firstName = fname;
}

void HeartRates::setLastName(const std::string& lname)
{
    lastName = lname;
}

void HeartRates::setBirthMonth(int month)
{
    birthMonth = (month > 0 && month <= 12) ? month : 1;
}

void HeartRates::setBirthDay(int day)
{
    birthDay = (day > 0 && day <= 31) ? day : 1;
}

void HeartRates::setBirthYear(int year)
{
    birthYear = (year > 0) ? year : 1900;
}

// Getters
std::string HeartRates::getFirstName() const
{
    return firstName;
}

std::string HeartRates::getLastName() const
{
    return lastName;
}

int HeartRates::getBirthMonth() const
{
    return birthMonth;
}

int HeartRates::getBirthDay() const
{
    return birthDay;
}

int HeartRates::getBirthYear() const
{
    return birthYear;
}

// Functional methods
int HeartRates::getAge(int currentMonth, int currentDay, int currentYear) const
{
    int age = currentYear - birthYear;

    if ((currentMonth < birthMonth) ||
        (currentMonth == birthMonth && currentDay < birthDay))
    {
        age--;
    }
    return age;
}

int HeartRates::getMaximumHeartRate(int age) const
{
    return 220 - age;
}

void HeartRates::getTargetHeartRate(int age, int& lowerBound, int& upperBound) const
{
    int maxRate = getMaximumHeartRate(age);
    lowerBound = static_cast<int>(maxRate * 0.50);
    upperBound = static_cast<int>(maxRate * 0.85);
}
