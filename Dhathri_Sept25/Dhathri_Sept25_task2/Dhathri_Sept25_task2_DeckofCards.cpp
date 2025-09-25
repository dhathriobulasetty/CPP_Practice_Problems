#include "Dhathri_Sept25_task2_DeckofCards.h"
#include <algorithm> // for swap
#include <cstdlib>   // for rand, srand
#include <ctime>     // for time

// Constructor: initialize deck with 52 cards
DeckOfCards::DeckOfCards() : currentCard(0)
{
    for (int suit = 0; suit < 4; ++suit)
    {
        for (int face = 0; face < 13; ++face)
        {
            deck.push_back(Card(face, suit));
        }
    }
}

// Shuffle deck using simple swap algorithm
void DeckOfCards::shuffle()
{
    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < deck.size(); ++i)
    {
        size_t j = rand() % deck.size();
        std::swap(deck[i], deck[j]);
    }
    currentCard = 0; // reset dealing position
}

// Deal one card
Card DeckOfCards::dealCard()
{
    if (moreCards())
    {
        return deck[currentCard++];
    }
    else
    {
        return Card(0, 0); // default: Ace of Hearts if no more cards
    }
}

// Check if there are cards left
bool DeckOfCards::moreCards() const
{
    return currentCard < static_cast<int>(deck.size());
}
