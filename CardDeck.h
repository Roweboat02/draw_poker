//
// Created by noahr on 18/12/22.
//
#include <list>
#include <random>
#include <chrono>
#include "card.h"

#ifndef POKER_CARDDECK_H
#define POKER_CARDDECK_H


class CardDeck {
    private:

        int spent_cards[15];
        int rand_num(int low, int high);
        int random_suit();  // return 0,1,2,3
        int random_val();  // return 2,3,4,5,6,7,8,9,10,11,12,13,14
        Card random_card(); // Card::from_int(random_suit*14 + random_val) if not in spent_cards
    public:
        CardDeck();
        void draw(int n, Card out[]);
};
#endif //POKER_CARDDECK_H
