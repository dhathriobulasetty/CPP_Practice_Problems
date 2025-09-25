#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount
{
private:
    double savingsBalance; // Each saver’s deposit balance
    static double annualInterestRate; // Common interest rate for all savers

public:
    // Constructor
    SavingsAccount(double initialBalance);

    // Function to calculate monthly interest
    void calculateMonthlyInterest();

    // Function to display balance
    void displayBalance() const;

    // Static function to modify interest rate
    static void modifyInterestRate(double newRate);
};

#endif // SAVINGSACCOUNT_H
