#include "Deck.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

Deck::Deck() {
    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j < 4; ++j) {
            cards.push_back(Card(i));
        }
    }
    shuffleDeck();
}

void Deck::shuffleDeck() {
    std::srand(std::time(0));
    std::random_shuffle(cards.begin(), cards.end());
}

Card Deck::drawCard() {
    if (cards.empty()) {
        throw std::out_of_range("No more cards in the deck.");
    }
    Card drawn = cards.back();
    cards.pop_back();
    return drawn;
}
