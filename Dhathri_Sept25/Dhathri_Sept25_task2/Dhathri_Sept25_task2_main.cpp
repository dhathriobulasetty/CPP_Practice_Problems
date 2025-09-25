#include "Dhathri_Sept25_task2_DeckofCards.h"
#include <iostream>

int main()
{
    DeckOfCards deck;

    deck.shuffle();

    std::cout << "Shuffled deck:\n";

    int count = 0;
    while (deck.moreCards())
    {
        std::cout << deck.dealCard().toString() << "\n";

        // print 4 cards per line
        if (++count % 4 == 0)
        {
            std::cout << "----\n";
        }
    }

    return 0;
}
