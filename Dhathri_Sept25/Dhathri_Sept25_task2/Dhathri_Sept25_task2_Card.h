#ifndef CARD_H
#define CARD_H

#include <string>
#include <array>

class Card
{
private:
    int face;
    int suit;

public:
    // Constructor
    Card(int faceValue, int suitValue);

    // Convert card to string
    std::string toString() const;

    // Static arrays for faces and suits
    static const std::array<std::string, 13> faces;
    static const std::array<std::string, 4> suits;
};

#endif // CARD_H
