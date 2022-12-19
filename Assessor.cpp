//
// Created by noahr on 18/12/22.
//

#include "Assessor.h"

Assessor::Assessor(Card hand[]){
    flush = is_flush(hand);
    straight = is_straight(hand);

    if (flush && straight){
        int i =0;
        while(hand[i].val!=0){
            if(hand[i].val==ACE){
                hand_value=ROYAL_FLUSH;
                return;
            }
        }
        hand_value=STRAIGHT_FLUSH;
        return;
    } else if (flush) {hand_value=FLUSH; return;}
    else if (straight) {hand_value=STRAIGHT; return;}
    int counts[5] = {0,0,0,0,0,};
    int count_of_counts[3] = {0,0,0};
    count_cards(hand, counts);
    count_counts(counts, count_of_counts);

    if (count_of_counts[2]>0) {
        hand_value=FOUR_OF_A_KIND;
        return;
    } else if (count_of_counts[1]==3 && count_of_counts[0]==2){
        hand_value=FULL_HOUSE;
        return;
    } else if (count_of_counts[0]==4){
        hand_value=TWO_PAIR;
        return;
    } else if (count_of_counts[0]==2){
        hand_value=PAIR;
        return;
    }

}

void count_suit_occurences(Card hand[], int out[4]){
    for (int suit=0; suit<4; suit++){
        int i=0;
        while(hand[i].val!=0){
            if (hand[i].suit==suit){out[suit]++;}
        }
    }
}
bool Assessor::is_flush(Card hand[5]){
    int suit_counts[4]={0,0,0,0};
    count_suit_occurences(hand, suit_counts);
    for (int suit_count : suit_counts){
        if (suit_count==5){return true;}
    }
    return false;
}

bool Assessor::is_straight(Card hand[]){
    // Find min card value

    int min_val=hand[0].val;
    int i=0;
    while (hand[i].val!=0){
        if (hand[i].val<min_val){min_val=hand[i].val;}
    }
    bool possible=true;
    int loops=0;


    while (possible)
    {
        loops++;
        for (int i=0; i<5; i++){
            if (hand[i].val==min_val+loops){break;}
            if(i==4){possible=false;}
            // If none of cards are req'd val, not straight
        }
        if (loops==4){break;}
        // If 5 cards are present, in ascending order, finish
    }
    return possible;

}

void Assessor::count_cards(Card hand[5], int out[5]){
    for (int i=0; i<5; i++){
        for (int j=0; j<6; j++){
            if(hand[i].val==hand[j].val){out[i]++;}
        }
    }
}

void Assessor::count_counts(int counts[5], int out[3]){
    // Returns array containing {count of 2's, count of 3's, count of 4's}
    for (int i=0; i<3; i++){
        for (int j=0; j<5; j++){
            if(i+2==counts[j]){
                out[i]++;
            }
        }
    }
}