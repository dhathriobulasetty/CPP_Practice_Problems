#include <iostream>
#include <string>

class ParcelAnalyzer {
public:
    // grams
    std::string classifyWeight(int grams)
    {
        if (grams < 0) grams = 0; // validate
        if (grams < 500) return "Light";
        if (grams <= 2000) return "Medium";
        return "Heavy";
    }

    // kilograms
    std::string classifyWeight(float kilograms)
    {
        if (kilograms < 0.0f) kilograms = 0.0f;
        if (kilograms < 0.5f) return "Light";
        if (kilograms <= 2.0f) return "Medium";
        return "Heavy";
    }

    // pounds
    std::string classifyWeight(double pounds)
    {
        if (pounds < 0.0) pounds = 0.0;
        if (pounds < 1.1) return "Light";
        if (pounds <= 4.4) return "Medium";
        return "Heavy";
    }
};

// Global function
void printClassification(const std::string& label)
{
    std::cout << label << "\n";
}

int main()
{
    ParcelAnalyzer analyzer;

    // Sample test cases 
    printClassification("classifyWeight(450) -> " + analyzer.classifyWeight(450));
    printClassification("classifyWeight(1500) -> " + analyzer.classifyWeight(1500));
    printClassification("classifyWeight(2500) -> " + analyzer.classifyWeight(2500));

    printClassification("classifyWeight(0.3f) -> " + analyzer.classifyWeight(0.3f));
    printClassification("classifyWeight(1.5f) -> " + analyzer.classifyWeight(1.5f));
    printClassification("classifyWeight(3.0f) -> " + analyzer.classifyWeight(3.0f));

    printClassification("classifyWeight(0.9) -> " + analyzer.classifyWeight(0.9));
    printClassification("classifyWeight(2.5) -> " + analyzer.classifyWeight(2.5));
    printClassification("classifyWeight(5.0) -> " + analyzer.classifyWeight(5.0));

    return 0;
}
