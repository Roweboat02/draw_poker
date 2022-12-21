//
// Created by noahr on 20/12/22.
//

#ifndef POKER_TOPLEVEL_H
#define POKER_TOPLEVEL_H


#include <string>
#include "view/View.h"
#include "game/Game.h"
#include "player/Player.h"

enum State{DEAL0, DECISION0, CARD_DECISION, DEAL1, DECISION1, ASSESS, FOLD};

class TopLevel {
    View view = View();
    Game game = Game();
    Player player = Player();
    int state = DEAL0;
    int round_count = 0;

private:
    void start();
    void second_deal();
    void decision(bool fold_or_play);
    void assess(); // return winnings amount
    void fold();
public:
    [[noreturn]] void play(){
        while (true) {
            start();
            round_count++;
        }
    }
};


#endif //POKER_TOPLEVEL_H
