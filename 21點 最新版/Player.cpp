#include "Player.h"
#include <iostream>

void Player::drawCard(Deck& deck) {
    hand.push_back(deck.drawCard());
}

int Player::getHandValue() const {
    int total = 0;
    for (const auto& card : hand) {
        total += card.getValue();
    }
    return total;
}

void Player::showHand() const {
    for (const auto& card : hand) {
        std::cout << card.getValue() << " ";
    }
    std::cout << std::endl;
}
