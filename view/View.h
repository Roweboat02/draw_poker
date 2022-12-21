//
// Created by noahr on 20/12/22.
//

#ifndef POKER_VIEW_H
#define POKER_VIEW_H


#include <string>
#include "CardButton.h"
#include "PointBoard.h"

class View {
    CardButton card_buttons[5];
    PointBoard pointBoard;
public:
    View(){}

    // cards is 5 cards, ending in /0 ;; return true=>continue game
    bool start(const std::string& cards, int total_points, int bet_val);
    void divey_to_buttons(const std::string& cards);

    void request_held_cards_arr(bool* out);

    bool receive_second_deal(const std::string& cards, int total_points, int bet_val); //return true=>continue game

    void receive_assessment(int winnings, int total_points, int bet_val, bool folded=false);
};


#endif //POKER_VIEW_H
