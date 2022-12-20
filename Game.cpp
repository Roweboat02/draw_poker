//
// Created by noahr on 19/12/22.
//

#include "Game.h"

void Game::advance_stage() {
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
    Card* arr = player.ptr_for_cards();
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
    Assessor ass = Assessor(player.ptr_for_cards());
    int winnings = ass_table.assess(ass.hand_value);
    player.add_winnings(winnings);
}


