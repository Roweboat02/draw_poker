//
// Created by noahr on 18/12/22.
//

#include "Assessor.h"
#include "enum_hand.h"

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
            i++;
        }
        hand_value=STRAIGHT_FLUSH;
        return;
    } else if (flush) {hand_value=FLUSH; return;}
    else if (straight) {hand_value=STRAIGHT; return;}

    int groupings[3] = {0,0,0};
    count_cards(hand, groupings);
    hand_value = counts_to_groups(groupings);
}

void count_suit_occurences(Card hand[], int out[4]){
    for (int suit=0; suit<4; suit++){
        int i=0;
        while(hand[i].val!=0){
            if (hand[i].suit==suit){
                out[suit]++;
            }
            i++;
        }
    }
}
bool Assessor::is_flush(Card hand[]){
    int suit_counts[4]={0,0,0,0};
    count_suit_occurences(hand, suit_counts);
    for (int suit_count : suit_counts){
        if (suit_count==5){return true;}
    }
    return false;
}

short hand_as_val_set(Card hand[]){
    short val_set = 0;
    int i=0;
    while (hand[i].val!=0){
        val_set |= 1<<(hand[i].val-1);
        i++;
    }
    return val_set;
}

bool Assessor::is_straight(Card hand[]){
    // Find min card value
    short val_set = hand_as_val_set(hand);
    short answer = 0b11111;
    int i=0;
    while (hand[i].val!=0){
        answer <<= i;
        if ((answer & val_set) == answer){
            return true;
        }
        i++;
    }
    return false;
}

void Assessor::count_cards(Card hand[], int out[3]){
    // out {pairs, three of a kind, four of a kind}
    bool vals_in_hand[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    int i =0;
    while (hand[i].val!=0){
        vals_in_hand[hand[i].val-2] = true;
        i++;
    }
    for (int card_val = TWO; card_val<=ACE; card_val++){
        if (!vals_in_hand[card_val-2]){ continue;}
        int card_index = 0;
        int count = 0;
        while (hand[card_index].val!=0){
            if(hand[card_index].val == card_val){
                count++;
            }
            card_index++;
        }
        if((count-2)>-1){out[count-2]++;}
    }
}

int Assessor::counts_to_groups(const int counts[3]){
    // Returns array containing {count of 2's, count of 3's, count of 4's}
    if (counts[2]>0){return FOUR_OF_A_KIND;}
    else if (counts[1]==1 && counts[0]==1){return FULL_HOUSE;}
    else if (counts[1]==1){return THREE_OF_A_KIND;}
    else if (counts[0]==2){return TWO_PAIR;}
    else if (counts[0]==1){return PAIR;}
    else {return HIGH_CARD;}
}