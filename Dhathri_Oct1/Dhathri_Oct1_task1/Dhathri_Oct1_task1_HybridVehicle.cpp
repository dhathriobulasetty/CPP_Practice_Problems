#include "Dhathri_Oct1_task1_HybridVehicle.h"
#include <stdexcept>

// Constructor
HybridVehicle::HybridVehicle(const std::string& vehicleModel, float electricDistance, float gasolineDistance, float fuelUsed)
    : modelName(vehicleModel), electricKm(electricDistance), gasolineKm(gasolineDistance), gasolineUsed(fuelUsed), tripCount(0)
{
    for (int i = 0; i < 10; ++i)
    {
        trips[i] = 0;
    }
}

// Copy constructor
HybridVehicle::HybridVehicle(const HybridVehicle& other)
{
    modelName = other.modelName;
    electricKm = other.electricKm;
    gasolineKm = other.gasolineKm;
    gasolineUsed = other.gasolineUsed;
    tripCount = other.tripCount;
    for (int i = 0; i < 10; ++i)
    {
        trips[i] = other.trips[i];
    }
}

// Assignment operator
HybridVehicle& HybridVehicle::operator=(const HybridVehicle& other)
{
    if (this != &other)
    {
        modelName = other.modelName;
        electricKm = other.electricKm;
        gasolineKm = other.gasolineKm;
        gasolineUsed = other.gasolineUsed;
        tripCount = other.tripCount;
        for (int i = 0; i < 10; ++i)
        {
            trips[i] = other.trips[i];
        }
    }
    return *this;
}

// + operator (combine two vehicles' usage)
HybridVehicle HybridVehicle::operator+(const HybridVehicle& other) const
{
    HybridVehicle result("Combined", electricKm + other.electricKm, gasolineKm + other.gasolineKm, gasolineUsed + other.gasolineUsed);

    // Merge trips (limited to 10 total)
    int index = 0;
    for (int i = 0; i < tripCount && index < 10; ++i)
    {
        result.trips[index++] = trips[i];
    }
    for (int i = 0; i < other.tripCount && index < 10; ++i)
    {
        result.trips[index++] = other.trips[i];
    }
    result.tripCount = index;

    return result;
}

// == operator (compare efficiency)
bool HybridVehicle::operator==(const HybridVehicle& other) const
{
    float efficiency1 = (gasolineUsed > 0.0F) ? (gasolineKm / gasolineUsed) : 0.0F;
    float efficiency2 = (other.gasolineUsed > 0.0F) ? (other.gasolineKm / other.gasolineUsed) : 0.0F;
    return efficiency1 == efficiency2;
}

// Prefix ++ (simulate new trip with dummy 10 km)
HybridVehicle& HybridVehicle::operator++()
{
    if (tripCount < 10)
    {
        trips[tripCount++] = 10; // dummy trip
    }
    return *this;
}

// [] operator (access trip by index)
int& HybridVehicle::operator[](int index)
{
    if (index < 0 || index >= 10)
    {
        throw std::out_of_range("Invalid trip index");
    }
    if (index >= tripCount)
    {
        tripCount = index + 1;
    }
    return trips[index];
}

// () operator (return total distance)
float HybridVehicle::operator()() const
{
    return electricKm + gasolineKm;
}

// float() operator (convert to fuel efficiency)
HybridVehicle::operator float() const
{
    if (gasolineUsed > 0.0F)
    {
        return gasolineKm / gasolineUsed;
    }
    return 0.0F;
}

// << operator (print vehicle details)
std::ostream& operator<<(std::ostream& output, const HybridVehicle& vehicle)
{
    output << "Model: " << vehicle.modelName << "\n"
           << "Electric Distance (km): " << vehicle.electricKm << "\n"
           << "Gasoline Distance (km): " << vehicle.gasolineKm << "\n"
           << "Fuel Used (L): " << vehicle.gasolineUsed << "\n"
           << "Trips: ";
    for (int i = 0; i < vehicle.tripCount; ++i)
    {
        output << vehicle.trips[i] << " ";
    }
    output << "\n";
    return output;
}
