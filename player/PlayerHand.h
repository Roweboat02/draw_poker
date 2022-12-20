//
// Created by noahr on 19/12/22.
//

#ifndef POKER_PLAYERHAND_H
#define POKER_PLAYERHAND_H
#include "card.h"


class PlayerHand {
    public:
        Card hand[6];
        Card holding[6];

        int number_of_held();  // Count non-zero card's in holding

        void replace_non_held(Card new_cards[]);  // any card which is 0 in holding is replaced using val from new_cards

        void add_to_holding(int index);  // Index of card in hand, to hold
        void remove_from_holding(int index);  // Index of card in hand/hold, to remove from hold



        PlayerHand(){clear_holding();};

    private:
        void clear_holding();

};


#endif //POKER_PLAYERHAND_H
