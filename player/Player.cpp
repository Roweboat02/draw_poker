//
// Created by noahr on 19/12/22.
//

#include "Player.h"

void Player::bank_stats(int *bank_stats) {
    bank_stats[0]=bank.total; bank_stats[1]=bank.bet;
}

std::string Player::hand_as_str() {
    std::string str = "";
    for (int i = 0; i < 5; ++i) {
        str+=hand.hand[i].card_as_str();
    }
    return str;
}

void Player::holding_vals(bool* held_indeces) {
    for (int i = 0; i < 5; ++i) {
        held_indeces[i] = hand.holding[i];
    }
}

void Player::modify_holding(int i) {
    if (hand.holding[i]){
        add_to_holding(i);
    } else {
        remove_from_holding(i);
    }
}
