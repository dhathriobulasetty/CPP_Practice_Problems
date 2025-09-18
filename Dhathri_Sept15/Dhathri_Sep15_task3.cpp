#include <iostream>
#include <string>

// Enums
enum ComponentType {
    COMPONENT_TYPE_ENGINE,
    COMPONENT_TYPE_AVIONICS,
    COMPONENT_TYPE_LANDING_GEAR,
    COMPONENT_TYPE_FUEL_SYSTEM
};

enum ComponentStatus {
    COMPONENT_STATUS_OPERATIONAL,
    COMPONENT_STATUS_MAINTENANCE_REQUIRED,
    COMPONENT_STATUS_FAILED
};

class AerospaceComponent {
private:
    int componentIdentifier;
    double componentEfficiency;
    std::string componentManufacturer;
    ComponentType componentType;
    ComponentStatus componentStatus;

public:
    // Default constructor
    AerospaceComponent()
        : componentIdentifier(0), componentEfficiency(100.0),
          componentManufacturer("Unknown"),
          componentType(COMPONENT_TYPE_ENGINE),
          componentStatus(COMPONENT_STATUS_OPERATIONAL) {}

    // Parameterized constructor
    AerospaceComponent(int id, double efficiency, const std::string &manufacturer,
                       ComponentType type, ComponentStatus status)
        : componentIdentifier(id), componentEfficiency(efficiency),
          componentManufacturer(manufacturer),
          componentType(type), componentStatus(status) {}

    // Destructor
    ~AerospaceComponent() {
        std::cout << "Component " << componentIdentifier << " destroyed." << std::endl;
    }

    // Getters
    int getIdentifier() const { return componentIdentifier; }
    double getEfficiency() const { return componentEfficiency; }
    std::string getManufacturer() const { return componentManufacturer; }
    ComponentType getType() const { return componentType; }
    ComponentStatus getStatus() const { return componentStatus; }

    // Setters
    void setIdentifier(int id) { componentIdentifier = id; }
    void setEfficiency(double eff) { componentEfficiency = eff; }
    void setManufacturer(const std::string &manu) { componentManufacturer = manu; }
    void setType(ComponentType type) { componentType = type; }
    void setStatus(ComponentStatus status) { componentStatus = status; }

    // Update status based on efficiency
    void UpdateStatus() {
        if (componentEfficiency < 50.0) {
            componentStatus = COMPONENT_STATUS_FAILED;
        } else if (componentEfficiency < 80.0) {
            componentStatus = COMPONENT_STATUS_MAINTENANCE_REQUIRED;
        } else {
            componentStatus = COMPONENT_STATUS_OPERATIONAL;
        }
    }

    // Simulate usage
    void SimulateUsage(int usageHours) {
        for (int i = 0; i < usageHours; i++) {
            componentEfficiency -= (componentEfficiency * 0.005); // reduce by 0.5%
            if (componentEfficiency < 0) {
                componentEfficiency = 0;
                break;
            }
        }
    }

    // Maintenance check
    void PerformMaintenanceCheck() const {
        switch (componentStatus) {
            case COMPONENT_STATUS_OPERATIONAL:
                std::cout << "Component " << componentIdentifier << " is operational." << std::endl;
                break;
            case COMPONENT_STATUS_MAINTENANCE_REQUIRED:
                std::cout << "Component " << componentIdentifier << " needs maintenance soon." << std::endl;
                break;
            case COMPONENT_STATUS_FAILED:
                std::cout << "Component " << componentIdentifier << " has failed!" << std::endl;
                break;
        }
    }

    // Boost efficiency
    void BoostEfficiency() {
        while (componentEfficiency < 100.0) {
            componentEfficiency += 1.0;
            if (componentEfficiency > 100.0) componentEfficiency = 100.0;
        }
    }

    // Display details
    void DisplayDetails() const {
        std::cout << "\n--- Component Details ---\n";
        std::cout << "ID: " << componentIdentifier << std::endl;
        std::cout << "Efficiency: " << componentEfficiency << std::endl;
        std::cout << "Manufacturer: " << componentManufacturer << std::endl;

        std::cout << "Type: ";
        switch (componentType) {
            case COMPONENT_TYPE_ENGINE: std::cout << "Engine"; break;
            case COMPONENT_TYPE_AVIONICS: std::cout << "Avionics"; break;
            case COMPONENT_TYPE_LANDING_GEAR: std::cout << "Landing Gear"; break;
            case COMPONENT_TYPE_FUEL_SYSTEM: std::cout << "Fuel System"; break;
        }
        std::cout << std::endl;

        std::cout << "Status: ";
        switch (componentStatus) {
            case COMPONENT_STATUS_OPERATIONAL: std::cout << "Operational"; break;
            case COMPONENT_STATUS_MAINTENANCE_REQUIRED: std::cout << "Maintenance Required"; break;
            case COMPONENT_STATUS_FAILED: std::cout << "Failed"; break;
        }
        std::cout << std::endl;
    }
};

// Global functions
void AssignManufacturer(AerospaceComponent &component, const std::string &manufacturerName) {
    component.setManufacturer(manufacturerName);
    std::cout << "Manufacturer assigned: " << component.getManufacturer() << std::endl;
}

bool IsEfficient(const AerospaceComponent &component) {
    return component.getEfficiency() > 85.0;
}

bool IsSameType(const AerospaceComponent &a, const AerospaceComponent &b) {
    return a.getType() == b.getType();
}

bool IsSameStatus(const AerospaceComponent &a, const AerospaceComponent &b) {
    return a.getStatus() == b.getStatus();
}

void PrintFormattedComponentList(const AerospaceComponent componentList[], const int listSize) {
    std::cout << "\nID | Efficiency | Manufacturer | Type | Status\n";
    std::cout << "-------------------------------------------------\n";

    for (int i = 0; i < listSize; i++) {
        std::cout << componentList[i].getIdentifier() << " | "
                  << componentList[i].getEfficiency() << " | "
                  << componentList[i].getManufacturer() << " | ";

        switch (componentList[i].getType()) {
            case COMPONENT_TYPE_ENGINE: std::cout << "Engine"; break;
            case COMPONENT_TYPE_AVIONICS: std::cout << "Avionics"; break;
            case COMPONENT_TYPE_LANDING_GEAR: std::cout << "Landing Gear"; break;
            case COMPONENT_TYPE_FUEL_SYSTEM: std::cout << "Fuel System"; break;
        }
        std::cout << " | ";

        switch (componentList[i].getStatus()) {
            case COMPONENT_STATUS_OPERATIONAL: std::cout << "Operational"; break;
            case COMPONENT_STATUS_MAINTENANCE_REQUIRED: std::cout << "Maintenance Required"; break;
            case COMPONENT_STATUS_FAILED: std::cout << "Failed"; break;
        }
        std::cout << std::endl;
    }
}

int SearchComponentByIdentifier(const AerospaceComponent componentList[], const int listSize, const int searchIdentifier) {
    for (int i = 0; i < listSize; i++) {
        if (componentList[i].getIdentifier() == searchIdentifier) {
            return i;
        }
    }
    return -1;
}

// Main function
int main() {
    AerospaceComponent components[3] = {
        AerospaceComponent(101, 92.5, "GE Aviation", COMPONENT_TYPE_ENGINE, COMPONENT_STATUS_OPERATIONAL),
        AerospaceComponent(102, 45.0, "Honeywell", COMPONENT_TYPE_AVIONICS, COMPONENT_STATUS_FAILED),
        AerospaceComponent()
    };

    int choice;
    do {
        std::cout << "\n===== Aerospace Component Monitoring Menu =====\n";
        std::cout << "1. Add Component Details\n";
        std::cout << "2. Assign Manufacturer\n";
        std::cout << "3. Simulate Usage\n";
        std::cout << "4. Boost Efficiency\n";
        std::cout << "5. Perform Maintenance Check\n";
        std::cout << "6. Compare Components (Type/Status)\n";
        std::cout << "7. Search by Component ID\n";
        std::cout << "8. Display All Components\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int index, id, typeChoice, statusChoice;
            double eff;
            std::string manu;

            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            if (index < 0 || index > 2) { std::cout << "Invalid index!\n"; continue; }

            std::cout << "Enter ID: ";
            std::cin >> id;
            std::cout << "Enter Efficiency (0-100): ";
            std::cin >> eff;
            if (eff < 0 || eff > 100) { std::cout << "Invalid efficiency!\n"; continue; }

            std::cin.ignore();
            std::cout << "Enter Manufacturer: ";
            std::getline(std::cin, manu);
            if (manu.empty()) { std::cout << "Invalid manufacturer!\n"; continue; }

            std::cout << "Select Type (0=Engine,1=Avionics,2=Landing Gear,3=Fuel System): ";
            std::cin >> typeChoice;
            if (typeChoice < 0 || typeChoice > 3) { std::cout << "Invalid type!\n"; continue; }

            std::cout << "Select Status (0=Operational,1=Maintenance,2=Failed): ";
            std::cin >> statusChoice;
            if (statusChoice < 0 || statusChoice > 2) { std::cout << "Invalid status!\n"; continue; }

            components[index] = AerospaceComponent(id, eff, manu,
                static_cast<ComponentType>(typeChoice),
                static_cast<ComponentStatus>(statusChoice));
            std::cout << "Component added successfully!\n";
        }
        else if (choice == 2) {
            int index;
            std::string manu;
            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            std::cin.ignore();
            std::cout << "Enter Manufacturer: ";
            std::getline(std::cin, manu);
            AssignManufacturer(components[index], manu);
        }
        else if (choice == 3) {
            int index, hours;
            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            std::cout << "Enter usage hours: ";
            std::cin >> hours;
            components[index].SimulateUsage(hours);
            components[index].UpdateStatus();
            std::cout << "Usage simulated successfully!\n";
        }
        else if (choice == 4) {
            int index;
            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            components[index].BoostEfficiency();
            components[index].UpdateStatus();
            std::cout << "Efficiency boosted!\n";
        }
        else if (choice == 5) {
            int index;
            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            components[index].PerformMaintenanceCheck();
        }
        else if (choice == 6) {
            int a, b;
            std::cout << "Enter two indices (0-2): ";
            std::cin >> a >> b;
            std::cout << "Same Type? " << (IsSameType(components[a], components[b]) ? "Yes" : "No") << std::endl;
            std::cout << "Same Status? " << (IsSameStatus(components[a], components[b]) ? "Yes" : "No") << std::endl;
        }
        else if (choice == 7) {
            int id;
            std::cout << "Enter Component ID to search: ";
            std::cin >> id;
            int idx = SearchComponentByIdentifier(components, 3, id);
            if (idx != -1) {
                std::cout << "Component found at index: " << idx << std::endl;
                components[idx].DisplayDetails();
            } else {
                std::cout << "Component not found.\n";
            }
        }
        else if (choice == 8) {
            PrintFormattedComponentList(components, 3);
        }
        else if (choice == 9) {
            std::cout << "Exiting program...\n";
        }
        else {
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 9);

    return 0;
}
