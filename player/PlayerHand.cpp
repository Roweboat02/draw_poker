//
// Created by noahr on 19/12/22.
//

#include "PlayerHand.h"

void PlayerHand::clear_holding() {
    holding[0]=Card();
    holding[1]=Card();
    holding[2]=Card();
    holding[3]=Card();
    holding[4]=Card();
    holding[5]=Card();
}

int PlayerHand::number_of_held() {
    int count=0;
    for (Card & i : holding){
        if(i.val!=0){count++;}
    }
    return count;
}


void PlayerHand::replace_non_held(Card *new_cards) {
    int new_card_ind=0;
    for (int i=0; i<5; i++){
        if (holding[i].val==0){
            hand[i]=new_cards[new_card_ind++];
        }
    }
    clear_holding();
}

void PlayerHand::add_to_holding(int index) {
    holding[index] = hand[index];
}

void PlayerHand::remove_from_holding(int index) {
    holding[index] = Card();
}
