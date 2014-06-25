//
//  chess_clock.cpp
//  Chess_Clock
//
//  Created by Ben de Haan on 6/16/14.
//  Copyright (c) 2014 Rainero. All rights reserved.
//

#include "chess_clock.h"

int chessClock::startClock() {
    //for now calls toggle clock no matter the argument
    this->clock.toggleClock();
    return 1;
}






int* chessClock::getTimePlayer(int player) {
    sf::Int32 total_time_ms = this->clock.getTime(player);
    int time_ms = total_time_ms % 1000;
    int time_seconds = ((total_time_ms) / 1000) % 60;
    int time_minutes = total_time_ms / 60000;
    int* time_player = (int*)malloc(4*3);
    //int time_player[3] = {time_minutes, time_seconds, time_ms};
    time_player[0] = time_minutes;
    time_player[1] = time_seconds;
    time_player[2] = time_ms;
    return time_player;
}


void chessClock::setTimePlayer(int* time, int player) {
    sf::Int32 total_time_ms = time[0] * 60000 + time[1]*1000 + time[2];
    this->clock.setTime(total_time_ms, player);
}


int chessClock::stopClock() {
    return this->clock.stopClock();
}


void chessClock::terminate() {
    this->clock.terminate();
}