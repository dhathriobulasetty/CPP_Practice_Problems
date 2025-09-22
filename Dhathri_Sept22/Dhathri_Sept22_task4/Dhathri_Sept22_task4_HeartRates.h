#ifndef HEARTRATES_H
#define HEARTRATES_H

#include <string>

class HeartRates
{
public:
    // Constructor
    explicit HeartRates(const std::string& firstName,
                        const std::string& lastName,
                        int birthMonth,
                        int birthDay,
                        int birthYear);

    // Setters
    void setFirstName(const std::string& fname);
    void setLastName(const std::string& lname);
    void setBirthMonth(int month);
    void setBirthDay(int day);
    void setBirthYear(int year);

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    int getBirthMonth() const;
    int getBirthDay() const;
    int getBirthYear() const;

    // Functional methods
    int getAge(int currentMonth, int currentDay, int currentYear) const;
    int getMaximumHeartRate(int age) const;
    void getTargetHeartRate(int age, int& lowerBound, int& upperBound) const;

private:
    std::string firstName;
    std::string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;
};

#endif // HEARTRATES_H
