#include <iostream>

// VehicleStatus class 
class VehicleStatus {
public:
    int num_wheels;
    float* wheel_speed;
    int num_temps;
    float* engine_temp;

    // Constructor
    VehicleStatus(int wheels, const float* ws, int temps, const float* et)
        : num_wheels(wheels), num_temps(temps)
    {
        // Allocate wheel speeds
        wheel_speed = new float[num_wheels];
        for (int i = 0; i < num_wheels; ++i) {
            wheel_speed[i] = ws[i];
        }

        // Allocate engine temps
        engine_temp = new float[num_temps];
        for (int i = 0; i < num_temps; ++i) {
            engine_temp[i] = et[i];
        }
    }

    // Destructor: free dynamic memory
    ~VehicleStatus() {
        delete [] wheel_speed;
        delete [] engine_temp;
        wheel_speed = nullptr;
        engine_temp = nullptr;
    }

    // Average wheel speed
    float averageWheelSpeed() const {
        float sum = 0.0f;
        for (int i = 0; i < num_wheels; ++i) {
            sum += wheel_speed[i];
        }
        return (num_wheels > 0) ? sum / num_wheels : 0.0f;
    }

    // Maximum engine temperature
    float maxEngineTemp() const {
        float maxVal = engine_temp[0];
        for (int i = 1; i < num_temps; ++i) {
            if (engine_temp[i] > maxVal) maxVal = engine_temp[i];
        }
        return maxVal;
    }

    // Compare max wheel speeds using this pointer
    bool isWheelSpeedHigher(const VehicleStatus& other) const {
       float thisMax = this->wheel_speed[0];   // using this-> explicitly
    for (int i = 1; i < this->num_wheels; ++i) {
        if (this->wheel_speed[i] > thisMax) {
            thisMax = this->wheel_speed[i];
        }
    }

        float otherMax = other.wheel_speed[0];
        for (int i = 1; i < other.num_wheels; ++i) {
            if (other.wheel_speed[i] > otherMax) otherMax = other.wheel_speed[i];
        }

        return (thisMax > otherMax); // explicit use of this pointer
    }
};

// Global functions
void printVehicleStatus(const VehicleStatus& vs) {
    std::cout << "Wheel Speeds: ";
    for (int i = 0; i < vs.num_wheels; ++i) {
        std::cout << vs.wheel_speed[i] << " ";
    }
    std::cout << "\nEngine Temps: ";
    for (int i = 0; i < vs.num_temps; ++i) {
        std::cout << vs.engine_temp[i] << " ";
    }
    std::cout << "\n";
}

bool compareWheelSpeedGlobal(const VehicleStatus& vs1, const VehicleStatus& vs2) {
    return vs1.isWheelSpeedHigher(vs2);
}

int main() {
    // Sample data
    float ws1[] = {55.5f, 56.6f, 57.2f, 55.9f};
    float et1[] = {90.5f, 88.9f};
    float ws2[] = {50.0f, 51.2f, 49.8f, 50.4f};
    float et2[] = {92.0f, 89.5f};

    VehicleStatus v1(4, ws1, 2, et1);
    VehicleStatus v2(4, ws2, 2, et2);

    std::cout << "--- Vehicle 1 ---\n";
    printVehicleStatus(v1);
    std::cout << "Avg wheel speed: " << v1.averageWheelSpeed()
              << " | Max temp: " << v1.maxEngineTemp() << "\n";

    std::cout << "--- Vehicle 2 ---\n";
    printVehicleStatus(v2);
    std::cout << "Avg wheel speed: " << v2.averageWheelSpeed()
              << " | Max temp: " << v2.maxEngineTemp() << "\n";

    std::cout << "Comparison using Member function "
              << (v1.isWheelSpeedHigher(v2) ? "v1 > v2" : "v2 > v1") << "\n";
    std::cout << "Comparison by global function "
              << (compareWheelSpeedGlobal(v1, v2) ? "v1 > v2" : "v2 > v1") << "\n";

    return 0;
}
