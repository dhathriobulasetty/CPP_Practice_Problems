#include "Dhathri_Sept25_task2_Card.h"

// Initialize static arrays
const std::array<std::string, 13> Card::faces = {
    "Ace", "Deuce", "Three", "Four", "Five", "Six", 
    "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

const std::array<std::string, 4> Card::suits = {
    "Hearts", "Diamonds", "Clubs", "Spades"};

// Constructor
Card::Card(int faceValue, int suitValue) : face(faceValue), suit(suitValue) {}

// Return card description
std::string Card::toString() const
{
    return faces[face] + " of " + suits[suit];
}
