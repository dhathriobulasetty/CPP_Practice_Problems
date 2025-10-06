#include "Dhathri_Oct6_Task1_CommissionEmployee.h"
#include <iostream>

CommissionEmployee::CommissionEmployee(const std::string& firstName,
                                       const std::string& lastName,
                                       const std::string& ssn,
                                       double sales,
                                       double rate)
    : employeeFirstName(firstName),
      employeeLastName(lastName),
      socialSecurityNumber(ssn),
      grossSales(0.0),
      commissionRate(0.0)
{
    setGrossSales(sales);  // validate and store gross sales
    setCommissionRate(rate);  // validate and store commission rate
}

// set first name
void CommissionEmployee::setFirstName( const std::string &firstname )
 {
   employeeFirstName = firstname; 
 } 
 
// return first name
std::string CommissionEmployee::getFirstName() const
  {
   return employeeFirstName;
  } 
 
// set last name
void CommissionEmployee::setLastName( const std::string &lastname )
  {
   employeeLastName = lastname; 
  } 
 
// return last name
std::string CommissionEmployee::getLastName() const
  {
   return employeeLastName;
  } 
 
// set social security number
void CommissionEmployee::setSocialSecurityNumber( const std::string &ssn )
  {
    socialSecurityNumber = ssn; 
  } 
 
// return social security number
std::string CommissionEmployee::getSocialSecurityNumber() const
  {
    return socialSecurityNumber;
  } 

// set gross sales amount
void CommissionEmployee::setGrossSales(double sales)
{
    grossSales = ( sales < 0.0 ) ? 0.0 : sales;
}

// return gross sales amount
double CommissionEmployee::getGrossSales() const
{
    return grossSales;
}

// set commission rate
void CommissionEmployee::setCommissionRate(double rate)
{
    commissionRate = ( rate > 0.0 && rate < 1.0 ) ? rate : 0.0;
}

// return commission rate
double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
}

// calculate earnings
double CommissionEmployee::calculateEarnings() const
{
    return getGrossSales() * getCommissionRate();
}

// print CommissionEmployee object
void CommissionEmployee::displayEmployeeDetails() const
{
    std::cout << "Employee Name: " << employeeFirstName << " " << employeeLastName << "\n";
    std::cout << "social security number: " << socialSecurityNumber << "\n";
    std::cout << "Gross Sales: " << grossSales << "\n";
    std::cout << "Commission Rate: " << commissionRate << "\n";
}
