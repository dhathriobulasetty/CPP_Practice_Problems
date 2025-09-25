#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Dhathri_Sept25_task2_Card.h"
#include <vector>

class DeckOfCards
{
private:
    std::vector<Card> deck;
    int currentCard;

public:
    // Constructor
    DeckOfCards();

    // Shuffle the deck
    void shuffle();

    // Deal one card
    Card dealCard();

    // Check if there are more cards
    bool moreCards() const;
};

#endif // DECKOFCARDS_H
