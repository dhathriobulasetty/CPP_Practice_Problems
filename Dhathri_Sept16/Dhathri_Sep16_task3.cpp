#include <iostream>
#include <iomanip>


class CameraConfig {
private:
    int num_modes;
    int* resolution_width;
    int* resolution_height;

public:
    // Constructor
    CameraConfig(int n, const int widths[], const int heights[])
        : num_modes(n),
          resolution_width(nullptr),
          resolution_height(nullptr)
    {
        if (num_modes > 0) {
            resolution_width = new int[num_modes];
            resolution_height = new int[num_modes];
            for (int i = 0; i < num_modes; ++i) {
                resolution_width[i] = widths[i];
                resolution_height[i] = heights[i];
            }
        }
    }

    // Copy constructor 
    CameraConfig(const CameraConfig& other)
        : num_modes(other.num_modes),
          resolution_width(nullptr),
          resolution_height(nullptr)
    {
        if (num_modes > 0) {
            resolution_width = new int[num_modes];
            resolution_height = new int[num_modes];
            for (int i = 0; i < num_modes; ++i) {
                resolution_width[i] = other.resolution_width[i];
                resolution_height[i] = other.resolution_height[i];
            }
        }
    }

    // Destructor
    ~CameraConfig() {
        delete[] resolution_width;
        delete[] resolution_height;
    }

    // Print config
    void printConfig() const {
        std::cout << "CameraConfig (" << num_modes << " modes):\n";
        for (int i = 0; i < num_modes; ++i) {
            std::cout << " Mode " << i << ": " << resolution_width[i] 
                      << " x " << resolution_height[i] << '\n';
        }
    }

    // Compare resolutions of two modes (using this pointer explicitly)
    bool isHigherResolution(int mode1, int mode2) const {
        if (mode1 < 0 || mode1 >= num_modes || mode2 < 0 || mode2 >= num_modes) {
             std::cout<<"Invalid mode index(s).\n";
            return false;
        }
        long long area1 = this->resolution_width[mode1] * this->resolution_height[mode1];
        long long area2 = this->resolution_width[mode2] * this->resolution_height[mode2];
        return area1 > area2;
    }

  
};

// Global functions
void printCameraConfig(const CameraConfig& config) {
    config.printConfig();
}

bool globalCompareResolution(const CameraConfig& config, int m1, int m2) {
    return config.isHigherResolution(m1, m2);
}

// main usage
int main() {
    const int widths[3] = {1920, 1280, 3840};
    const int heights[3] = {1080, 2160, 2160}; 
    CameraConfig cfg(3, widths, heights);

    printCameraConfig(cfg);

    std::cout << "Member compare : "
              << (cfg.isHigherResolution(0, 2) ? "mode0 > mode2\n" : "mode0 <= mode2\n");

    std::cout << "Global compare : "
              << (globalCompareResolution(cfg, 0, 2) ? "mode0 > mode2\n" : "mode0 <= mode2\n");

    return 0;
}
