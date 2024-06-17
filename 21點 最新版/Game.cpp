#include "Game.h"
#include <iostream>

Game::Game() : deck(), player(), dealer() {}

void Game::play() {
    std::cout << "Welcome to Blackjack!" << std::endl;

    // Initial draw
    player.drawCard(deck);
    dealer.drawCard(deck);
    player.drawCard(deck);
    dealer.drawCard(deck);

    std::cout << "Your hand: ";
    player.showHand();
    std::cout << "Dealer's hand: ";
    dealer.showHand();

    char choice;
    while (true) {
        std::cout << "Do you want to hit or stand? (h/s): ";
        std::cin >> choice;
        if (choice == 'h') {
            player.drawCard(deck);
            std::cout << "Your hand: ";
            player.showHand();

            if (player.getHandValue() > 21) {
                std::cout << "You busted! Dealer wins." << std::endl;
                return;
            }
        }
        else if (choice == 's') {
            break;
        }
        else {
            std::cout << "Invalid choice. Please enter 'h' to hit or 's' to stand." << std::endl;
        }
    }

    // Dealer's turn
    while (dealer.getHandValue() < 17) {
        dealer.drawCard(deck);
    }

    std::cout << "Dealer's hand: ";
    dealer.showHand();

    // Determine winner
    int playerValue = player.getHandValue();
    int dealerValue = dealer.getHandValue();

    if (dealerValue > 21 || playerValue > dealerValue) {
        std::cout << "You win!" << std::endl;
    }
    else if (playerValue == dealerValue) {
        std::cout << "It's a tie!" << std::endl;
    }
    else {
        std::cout << "Dealer wins." << std::endl;
    }
}
