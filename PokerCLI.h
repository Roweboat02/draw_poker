//
// Created by noahr on 19/12/22.
//

#ifndef POKER_POKERCLI_H
#define POKER_POKERCLI_H


#include "game/Game.h"
#include "player/Player.h"

enum State{DEAL0, DECISION0, CARD_DECISION, DEAL1, DECISION1, ASSESS};

class PokerCLI {
    Game game = Game();
    Player player = Player();
    int state = DEAL0;

    void print_hand();
    void print_held();
    void print_bank();
    void start();  // trigger initial deal
    void fold_or_bet();  // type "fold" or "bet"
    void modify_holding();  // Add or remove typed index to holding until '\n' is entered
    void second_deal();
    void assess();

public:
    void play();
    void advance();
};


#endif //POKER_POKERCLI_H
