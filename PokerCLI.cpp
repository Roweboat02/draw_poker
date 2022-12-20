//
// Created by noahr on 19/12/22.
//

#include "PokerCLI.h"

void PokerCLI::print_hand() {
    std::string hand_str = player.hand_as_str();
    std::cout << "Hand: ";
    int step = hand_str.length()/5;
    for (int i = 0; i < 5; ++i) {
        std::cout << hand_str.substr(i*step,step)
        << " | ";
    }
    std::cout <<std::endl;
}
void PokerCLI::print_held() {
    bool being_held[5];
    player.holding_vals(being_held);
    std::cout << "Held: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << being_held[i] << "  | " ;
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

void PokerCLI::fold_or_play() {
    while (true) {
        print_bank();
        print_hand();
        std::cout << "Fold or Play [f/p]" << std::endl;
        char ans;
        std::cin >> ans;
        if (ans == 'f') {
            player.fold();
            state = DEAL0;
            start();
            return;
        } else if (ans == 'p') {
            if (state==DECISION0){
                state=CARD_DECISION;
                return;
            } else if (state==DECISION1){

                state=ASSESS;
                return;
            }
        }
    }
}

void PokerCLI::modify_holding() {
    std::cout << "type 0,1,2,3,4 to hold/unhold that card" << std::endl;
    while(true){

        print_hand();
        print_held();

        char ans[1];
        std::cin >> ans;
        if (ans[0]=='0' || ans[0]=='1' ||ans[0]=='2' ||ans[0]=='3' ||ans[0]=='4') {
            int to_hold = std::stoi(ans);
            if (-1 < to_hold && to_hold < 5) {
                player.modify_holding(to_hold);
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
    player.replace_non_held(new_cards);
    player.bet();
    state=DECISION1;
}

void PokerCLI::assess() {
    int winnings = game.assess(player.ptr_for_cards());
    player.add_winnings(winnings);
    print_hand();
    print_bank();
    std::cout<< "Hand Value: " << winnings << std::endl;
    std::cout<< "Enter any key to continue"<< std::endl;
    char ans;
    std::cin>>ans;
    state = DEAL0;
}

void PokerCLI::play() {
    std::cout<<std::endl;
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
            fold_or_play();
            break;
        case (CARD_DECISION):
            modify_holding();
            break;
        case (DEAL1):
            second_deal();
            break;
        case (DECISION1):
            fold_or_play();
            break;
        case (ASSESS):
            assess();
            break;
    }
}



