//
// Created by noahr on 20/12/22.
//

#include "View.h"

#include <utility>

bool View::start(const std::string& cards, int total_points, int bet_val) {
    divey_to_buttons(cards);
    pointBoard.set(total_points, bet_val);
}

void View::divey_to_buttons(const std::string& cards) {
    int step = cards.length()/5;
    for (int i = 0; i < 5; ++i) {
        card_buttons[i].set(cards.substr(i*step, step));
    }
}

void View::request_held_cards_arr(bool *out) {
    for (int i = 0; i < 5; ++i) {
        out[i] = card_buttons[i].held;
    }
}

bool View::receive_second_deal(const std::string& cards, int total_points, int bet_val) {
    divey_to_buttons(cards);
    pointBoard.set(total_points, bet_val);
}


void View::receive_assessment(int winnings, int total_points, int bet_val, bool folded) {
    pointBoard.set_winnings(winnings);
    pointBoard.set(total_points, bet_val);
    // AWAIT CARD INPUT
    return pointBoard.clear_winnings();
}
