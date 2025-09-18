#include <iostream>
#include <string>
#include <stdexcept>


// FleetVehicle class

class FleetVehicle {
private:
    int vehicleID;
    float fuelLevel;
    double distanceTravelled;
    char status;
    bool isAvailable;
    std::string driverName;

public:
    // Default constructor
    FleetVehicle() 
        : vehicleID(0), fuelLevel(50.0f), distanceTravelled(0.0),
          status('A'), isAvailable(true), driverName("Unassigned") {}

    // Parameterized constructor
    FleetVehicle(int id, float fuel, double distance, char stat, bool available, std::string driver) 
        : vehicleID(id), fuelLevel(fuel), distanceTravelled(distance),
          status(stat), isAvailable(available), driverName(driver) {}

    // Destructor
    ~FleetVehicle() {
        std::cout << "Destructor called for vehicle ID: " << vehicleID << std::endl;
    }

    // Getters
    int getVehicleID() const { return vehicleID; }
    float getFuelLevel() const { return fuelLevel; }
    double getDistanceTravelled() const { return distanceTravelled; }
    char getStatus() const { return status; }
    bool getIsAvailable() const { return isAvailable; }
    std::string getDriverName() const { return driverName; }

    // Setters
    void setVehicleID(int id) { vehicleID = id; }
    void setFuelLevel(float fuel) { fuelLevel = fuel; }
    void setDistanceTravelled(double distance) { distanceTravelled = distance; }
    void setStatus(char stat) { status = stat; }
    void setIsAvailable(bool available) { isAvailable = available; }
    void setDriverName(const std::string &driver) { driverName = driver; }

    // Update vehicle status
    void updateStatus() {
        if (fuelLevel < 10.0f || !isAvailable) {
            status = 'I';
        } else {
            status = 'A';
        }
    }

    // Display info
    void displayInfo() const {
        std::cout << "\n--- Vehicle Information ---\n";
        std::cout << "Vehicle ID: " << vehicleID << std::endl;
        std::cout << "Fuel Level: " << fuelLevel << std::endl;
        std::cout << "Distance Travelled: " << distanceTravelled << std::endl;
        std::cout << "Status: " << status << std::endl;
        std::cout << "Availability: " << (isAvailable ? "Yes" : "No") << std::endl;
        std::cout << "Driver: " << driverName << std::endl;
        std::cout << "---------------------------\n";
    }
};

// Global functions
void assignDriver(FleetVehicle &vehicle, std::string name) {
    vehicle.setDriverName(name);
    std::cout << "Driver " << vehicle.getDriverName() << " assigned successfully.\n";
}

void refuelVehicle(FleetVehicle &vehicle, float fuelAmount) {
    if (fuelAmount <= 0) {
        throw std::invalid_argument("Fuel amount must be greater than 0!");
    }
    vehicle.setFuelLevel(vehicle.getFuelLevel() + fuelAmount);
    std::cout << "Vehicle refueled. Current fuel level: " << vehicle.getFuelLevel() << std::endl;
}

// Main function
int main() {
    FleetVehicle vehicles[3] = {
        FleetVehicle(101, 45.5f, 120.0, 'A', true, "Raj"),
        FleetVehicle(102, 8.0f, 300.0, 'A', true, "Priya"),
        FleetVehicle()
    };

    int choice;
    do {
        std::cout << "\n===== Fleet Vehicle Monitoring Menu =====\n";
        std::cout << "1. Add Vehicle Details\n";
        std::cout << "2. Assign Driver\n";
        std::cout << "3. Refuel Vehicle\n";
        std::cout << "4. Update Status\n";
        std::cout << "5. Display Vehicle Info\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id, index;
                float fuel;
                double distance;
                char status;
                bool available;
                std::string driver;

                std::cout << "Enter index (0-2): ";
                std::cin >> index;
                if (index < 0 || index > 2) {
                    std::cout << "Invalid index!\n";
                    break;
                }

                std::cout << "Enter Vehicle ID: ";
                std::cin >> id;
                std::cout << "Enter Fuel Level: ";
                std::cin >> fuel;
                std::cout << "Enter Distance Travelled: ";
                std::cin >> distance;
                std::cout << "Enter Status (A/I): ";
                std::cin >> status;
                std::cout << "Is Available? (1=Yes, 0=No): ";
                std::cin >> available;
                std::cin.ignore();
                std::cout << "Enter Driver Name: ";
                getline(std::cin, driver);

                vehicles[index] = FleetVehicle(id, fuel, distance, status, available, driver);
                std::cout << "Vehicle details added successfully.\n";
                break;
            }
            case 2: {
                int index;
                std::string driver;
                std::cout << "Enter index (0-2): ";
                std::cin >> index;
                std::cin.ignore();
                std::cout << "Enter Driver Name: ";
                getline(std::cin, driver);
                assignDriver(vehicles[index], driver);
                break;
            }
            case 3: {
                int index;
                float fuel;
                std::cout << "Enter index (0-2): ";
                std::cin >> index;
                std::cout << "Enter fuel amount: ";
                std::cin >> fuel;
                try {
                    refuelVehicle(vehicles[index], fuel);
                } catch (std::exception &e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter index (0-2): ";
                std::cin >> index;
                vehicles[index].updateStatus();
                std::cout << "Status updated successfully.\n";
                break;
            }
            case 5: {
                int index;
                std::cout << "Enter index (0-2): ";
                std::cin >> index;
                vehicles[index].displayInfo();
                break;
            }
            case 6:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
