#ifndef HYBRIDVEHICLE_H
#define HYBRIDVEHICLE_H

#include <iostream>
#include <string>

class HybridVehicle
{
private:
    std::string modelName;
    float electricKm;
    float gasolineKm;
    float gasolineUsed;
    int trips[10];          // fixed-size array (max 10 trips)
    int tripCount;          // number of trips taken

public:
    // Constructor
    HybridVehicle(const std::string& vehicleModel, float electricDistance, float gasolineDistance, float fuelUsed);

    // Copy constructor
    HybridVehicle(const HybridVehicle& other);

    // Assignment operator (=)
    HybridVehicle& operator=(const HybridVehicle& other);

    // Operator Overloads
    HybridVehicle operator+(const HybridVehicle& other) const;   // combine usage
    bool operator==(const HybridVehicle& other) const;           // compare efficiency
    HybridVehicle& operator++();                                 // prefix ++ (add dummy trip)
    int& operator[](int index);                                  // subscript operator
    float operator()() const;                                    // function call operator
    explicit operator float() const;                             // type conversion to efficiency
    friend std::ostream& operator<<(std::ostream& output, const HybridVehicle& vehicle); // print details
};

#endif
