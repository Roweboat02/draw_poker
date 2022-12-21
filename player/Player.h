//
// Created by noahr on 19/12/22.
//

#ifndef POKER_PLAYER_H
#define POKER_PLAYER_H


#include "PlayerBank.h"
#include "PlayerHand.h"

class Player {
    public:
        PlayerBank bank = PlayerBank();
        PlayerHand hand = PlayerHand();

        Card* ptr_for_cards() {return hand.hand;}
        bool* ptr_for_held() {return hand.holding;}

        void bet(){bank.place_bet();}
        void fold(){bank.clear_bet();}

        void bank_stats(int* bank_stats);  // bank_stats={total, bet amount}

        std::string hand_as_str(); // hand_vals must be 10 chars long

        void holding_vals(bool* held);

        void add_winnings(int winnings){ bank.add_winnings(winnings); bank.clear_bet();}



        int num_cards_to_replace(){return 5 - hand.number_of_held();}

        void replace_non_held(Card* new_cards){hand.replace_non_held(new_cards);}

        void modify_holding(int i);
    private:
        void add_to_holding(int index){hand.add_to_holding(index);}  // Index of card in hand, to hold
        void remove_from_holding(int index){hand.remove_from_holding(index);}  // Index of card in hand/hold, to remove from hold
};


#endif //POKER_PLAYER_H
