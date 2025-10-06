#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include <string>

class CommissionEmployee
{
private:
    std::string employeeFirstName;
    std::string employeeLastName;
    std::string socialSecurityNumber;
    double grossSales;
    double commissionRate;

public:
    CommissionEmployee(const std::string& firstName,
                       const std::string& lastName,
                       const std::string& ssn,
                       double sales,
                       double rate);

    // Setters
    void setFirstName( const std::string & firstName); // set first name
     void setLastName( const std::string & lastName); // set last name
     void setSocialSecurityNumber( const std::string & ssn); // set SSN
    void setGrossSales(double sales); // set gross sales amount
    void setCommissionRate(double rate);  // set commission rate

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getSocialSecurityNumber() const;
    double getGrossSales() const;
    double getCommissionRate() const;
    
    // Earnings
    double calculateEarnings() const;

    // Display employee details
    void displayEmployeeDetails() const;
};

#endif
