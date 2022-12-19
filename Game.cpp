//
// Created by noahr on 19/12/22.
//

#include "Game.h"

void Game::advance() {
    switch (stage){
        case FIRST_DEAL:
            first_deal();
            stage = SECOND_DEAL;
            break;
        case SECOND_DEAL:
            second_deal();
            stage = ASSESS;
            break;
        case ASSESS:
            assess();
            stage = FIRST_DEAL;
            break;
    }
}

void Game::first_deal() {
    deck = CardDeck();
    player.bet();
    Card* arr = player.ptr_for_deal();
    deck.draw(5,arr);
    arr[5]=Card();
}

void Game::second_deal() {
    int card_num = player.cards_to_replace();
    Card new_cards[card_num];
    deck.draw(card_num, new_cards);
    player.replace_non_held(new_cards);
    player.bet();
}

void Game::assess() {
    Assessor ass = Assessor(player.ptr_for_deal());
    int winnings = 0;
    switch(ass.hand_value){
        case HIGH_CARD:
            winnings=0;
            break;
        case PAIR:
            winnings=5;
            break;
        case TWO_PAIR:
            winnings=10;
            break;
        case THREE_OF_A_KIND:
            winnings=15;
            break;
        case STRAIGHT:
            winnings=20;
            break;
        case FLUSH:
            winnings=25;
            break;
        case FULL_HOUSE:
            winnings=40;
            break;
        case FOUR_OF_A_KIND:
            winnings=125;
            break;
        case STRAIGHT_FLUSH:
            winnings=250;
            break;
        case ROYAL_FLUSH:
            winnings=1000;
            break;
    }
    player.add_winnings(winnings);
}


