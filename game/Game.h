//
// Created by noahr on 19/12/22.
//

#ifndef POKER_GAME_H
#define POKER_GAME_H


#include "Assessor.h"
#include "CardDeck.h"
#include "AssesmentTable.h"


class Game {
private:
    CardDeck deck;
    AssesmentTable ass_table;
public:
    void first_deal(Card* hand);

    void second_deal(int cards_to_replace, Card* replacement_cards);

    int assess(Card* hand);

};


#endif //POKER_GAME_H
