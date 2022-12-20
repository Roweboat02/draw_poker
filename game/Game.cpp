//
// Created by noahr on 19/12/22.
//

#include "Game.h"


void Game::first_deal(Card* hand) {
    deck = CardDeck();
    deck.draw(5,hand);
    hand[5]=Card();
}

void Game::second_deal(int cards_to_replace, Card* replacement_cards) {
    deck.draw(cards_to_replace, replacement_cards);
}

int Game::assess(Card* hand) {
    Assessor ass = Assessor(hand);
    return ass_table.assess(ass.hand_value);
}



