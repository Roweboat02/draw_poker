//
// Created by noahr on 20/12/22.
//

#ifndef POKER_POINTBOARD_H
#define POKER_POINTBOARD_H


class PointBoard {
    int total_points=100;
    int bet_val=0;
    int winnings=0;;

public:
    void set_winnings(int earnings){
        winnings = earnings;
    }

    void clear_winnings(){
        winnings=0;
    }

    void set(int total_points, int bet_val){
        this->total_points=total_points;
        this->bet_val=bet_val;
    }
};


#endif //POKER_POINTBOARD_H
