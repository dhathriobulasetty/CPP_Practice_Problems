#include <iostream>

class ObjectDistance {
public:
    float radar_distance;
    float camera_distance;

    ObjectDistance(float r , float c )
        : radar_distance(r), camera_distance(c) {}
};

// Adjust by value (operates on a copy)
void adjustDistancesByValue(ObjectDistance obj) {
    obj.radar_distance += 5.0f;
    obj.camera_distance += 5.0f;
    // changes lost after function returns
}

// Adjust by reference (modifies original)
void adjustDistancesByReference(ObjectDistance& obj) {
    obj.radar_distance += 5.0f;
    obj.camera_distance += 5.0f;
}

void printObjectDistance(const ObjectDistance& obj) {
    std::cout << "Radar: " << obj.radar_distance
              << ", Camera: " << obj.camera_distance << '\n';
}

ObjectDistance* createObjectDistanceOnHeap(float radar, float camera) {
    return new ObjectDistance(radar, camera);
}

int main() {
    ObjectDistance* od = createObjectDistanceOnHeap(35.5f, 34.8f);

    std::cout << "Original values:\n";
    printObjectDistance(*od);

    std::cout << "\nCall adjustDistancesByValue(*od):\n";
    adjustDistancesByValue(*od);
    printObjectDistance(*od); // unchanged

    std::cout << "\nCall adjustDistancesByReference(*od):\n";
    adjustDistancesByReference(*od);
    printObjectDistance(*od); // increased by 5.0

    delete od; // free heap memory
    od = nullptr;
    return 0;
}
