#include <iostream>

class RadarSignal {
private:
    int num_channels;
    float* signal_strength;

public:
    RadarSignal(int n, const float signals[])
        : num_channels(n), signal_strength(nullptr)
    {
        if (num_channels > 0) {
            signal_strength = new float[num_channels];
            for (int i = 0; i < num_channels; ++i)
                signal_strength[i] = signals[i];
        }
    }

    // Copy constructor 
    RadarSignal(const RadarSignal& other)
        : num_channels(other.num_channels), signal_strength(nullptr)
    {
        if (num_channels > 0) {
            signal_strength = new float[num_channels];
            for (int i = 0; i < num_channels; ++i)
                signal_strength[i] = other.signal_strength[i];
        }
    }
 
    //Deconstructor
    ~RadarSignal() {
        delete[] signal_strength;
    }

    double averageSignal() const {
        if (num_channels == 0) return 0.0;
        double sum = 0.0;
        for (int i = 0; i < num_channels; ++i) sum += signal_strength[i];
        return sum / num_channels;
    }

    // Boost by value (copy)
    void boostSignalByValue(RadarSignal obj) {
        for (int i = 0; i < obj.num_channels; ++i)
            obj.signal_strength[i] += 5.0f;
        // obj is destroyed on return; original unchanged
    }

    // Boost by reference (modifies original)
    void boostSignalByReference(RadarSignal& obj) {
        for (int i = 0; i < obj.num_channels; ++i)
            obj.signal_strength[i] += 5.0f;
    }

    // For printing by global function
    void print() const {
        std::cout << "RadarSignal [" << num_channels << "]: ";
        for (int i = 0; i < num_channels; ++i)
            std::cout <<  signal_strength[i] 
                      << (i+1 < num_channels ? ", " : "\n\n");
    }

    int getNumChannels() const { return num_channels; }
};

// Global functions
void printRadarSignal(const RadarSignal& radar) {
    radar.print();
}

RadarSignal* createRadarSignalHeap(int num, const float* signals) {
    return new RadarSignal(num, signals);
}

// main
int main() {
    const float signals[4] = {55.5f, 48.2f, 60.1f, 52.6f};
    RadarSignal* radar = createRadarSignalHeap(4, signals);

    std::cout << "Original:\n";
    printRadarSignal(*radar);
    std::cout << "Average: " << radar->averageSignal() << "\n\n";

    std::cout << "Call boostSignalByValue(*radar):\n";
    radar->boostSignalByValue(*radar);
    printRadarSignal(*radar); // unchanged

    std::cout << "\nCall boostSignalByReference(*radar):\n";
    radar->boostSignalByReference(*radar);
    printRadarSignal(*radar); // increased by +5.0 each

    delete radar;
    radar = nullptr;
    return 0;
}
