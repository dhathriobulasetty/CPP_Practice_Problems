#include <iostream>
#include <cstdint>

using uint32 = std::uint32_t;

class DetectedObject {
public:
    uint32 object_id;
    float rel_speed;
    float distance;

    DetectedObject(uint32 id = 0u, float rs = 0.0f, float dist = 0.0f)
        : object_id(id), rel_speed(rs), distance(dist)
    {
        if (distance < 0.0f) distance = 0.0f;
    }

    void display() const
    {
        std::cout << "Object ID: " << object_id
                  << " | RelSpeed: " << rel_speed
                  << " | Distance: " << distance << "\n";
    }

    // Returns true if *this has smaller distance and higher rel_speed than other
    bool isHigherRisk(const DetectedObject& other) const
    {
        // Use this pointer explicitly as requested
        return (this->distance < other.distance) && (this->rel_speed > other.rel_speed);
    }

    // Modifies the copy only 
    void updateValuesByValue(DetectedObject obj)
    {
        obj.rel_speed += 2.0f;
        obj.distance -= 5.0f;
        if (obj.distance < 0.0f) obj.distance = 0.0f;
        // Original values are unchanged
    }

    // Modifies the original object passed by reference
    void updateValuesByReference(DetectedObject& obj)
    {
        obj.rel_speed += 2.0f;
        obj.distance -= 5.0f;
        if (obj.distance < 0.0f) obj.distance = 0.0f;
    }
};

void printDetectedObject(const DetectedObject& obj)
{
    obj.display();
}

void printHighestRiskObject(const DetectedObject* obj)
{
    if (obj == nullptr) {
        std::cout << "No highest risk object found.\n";
    } else {
        std::cout << "Highest Risk Object\n";
        obj->display();
    }
}

void updateObjectValuesByValueGlobal(DetectedObject obj)
{
    obj.updateValuesByValue(obj);
}

void updateObjectValuesByReferenceGlobal(DetectedObject& obj)
{
    obj.updateValuesByReference(obj);
}

//Assigns the 
reference pointer riskObj to the object with the highest risk 
//Return the first match in case of a tie. 
void findHighestRiskObject(DetectedObject* arr, uint32 size, const DetectedObject*& riskObj)
{
    riskObj = nullptr;
    if (arr == nullptr || size == 0u) return;

    int bestIndex = 0;
    int bestScore = -1;

    for (uint32 i = 0u; i < size; ++i) {
        int score = 0;
        for (uint32 j = 0u; j < size; ++j) {
            if (i == j) continue;
            if (arr[i].isHigherRisk(arr[j])) {
                ++score;
            }
        }
        if (score > bestScore) {
            bestScore = score;
            bestIndex = static_cast<int>(i);
        }
    }
    riskObj = &arr[bestIndex];
}

int main()
{
    const uint32 count = 3u;
    DetectedObject* objects = new DetectedObject[count] {
        DetectedObject(701u, 15.0f, 55.0f),
        DetectedObject(702u, 20.0f, 35.0f),
        DetectedObject(703u, 10.0f, 30.0f)
    };

    std::cout << "Initial objects:\n";
    for (uint32 i = 0u; i < count; ++i) printDetectedObject(objects[i]);

    // Demonstrate update by value (no change to original)
    std::cout << "\nCalling updateObjectValuesByValueGlobal on object 701 \n";
    updateObjectValuesByValueGlobal(objects[0]);
    std::cout << "After update by value (original should be unchanged):\n";
    printDetectedObject(objects[0]);

    // Demonstrate update by reference (modifies original)
    std::cout << "\nCalling updateObjectValuesByReferenceGlobal on object 702 \n";
    updateObjectValuesByReferenceGlobal(objects[1]);
    std::cout << "After update by reference (original changed):\n";
    printDetectedObject(objects[1]);

    // Find and print highest risk object
    const DetectedObject* highestRisk = nullptr;
    findHighestRiskObject(objects, count, highestRisk);
    printHighestRiskObject(highestRisk);

    delete [] objects;
    objects = nullptr;
    return 0;
}
