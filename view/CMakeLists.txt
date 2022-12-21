cmake_minimum_required(VERSION 3.23)
project(poker)

set(CMAKE_CXX_STANDARD 14)


#add_library(gamelib.a game/Game.h ${GAME})
#add_library(playerlib.a player/Player.h ${PLAYER})
#
#target_include_directories(gamelib.a PRIVATE game)
#target_include_directories(playerlib.a PRIVATE player)


add_executable(poker
        View.cpp
        View.h
        PokerCLI.cpp
        PokerCLI.h
        PointBoard.cpp PointBoard.h CardButton.cpp CardButton.h)



