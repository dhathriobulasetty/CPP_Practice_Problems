#include "Dhathri_Oct1_task1_HybridVehicle.h"

int main()
{
    // Create two HybridVehicle objects with sample data
    HybridVehicle v1("Prius", 120.5F, 80.0F, 4.5F);
    HybridVehicle v2("Volt", 100.0F, 90.0F, 5.0F);

    // Add trips
    v1[0] = 50;
    v1[1] = 60;
    v2[0] = 70;
    v2[1] = 40;

    // Display both using <<
    std::cout << "Vehicle 1:\n" << v1 << "\n";
    std::cout << "Vehicle 2:\n" << v2 << "\n";

    // Use + to combine them
    HybridVehicle v3 = v1 + v2;
    std::cout << "Combined Vehicle:\n" << v3 << "\n";

    // Use == to compare efficiency
    if (v1 == v2)
    {
        std::cout << "Vehicles have the same efficiency.\n\n";
    }
    else
    {
        std::cout << "Vehicles have different efficiency.\n\n";
    }

    // Use ++ to simulate a new trip
    ++v1;
    std::cout << "Vehicle 1 after new trip:\n" << v1 << "\n";

    // Access a trip using []
    std::cout << "Vehicle 2 Trip[0]: " << v2[0] << "\n\n";

    // Use () to get total distance
    std::cout << "Total distance of Vehicle 1: " << v1() << " km\n\n";

    // Use float() to get efficiency
    float efficiency = static_cast<float>(v1);
    std::cout << "Efficiency of Vehicle 1: " << efficiency << " km/L\n\n";

    // Use = to copy one vehicle to another
    HybridVehicle v4 = v1; // copy constructor
    HybridVehicle v5("Temp", 0.0F, 0.0F, 0.0F);
    v5 = v2; // assignment operator
    std::cout << "Copied Vehicle (v4 from v1):\n" << v4 << "\n";
    std::cout << "Copied Vehicle (v5 from v2):\n" << v5 << "\n";

    return 0;
}
