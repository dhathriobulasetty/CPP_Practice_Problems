#include <iostream>

class EgoVehicleData {
public:
    int num_lanes;
    float* lane_positions;
    float* sensor_confidence;

    // Constructor
    EgoVehicleData(int lanes, const float* lp, const float* sc)
        : num_lanes(lanes)
    {
        lane_positions = new float[num_lanes];
        sensor_confidence = new float[num_lanes];
        for (int i = 0; i < num_lanes; ++i) {
            lane_positions[i] = lp[i];
            sensor_confidence[i] = sc[i];
        }
    }

    // Destructor
    ~EgoVehicleData() {
        delete [] lane_positions;
        delete [] sensor_confidence;
        lane_positions = nullptr;
        sensor_confidence = nullptr;
    }

    // Average lane position
    float getAverageLanePosition() const {
        float sum = 0.0f;
        for (int i = 0; i < num_lanes; ++i) sum += lane_positions[i];
        return (num_lanes > 0) ? sum / num_lanes : 0.0f;
    }

    // Update sensor confidence
    void updateSensorConfidence(float factor) {
        for (int i = 0; i < num_lanes; ++i) {
            sensor_confidence[i] *= factor;
        }
    }

    // Sum of confidence 
    float totalConfidence() const {
        float sum = 0.0f;
        for (int i = 0; i < num_lanes; ++i) sum += sensor_confidence[i];
        return sum;
    }
};

// Global functions
void printEgoVehicleData(const EgoVehicleData& data) {
    std::cout << "Lane positions: ";
    for (int i = 0; i < data.num_lanes; ++i) {
        std::cout << data.lane_positions[i] << " ";
    }
    std::cout << "\nSensor confidence: ";
    for (int i = 0; i < data.num_lanes; ++i) {
        std::cout << data.sensor_confidence[i] << " ";
    }
    std::cout << "\nAverage lane position: " << data.getAverageLanePosition() << "\n";
}

void findHighestConfidenceVehicle(EgoVehicleData* array, int size, const EgoVehicleData*& highest) {
    highest = nullptr;
    if (array == nullptr || size <= 0) return;

    const EgoVehicleData* best = &array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i].totalConfidence() > best->totalConfidence()) {
            best = &array[i];
        }
    }
    highest = best;
}

void printHighestConfidenceVehicle(const EgoVehicleData* vehicle) {
    if (vehicle == nullptr) {
        std::cout << "No vehicle found.\n";
    } else {
        std::cout << "*** Highest Confidence Vehicle ***\n";
        printEgoVehicleData(*vehicle);
    }
}

int main() {
    // Sample data
    float lp1[] = {3.2f, 3.0f, 3.4f};
    float sc1[] = {0.95f, 0.97f, 0.93f};

    float lp2[] = {2.9f, 2.8f, 3.1f};
    float sc2[] = {0.92f, 0.90f, 0.88f};

    float lp3[] = {3.4f, 3.5f, 3.6f};
    float sc3[] = {0.99f, 0.98f, 0.97f};

    const int count = 3;
    EgoVehicleData* vehicles = new EgoVehicleData[count] {
        EgoVehicleData(3, lp1, sc1),
        EgoVehicleData(3, lp2, sc2),
        EgoVehicleData(3, lp3, sc3)
    };

    // Update sensor confidence with different factors
    vehicles[0].updateSensorConfidence(1.05f);
    vehicles[1].updateSensorConfidence(0.95f);
    vehicles[2].updateSensorConfidence(1.10f);

    // Print all
    for (int i = 0; i < count; ++i) {
        std::cout << "--- Vehicle " << (i+1) << " ---\n";
        printEgoVehicleData(vehicles[i]);
    }

    // Find highest confidence vehicle
    const EgoVehicleData* best = nullptr;
    findHighestConfidenceVehicle(vehicles, count, best);
    printHighestConfidenceVehicle(best);

    delete [] vehicles;
    vehicles = nullptr;
    return 0;
}
