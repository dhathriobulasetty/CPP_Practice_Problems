#ifndef ACCOUNT_H
#define ACCOUNT_H

// Account class definition
class Account
{
public:
    // Constructor that initializes balance with validation
    explicit Account(int initialBalance);

    // Function to add an amount to the balance
    void credit(int amount);

    // Function to withdraw an amount from the balance
    void debit(int amount);

    // Function to get the current balance
    int getBalance() const;

private:
    int balance; // account balance
};

#endif // ACCOUNT_H
