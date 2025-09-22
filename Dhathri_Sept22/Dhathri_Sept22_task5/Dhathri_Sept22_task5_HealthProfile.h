#ifndef HEALTHPROFILE_H
#define HEALTHPROFILE_H

#include <string>

class HealthProfile {
private:
    std::string firstName;
    std::string lastName;
    std::string gender;
    int birthDay;
    int birthMonth;
    int birthYear;
    int heightInInches;
    int weightInPounds;

public:
    // Constructor
    HealthProfile(const std::string& fName, const std::string& lName, const std::string& gen,
                  int day, int month, int year, int height, int weight);

    // Setters
    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);
    void setGender(const std::string& gen);
    void setBirthDay(int day);
    void setBirthMonth(int month);
    void setBirthYear(int year);
    void setHeight(int height);
    void setWeight(int weight);

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getGender() const;
    int getBirthDay() const;
    int getBirthMonth() const;
    int getBirthYear() const;
    int getHeight() const;
    int getWeight() const;

    // Calculations
    int getAge(int currentDay, int currentMonth, int currentYear) const;
    int getMaximumHeartRate(int age) const;
    void getTargetHeartRateRange(int age, int& lower, int& upper) const;
    double getBMI() const;
};

#endif
