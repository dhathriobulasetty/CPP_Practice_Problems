#include <iostream>
#include <cstdint>
#include <cstring>
#include <limits>

enum class SensorType { LIDAR, RADAR, CAMERA };

class SensorArray {
public:
    int sensor_id;
    SensorType type;
    double* temperature_readings;
    int num_readings;
    static double global_max_temperature;

    // Constructor
    SensorArray(int id = 0, SensorType t = SensorType::LIDAR, const double* readings = nullptr, int n = 0)
        : sensor_id(id), type(t), temperature_readings(nullptr), num_readings(n)
    {
        if (num_readings < 0) num_readings = 0;
        if (num_readings > 0 && readings != nullptr) {
            temperature_readings = new double[num_readings];
            for (int i = 0; i < num_readings; ++i) {
                temperature_readings[i] = readings[i];
                if (temperature_readings[i] > global_max_temperature) {
                    global_max_temperature = temperature_readings[i];
                }
            }
        } else {
            temperature_readings = nullptr;
            num_readings = 0;
        }
    }

    // Destructor
    ~SensorArray()
    {
        delete [] temperature_readings;
        temperature_readings = nullptr;
        num_readings = 0;
    }

    double getMaxTemperature() const
    {
        double maxT = std::numeric_limits<double>::lowest();
        if (temperature_readings == nullptr || num_readings == 0) {
            return maxT;
        }
        for (int i = 0; i < num_readings; ++i) {
            if (temperature_readings[i] > maxT) maxT = temperature_readings[i];
        }
        return maxT;
    }

    void printSensorInfo() const
    {
        const char* typeStr = sensorTypeToString(type);
        std::cout << "Sensor ID: " << sensor_id
                  << " | Type: " << typeStr
                  << " | Max Temp: " << getMaxTemperature() << " C\n";
    }

    static double getGlobalMaxTemperature()
    {
        return global_max_temperature;
    }

    static const char* sensorTypeToString(SensorType t)
    {
        switch (t) {
            case SensorType::LIDAR: return "LIDAR";
            case SensorType::RADAR: return "RADAR";
            case SensorType::CAMERA: return "CAMERA";
            default: return "UNKNOWN";
        }
    }
};

// Static initialization
double SensorArray::global_max_temperature = std::numeric_limits<double>::lowest();

// Global helper wrappers 
const char* sensorTypeToString(SensorType t) { return SensorArray::sensorTypeToString(t); }

void printSensor(const SensorArray& s)
{
    s.printSensorInfo();
}

void printAllSensors(const SensorArray* arr, int size)
{
    if (arr == nullptr || size <= 0) {
        std::cout << "No sensors to print.\n";
        return;
    }
    for (int i = 0; i < size; ++i) {
        printSensor(arr[i]);
    }
}

int main()
{
    // Sample data
    double readings1[] = {35.5, 36.1, 34.9};
    double readings2[] = {39.0, 38.7, 39.3};
    double readings3[] = {30.2, 31.0, 30.5};

    const int count = 3;
    SensorArray* sensors = new SensorArray[count] {
        SensorArray(801, SensorType::LIDAR, readings1, 3),
        SensorArray(802, SensorType::RADAR, readings2, 3),
        SensorArray(803, SensorType::CAMERA, readings3, 3)
    };

    printAllSensors(sensors, count);

    std::cout << "Global maximum temperature across all sensors: "
              << SensorArray::getGlobalMaxTemperature() << " C\n";

    delete [] sensors;
    sensors = nullptr;
    return 0;
}
