//
// Created by noahr on 19/12/22.
//

#ifndef POKER_PLAYERBANK_H
#define POKER_PLAYERBANK_H


class PlayerBank {

    public:
        int total = 100;
        int bet = 0;

        void place_bet(); // sub 5 from total, and put in "bet"

        void clear_bet();

        void add_winnings(int winnings);

};


#endif //POKER_PLAYERBANK_H
