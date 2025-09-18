#include <iostream>
#include <cstdint>
#include <limits>

using uint32 = std::uint32_t;

class TrackedVehicle {
public:
    uint32 vehicle_id;
    float speed;    
    float distance; 

    // static members
    static float min_recorded_distance;
    static int vehicle_count;

    // Constructor
    TrackedVehicle(uint32 id = 0u, float spd = 0.0f, float dist = std::numeric_limits<float>::infinity())
        : vehicle_id(id), speed(spd), distance(dist)
    {
        // Update static members
        ++vehicle_count;
        if (distance < min_recorded_distance) {
            min_recorded_distance = distance;
        }
    }

    void display() const
    {
        std::cout << "Vehicle ID: " << vehicle_id
                  << " | Speed: " << speed << " km/h"
                  << " | Distance: " << distance << " m\n";
    }

    // Compare two vehicles and return pointer to the one with smaller distance.
    // In case of tie, return current object (this).
    const TrackedVehicle* compareDistance(const TrackedVehicle& other) const
    {
        if (this->distance <= other.distance) {
            return this;
        }
        return &other;
    }

    static float getMinRecordedDistance()
    {
        return min_recorded_distance;
    }
    static int getVehicleCount()
    {
        return vehicle_count;
    }
};

// Static members initialization
float TrackedVehicle::min_recorded_distance = std::numeric_limits<float>::infinity();
int TrackedVehicle::vehicle_count = 0;

// Uses compareDistance to find lead vehicle
void findLeadVehicle(TrackedVehicle* arr, uint32 size, const TrackedVehicle*& lead)
{
    if (arr == nullptr || size == 0u) {
        lead = nullptr;
        return;
    }

    const TrackedVehicle* minPtr = &arr[0];
    for (uint32 i = 1u; i < size; ++i) {
        minPtr = minPtr->compareDistance(arr[i]); // reuse compareDistance
    }
    lead = minPtr;
}

void printTrackedVehicle(const TrackedVehicle& vehicle)
{
    vehicle.display();
}

void printLeadVehicle(const TrackedVehicle* lead)
{
    if (lead == nullptr) {
        std::cout << "Lead vehicle: None found\n";
    } else {
        std::cout << "*** Lead Vehicle ***\n";
        lead->display();
    }
}

int main()
{
    const uint32 count = 4u;
    TrackedVehicle* vehicles = new TrackedVehicle[count] {
        TrackedVehicle(501u, 80.0f, 60.0f),
        TrackedVehicle(502u, 78.0f, 45.0f),
        TrackedVehicle(503u, 85.0f, 100.0f),
        TrackedVehicle(504u, 76.0f, 40.0f)
    };

    std::cout << "All tracked vehicles:\n";
    for (uint32 i = 0u; i < count; ++i) {
        printTrackedVehicle(vehicles[i]);
    }

    const TrackedVehicle* lead = nullptr;
    findLeadVehicle(vehicles, count, lead);
    printLeadVehicle(lead);

    std::cout << "Minimum recorded distance across all vehicles: "
              << TrackedVehicle::getMinRecordedDistance() << " m\n";
    std::cout << "Total number of tracked vehicles created: "
              << TrackedVehicle::getVehicleCount() << "\n";

    delete [] vehicles;
    vehicles = nullptr;

    return 0;
}
