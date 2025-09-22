#ifndef INVOICE_H
#define INVOICE_H

#include <string>

// Invoice class definition
class Invoice
{
public:
    // Constructor that initializes all data members with validation
    Invoice(const std::string& partNumber,
            const std::string& partDescription,
            int quantity,
            int pricePerItem);

    // Set and get functions for part number
    void setPartNumber(const std::string& partNumber);
    std::string getPartNumber() const;

    // Set and get functions for part description
    void setPartDescription(const std::string& partDescription);
    std::string getPartDescription() const;

    // Set and get functions for quantity
    void setQuantity(int quantity);
    int getQuantity() const;

    // Set and get functions for price per item
    void setPricePerItem(int pricePerItem);
    int getPricePerItem() const;

    // Function to calculate invoice amount
    int getInvoiceAmount() const;

private:
    std::string partNumber;       // Part number
    std::string partDescription;  // Part description
    int quantity;                 // Quantity of items
    int pricePerItem;             // Price per item
};

#endif // INVOICE_H
