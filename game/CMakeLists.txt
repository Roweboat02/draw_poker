cmake_minimum_required(VERSION 3.23)
project(game)

set(CMAKE_CXX_STANDARD 14)

set(GAME
        AssesmentTable.h
        AssesmentTable.cpp
        Assessor.h
        Assessor.cpp
        card.h
        CardDeck.h
        CardDeck.cpp
        enum_hand.h
        enum_card.h
        Game.h
        Game.cpp
        )


add_executable(poker
        game_main.cpp
        ${GAME}
)


