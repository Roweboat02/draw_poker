//
// Created by noahr on 19/12/22.
//

#include "PlayerBank.h"

void PlayerBank::place_bet() {
    total-=5;
    bet+=5;
}

void PlayerBank::clear_bet() {
    bet=0;
}

void PlayerBank::add_winnings(int winnings) {
    total+=winnings;
}
