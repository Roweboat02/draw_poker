//
// Created by noahr on 19/12/22.
//

#include "PokerCLI.h"

void PokerCLI::print_hand() {
    char hand_as_str[10];
    player.hand_as_str(hand_as_str);
    std::cout << "Hand: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << hand_as_str[i*2] << hand_as_str[i*2+1] << " | ";
    }
    std::cout <<std::endl;
}
void PokerCLI::print_held() {
    bool being_held[5];
    player.holding_vals(being_held);
    std::cout << "Hand: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << being_held[i] << " | " ;
    }
    std::cout <<std::endl;
}

void PokerCLI::print_bank() {
    int bank_stats[2];
    player.bank_stats(bank_stats);
    std::cout << "Total: " << bank_stats[0] << " Bet: " << bank_stats[1] << std::endl;
}

void PokerCLI::start() {
    game.first_deal(player.ptr_for_cards());
    player.bet();

    state = DECISION0;
}

void PokerCLI::fold_or_bet() {
    while (true) {
        print_bank();
        print_hand();
        std::cout << "Fold or Bet [F/B]" << std::endl;
        char ans;
        std::cin >> ans;
        if (ans == 'F') {
            player.fold();
            state = DEAL0;
            start();
            return;
        } else if (ans == 'B') {
            if (state==DECISION0){
                player.bet();
                state=CARD_DECISION;
                return;
            } else if (state==DECISION1){
                player.bet();
                state=ASSESS;
                return;
            }
        }
    }
}

void PokerCLI::modify_holding() {
    while(true){
        std::cout << "type 0,1,2,3,4 to hold/unhold that card" << std::endl;
        char ans[1];
        std::cin >> ans;
        if (ans[0]!='\n') {
            int to_hold = std::stoi(ans);
            if (-1 < to_hold && to_hold < 5) {
                player.modify_holding(to_hold);
                print_held();
            }
        } else {
            state=DEAL1;
            return;
        }

    }
}

void PokerCLI::second_deal() {
    int num_to_replace = player.num_cards_to_replace();
    Card new_cards[num_to_replace+1];
    new_cards[num_to_replace] = Card();
    game.second_deal(num_to_replace, new_cards);
    state=DECISION1;
}

void PokerCLI::assess() {
    player.add_winnings(game.assess(player.ptr_for_cards()));
    print_hand();
    print_bank();
    char ans;
    std::cin>>ans;
    state = DEAL0;
}

void PokerCLI::play() {
    while (true){
        advance();
    }
}

void PokerCLI::advance() {
    switch (state) {
        case (DEAL0):
            start();
            break;
        case (DECISION0):
            fold_or_bet();
            break;
        case (CARD_DECISION):
            modify_holding();
            break;
        case (DEAL1):
            second_deal();
            break;
        case (DECISION1):
            fold_or_bet();
            break;
        case (ASSESS):
            assess();
            break;
    }
}



