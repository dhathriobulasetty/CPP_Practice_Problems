#include "Dhathri_Sept22_task3_Invoice.h"
#include <iostream>

// Constructor initializes data members with validation
Invoice::Invoice(const std::string& partNumberInput,
                 const std::string& partDescriptionInput,
                 int quantityInput,
                 int pricePerItemInput)
{
    setPartNumber(partNumberInput);
    setPartDescription(partDescriptionInput);
    setQuantity(quantityInput);
    setPricePerItem(pricePerItemInput);
}

// Set and get functions for part number
void Invoice::setPartNumber(const std::string& partNumberInput)
{
    partNumber = partNumberInput;
}

std::string Invoice::getPartNumber() const
{
    return partNumber;
}

// Set and get functions for part description
void Invoice::setPartDescription(const std::string& partDescriptionInput)
{
    partDescription = partDescriptionInput;
}

std::string Invoice::getPartDescription() const
{
    return partDescription;
}

// Set and get functions for quantity (validate non-negative)
void Invoice::setQuantity(int quantityInput)
{
    if (quantityInput > 0)
    {
        quantity = quantityInput;
    }
    else
    {
        quantity = 0;
        std::cout << "Warning: Invalid quantity. Setting to 0." << std::endl;
    }
}

int Invoice::getQuantity() const
{
    return quantity;
}

// Set and get functions for price per item (validate non-negative)
void Invoice::setPricePerItem(int pricePerItemInput)
{
    if (pricePerItemInput > 0)
    {
        pricePerItem = pricePerItemInput;
    }
    else
    {
        pricePerItem = 0;
        std::cout << "Warning: Invalid price per item. Setting to 0." << std::endl;
    }
}

int Invoice::getPricePerItem() const
{
    return pricePerItem;
}

// Function to calculate invoice amount
int Invoice::getInvoiceAmount() const
{
    return quantity * pricePerItem;
}
