//
// Created by noahr on 18/12/22.
//

#ifndef POKER_ASSESSOR_H
#define POKER_ASSESSOR_H


#include "card.h"
#include "enum_hand.h"


class Assessor{
private:
    bool straight;
    bool flush;

    static bool is_flush(Card hand[]);  // 5 card of same suit => true
    static bool is_straight(Card hand[]);  // 5 card in ascending order => true

    static void count_cards(Card hand[], int out[3]);  // Number of cards with same value
    static int counts_to_groups(const int counts[3]);  // Number of {pairs, three of kind, four of kind}
public:
    int hand_value;
    explicit Assessor(Card hand[5]);
};


#endif //POKER_ASSESSOR_H
