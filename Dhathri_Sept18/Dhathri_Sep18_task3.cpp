#include <iostream>

enum SatelliteStatus { OPERATIONAL, MAINTENANCE, DECOMMISSIONED };

class SatelliteData {
public:
    int satellite_id;
    int num_antennas;
    float* signal_strength;
    float orbital_altitude;
    SatelliteStatus status;
    static int active_satellites;

    // Constructor
    SatelliteData(int id, int antennas, const float* signals, float altitude, SatelliteStatus st)
        : satellite_id(id), num_antennas(antennas), orbital_altitude(altitude), status(st)
    {
        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; ++i) {
            signal_strength[i] = signals[i];
        }
        ++active_satellites;
    }

    // Copy constructor
    SatelliteData(const SatelliteData& other)
        : satellite_id(other.satellite_id), num_antennas(other.num_antennas),
          orbital_altitude(other.orbital_altitude), status(other.status)
    {
        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; ++i) {
            signal_strength[i] = other.signal_strength[i];
        }
        ++active_satellites;
    }

    // Destructor
    ~SatelliteData() {
        delete [] signal_strength;
        signal_strength = nullptr;
        --active_satellites;
    }

    float getAverageSignalStrength() const {
        float sum = 0.0f;
        for (int i = 0; i < num_antennas; ++i) sum += signal_strength[i];
        return (num_antennas > 0) ? sum / num_antennas : 0.0f;
    }

    void boostSignal(float factor) {
        for (int i = 0; i < num_antennas; ++i) {
            signal_strength[i] *= factor;
        }
    }

    void boostSignal(float factor, float threshold) {
        for (int i = 0; i < num_antennas; ++i) {
            if (signal_strength[i] < threshold) {
                signal_strength[i] *= factor;
            }
        }
    }

    static int getActiveSatelliteCount() {
        return active_satellites;
    }

    void setStatus(SatelliteStatus new_status) {
        status = new_status;
    }

    std::string getStatusString() const {
        switch (status) {
            case OPERATIONAL: return "OPERATIONAL";
            case MAINTENANCE: return "MAINTENANCE";
            case DECOMMISSIONED: return "DECOMMISSIONED";
            default: return "UNKNOWN";
        }
    }
};

// Static initialization
int SatelliteData::active_satellites = 0;

// Global functions
void printSatelliteData(const SatelliteData& sd) {
    std::cout << "Satellite ID: " << sd.satellite_id
              << " | Altitude: " << sd.orbital_altitude
              << " | Status: " << sd.getStatusString()
              << "\nSignal strengths: ";
    for (int i = 0; i < sd.num_antennas; ++i) {
        std::cout << sd.signal_strength[i] << " ";
    }
    std::cout << "\n";
}

bool compareAltitude(const SatelliteData& s1, const SatelliteData& s2) {
    return (s1.orbital_altitude > s2.orbital_altitude);
}

void cloneSatellite(const SatelliteData& source, SatelliteData*& target) {
    target = new SatelliteData(source); // calls copy constructor
}

void printActiveSatelliteCount() {
    std::cout << "Active satellites: " << SatelliteData::getActiveSatelliteCount() << "\n";
}

void updateStatusIfWeak(SatelliteData& sd, float confidence_threshold) {
    if (sd.getAverageSignalStrength() < confidence_threshold) {
        sd.setStatus(MAINTENANCE);
    }
}

int main() {
    // Sample data
    float s1[] = {78.5f, 80.2f, 79.0f};
    float s2[] = {75.0f, 76.5f};

    SatelliteData sat1(101, 3, s1, 550.0f, OPERATIONAL);
    SatelliteData sat2(102, 2, s2, 600.0f, MAINTENANCE);

    // Boost sat1 signals (all)
    sat1.boostSignal(1.1f);
    // Boost sat2 signals (only below threshold)
    sat2.boostSignal(1.2f, 76.0f);

    // Compare altitudes
    std::cout << "Compare Altitudes\n "
              << (compareAltitude(sat2, sat1) ? "Satellite2 > Satellite1" : "Satellite1 > Satellite2") << "\n";

    // Clone sat1
    SatelliteData* clone = nullptr;
    cloneSatellite(sat1, clone);

    // Print all satellites
    std::cout << "--- Satellite 1 ---\n"; printSatelliteData(sat1);
    std::cout << "--- Satellite 2 ---\n"; printSatelliteData(sat2);
    std::cout << "--- Cloned Satellite ---\n"; printSatelliteData(*clone);

    // Update status if weak
    updateStatusIfWeak(sat2, 77.0f);
    std::cout << "After update, Sat2 status: " << sat2.getStatusString() << "\n";

    // Print active count
    printActiveSatelliteCount();

    // Free clone
    delete clone;
    clone = nullptr;

    return 0;
}
