//
// Created by noahr on 19/12/22.
//

#ifndef POKER_PLAYER_H
#define POKER_PLAYER_H


#include "PlayerBank.h"
#include "PlayerHand.h"

class Player {
    public:
        PlayerBank bank;
        PlayerHand hand;

        Card* ptr_for_deal();
        void bet(){bank.place_bet();}
        void add_winnings(int winnings){ bank.add_winnings(winnings); bank.clear_bet();}
        int cards_to_replace(){return 5-hand.number_of_held();}
        void replace_non_held(Card* new_cards){hand.replace_non_held(new_cards);}
};


#endif //POKER_PLAYER_H
