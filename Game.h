//
// Created by noahr on 19/12/22.
//

#ifndef POKER_GAME_H
#define POKER_GAME_H


#include "Player.h"
#include "Assessor.h"
#include "CardDeck.h"

enum Stage{FIRST_DEAL, SECOND_DEAL, ASSESS};

class Game {
private:
    Player player;

    int stage;

    CardDeck deck;

    void first_deal();

    void second_deal();

    void assess();
public:
    void advance();
};


#endif //POKER_GAME_H
