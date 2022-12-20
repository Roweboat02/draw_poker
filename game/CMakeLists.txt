cmake_minimum_required(VERSION 3.23)
project(game)

set(CMAKE_CXX_STANDARD 14)

set(GAME
        game/AssesmentTable.h
        game/AssesmentTable.cpp
        game/Assessor.h
        game/Assessor.cpp
        game/card.h
        game/CardDeck.h
        game/CardDeck.cpp
        game/enum_hand.h
        game/enum_card.h
        game/Game.h
        game/Game.cpp
        )


add_executable(poker
        main.cpp
        ${GAME}
)


