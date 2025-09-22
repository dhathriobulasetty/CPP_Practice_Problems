#include "Dhathri_Sept22_task2_Account.h"
#include <iostream>

// Constructor initializes balance with validation
Account::Account(int initialBalance)
{
    if (initialBalance >= 0)
    {
        balance = initialBalance;
    }
    else
    {
        balance = 0;
        std::cout << "Error: Initial balance is invalid. Setting balance to 0." << std::endl;
    }
}

// Function to add an amount to the balance
void Account::credit(int amount)
{
    if (amount > 0)
    {
        balance += amount;
    }
    else
    {
        std::cout << "Error: Credit amount must be positive." << std::endl;
    }
}

// Function to withdraw an amount from the balance
void Account::debit(int amount)
{
    if (amount > balance)
    {
        std::cout << "Debit amount exceeded account balance." << std::endl;
    }
    else if (amount > 0)
    {
        balance -= amount;
    }
    else
    {
        std::cout << "Error: Debit amount must be positive." << std::endl;
    }
}

// Function to get the current balance
int Account::getBalance() const
{
    return balance;
}
