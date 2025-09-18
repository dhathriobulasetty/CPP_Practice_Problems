#include <iostream>


class LaneBoundary {
private:
    float curvature;
    int lane_id;

public:

    // Constructor
    LaneBoundary(float curvature, int lane_id)
        : curvature(curvature), lane_id(lane_id) {}

    // Const getters
    float getCurvature() const { return curvature; }
    int getLaneId() const { return lane_id; }

    // Compare using this pointer explicitly
    bool compareCurvature(const LaneBoundary& other) const {
        return this->curvature > other.curvature;
    }
    
    // Display function
    void display() const {
        std::cout << "Lane " << lane_id << " -> curvature: "<< curvature << '\n';
    }
};

// Global functions
bool isCurvatureGreater(const LaneBoundary& lane1, const LaneBoundary& lane2) {
    return lane1.getCurvature() > lane2.getCurvature();
}

void printLaneComparison(const LaneBoundary& lane1, const LaneBoundary& lane2) {
    if (isCurvatureGreater(lane1, lane2)) {
        std::cout << "Lane " << lane1.getLaneId() << " has greater curvature.\n";
    } else if (isCurvatureGreater(lane2, lane1)) {
        std::cout << "Lane " << lane2.getLaneId() << " has greater curvature.\n";
    } else {
        std::cout << "Both lanes have equal curvature.\n";
    }
}

int main() {
    LaneBoundary lane1(0.015f, 1);
    LaneBoundary lane2(0.023f, 2);

    // Display lanes
    lane1.display();
    lane2.display();

    // Member function comparison
    std::cout << "Compare using member: ";
    if (lane1.compareCurvature(lane2))
        std::cout << "Lane 1 has greater curvature\n";
    else if (lane2.compareCurvature(lane1))
        std::cout << "Lane 2 has greater curvature\n";
    else
        std::cout << "Both lanes have equal curvature\n";

    // Global function comparison
    std::cout << "Compare using global function:\n";
    printLaneComparison(lane1, lane2);

    return 0;
}
