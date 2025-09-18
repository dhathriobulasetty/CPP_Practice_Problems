#include <iostream>
#include <cstdint>

using uint32 = std::uint32_t;

class Pedestrian {
public:
    uint32 pedestrian_id;
    float distance_from_vehicle;

    // Constructor (initializes both members)
    Pedestrian(uint32 id = 0u, float distance = 0.0f)
        : pedestrian_id(id), distance_from_vehicle(distance){}

    // Update distance
    void updateDistance(float newDistance)
    {
        
        distance_from_vehicle = newDistance;
        
    }

    // Getter
    float getDistance() const
    {
        return distance_from_vehicle;
    }
};

// Finds the closest pedestrian (assigns 'closest' to point to the Pedestrian with min distance)
void findClosestPedestrian(Pedestrian* array, uint32 size, const Pedestrian*& closest)
{
    closest = nullptr;
    if (array == nullptr || size == 0u) {
        return;
    }
    const Pedestrian* minPtr = &array[0];
    for (uint32 i = 1u; i < size; ++i) {
        if (array[i].getDistance() < minPtr->getDistance()) {
            minPtr = &array[i];
        }
    }
    closest = minPtr;
}

void printPedestrianInfo(const Pedestrian& ped)
{
    std::cout << "Pedestrian ID: " << ped.pedestrian_id
              << " | Distance: " << ped.distance_from_vehicle << " m\n";
}

void printClosestPedestrian(const Pedestrian* closest)
{
    if (closest == nullptr) {
        std::cout << "No closest pedestrian found.\n";
    } else {
        std::cout << "Closest Pedestrian\n";
        printPedestrianInfo(*closest);
    }
}

int main()
{
    // Dynamically allocate array of 3 Pedestrian objects (heap)
    const uint32 count = 3u;
    Pedestrian* pedestrians = new Pedestrian[count] {
        Pedestrian(101u, 12.4f),
        Pedestrian(102u, 8.7f),
        Pedestrian(103u, 15.1f)
    };

    // Print all pedestrians
    std::cout << "All Pedestrians:\n";
    for (uint32 i = 0u; i < count; ++i) {
        printPedestrianInfo(pedestrians[i]);
    }

    // Find the closest
    const Pedestrian* closest = nullptr;
    findClosestPedestrian(pedestrians, count, closest);

    // Print closest
    printClosestPedestrian(closest);

    // Clean up
    delete [] pedestrians;
    pedestrians = nullptr;

    return 0;
}
