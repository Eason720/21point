#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"
#include "Deck.h"

class Player {
public:
    void drawCard(Deck& deck);
    int getHandValue() const;
    void showHand() const;

private:
    std::vector<Card> hand;
};

#endif // PLAYER_H
