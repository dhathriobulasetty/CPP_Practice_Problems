#ifndef BATTERYMONITOR_H
#define BATTERYMONITOR_H

#include <iostream>
#include <string>

class BatteryMonitor
{
private:
    std::string scooterID;
    int chargeCycles;
    float batteryCapacity;
    float originalCapacity;
    bool isActive;
    int* tripDistances;   // dynamically allocated array
    int tripCount;        // number of trips

public:
    // Constructor
    BatteryMonitor(const std::string& id, int cycles, float capacity, float originalCap, bool active, int trips);

    // Copy constructor (deep copy)
    BatteryMonitor(const BatteryMonitor& other);

    // Assignment operator (deep copy with self-assignment check)
    BatteryMonitor& operator=(const BatteryMonitor& other);

    // Destructor
    ~BatteryMonitor();

    // Operator Overloads
    bool operator>(const BatteryMonitor& other) const;   // compare health ratio
    bool operator<(const BatteryMonitor& other) const;   // compare health ratio
    BatteryMonitor& operator+=(int cycles);              // simulate charge cycles and degradation
    int& operator[](int index);                          // access trip by index
    bool operator!() const;                              // check inactive
    friend std::ostream& operator<<(std::ostream& os, const BatteryMonitor& scooter); // print details
};

#endif
