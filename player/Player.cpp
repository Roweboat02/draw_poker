//
// Created by noahr on 19/12/22.
//

#include "Player.h"

Card *Player::ptr_for_cards() {
    return hand.hand;
}

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
        held_indeces[i] = (hand.holding[i].val != 0);
    }
}

void Player::modify_holding(int i) {
    if (hand.holding[i].val==0){
        add_to_holding(i);
    } else {
        remove_from_holding(i);
    }
}
