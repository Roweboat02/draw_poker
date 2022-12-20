cmake_minimum_required(VERSION 3.23)
project(poker)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        poker
        Assessor.cpp
        Assessor.h
        card.h
        CardDeck.cpp
        CardDeck.h
        main.cpp
        PlayerHand.cpp
        PlayerHand.h main.cpp main.cpp PlayerBank.cpp PlayerBank.h Game.cpp Game.h Player.cpp Player.h AssesmentTable.cpp AssesmentTable.h enum_hand.h PokerCLI.cpp PokerCLI.h)
