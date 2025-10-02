#include "Dhathri_Oct1_task2_BatteryMonitor.h"
#include <stdexcept> // for std::out_of_range

// Constructor
BatteryMonitor::BatteryMonitor(const std::string& id, int cycles, float capacity, float originalCap, bool active, int trips)
    : scooterID(id), chargeCycles(cycles), batteryCapacity(capacity), originalCapacity(originalCap), isActive(active), tripCount(trips)
{
    if (tripCount > 0)
    {
        tripDistances = new int[tripCount];
        for (int i = 0; i < tripCount; ++i)
        {
            tripDistances[i] = 0; // initialize with 0
        }
    }
    else
    {
        tripDistances = nullptr;
    }
}

// Copy constructor (deep copy)
BatteryMonitor::BatteryMonitor(const BatteryMonitor& other)
{
    scooterID = other.scooterID;
    chargeCycles = other.chargeCycles;
    batteryCapacity = other.batteryCapacity;
    originalCapacity = other.originalCapacity;
    isActive = other.isActive;
    tripCount = other.tripCount;

    if (tripCount > 0)
    {
        tripDistances = new int[tripCount];
        for (int i = 0; i < tripCount; ++i)
        {
            tripDistances[i] = other.tripDistances[i];
        }
    }
    else
    {
        tripDistances = nullptr;
    }
}

// Assignment operator (deep copy with self-assignment check)
BatteryMonitor& BatteryMonitor::operator=(const BatteryMonitor& other)
{
    if (this != &other) // self-assignment check
    {
        // Free existing memory
        delete[] tripDistances;

        scooterID = other.scooterID;
        chargeCycles = other.chargeCycles;
        batteryCapacity = other.batteryCapacity;
        originalCapacity = other.originalCapacity;
        isActive = other.isActive;
        tripCount = other.tripCount;

        if (tripCount > 0)
        {
            tripDistances = new int[tripCount];
            for (int i = 0; i < tripCount; ++i)
            {
                tripDistances[i] = other.tripDistances[i];
            }
        }
        else
        {
            tripDistances = nullptr;
        }
    }
    return *this;
}

// Destructor 
BatteryMonitor::~BatteryMonitor()
{
    delete[] tripDistances;
    tripDistances = nullptr;
}

// > operator (compare health ratio)
bool BatteryMonitor::operator>(const BatteryMonitor& other) const
{
    float health1 = (originalCapacity > 0.0F) ? (batteryCapacity / originalCapacity) : 0.0F;
    float health2 = (other.originalCapacity > 0.0F) ? (other.batteryCapacity / other.originalCapacity) : 0.0F;
    return health1 > health2;
}

// < operator (compare health ratio)
bool BatteryMonitor::operator<(const BatteryMonitor& other) const
{
    float health1 = (originalCapacity > 0.0F) ? (batteryCapacity / originalCapacity) : 0.0F;
    float health2 = (other.originalCapacity > 0.0F) ? (other.batteryCapacity / other.originalCapacity) : 0.0F;
    return health1 < health2;
}

// += operator (simulate charge cycles and degradation)
BatteryMonitor& BatteryMonitor::operator+=(int cycles)
{
    chargeCycles += cycles;

    // simulate degradation: lose 0.1 kWh per 50 cycles
    float degradation = (static_cast<float>(cycles) / 50.0F) * 0.1F;
    batteryCapacity -= degradation;

    if (batteryCapacity < 0.0F)
    {
        batteryCapacity = 0.0F;
        isActive = false; // dead battery
    }

    return *this;
}

// [] operator (access trip distance)
int& BatteryMonitor::operator[](int index)
{
    if (index < 0 || index >= tripCount)
    {
        throw std::out_of_range("Invalid trip index");
    }
    return tripDistances[index];
}

// ! operator (check inactive)
bool BatteryMonitor::operator!() const
{
    return !isActive;
}

// << operator (print details)
std::ostream& operator<<(std::ostream& os, const BatteryMonitor& scooter)
{
    float health = (scooter.originalCapacity > 0.0F) 
                     ? (scooter.batteryCapacity / scooter.originalCapacity) * 100.0F 
                     : 0.0F;

    os << "Scooter ID: " << scooter.scooterID << "\n"
       << "Charge Cycles: " << scooter.chargeCycles << "\n"
       << "Battery Capacity: " << scooter.batteryCapacity << " kWh\n"
       << "Original Capacity: " << scooter.originalCapacity << " kWh\n"
       << "Battery Health: " << health << "%\n"
       << "Status: " << (scooter.isActive ? "Active" : "Inactive") << "\n"
       << "Trips: ";
    for (int i = 0; i < scooter.tripCount; ++i)
    {
        os << scooter.tripDistances[i] << " ";
    }
    os << "\n";

    return os;
}
