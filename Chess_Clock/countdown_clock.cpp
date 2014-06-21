//
//  countdown_clock.cpp
//  Chess_Clock
//
//  Created by Ben de Haan on 6/16/14.
//  Copyright (c) 2014 Rainero. All rights reserved.
//

#include "countdown_clock.h"

void countdownClock::startClock() {
    sf::Time elapsed_time;
    while (this->time[0] != 0 || this->time[1] != 0) {
        while (clock_state == CLOCK_RUNNING) {
            elapsed_time = this->clock.restart();
            this->time[this->current_player] -= elapsed_time.asMilliseconds();
        }
    }
}


int countdownClock::toggleClock() {
    if (this->clock_state == CLOCK_RUNNING) {
        this->current_player = (this->current_player + 1) % 2;
        return 1;
    }
    return 0;
    
}


sf::Int32 countdownClock::getTime(int player) {
    return this->time[player];
}


void countdownClock::setTime(sf::Int32 time, int player) {
    this->clock_state = CLOCK_SET;
    this->time[player] = time;
}


int countdownClock::stopClock() {
    if (this->clock_state == CLOCK_RUNNING) {
        
        this->clock_state = CLOCK_SET;
        return 1;
    }
    return 0;
}



countdownClock::countdownClock() {
    this->clock_state = CLOCK_SET;
    this->time[0] = 60000;
    this->time[1] = 60000;
    this->current_player = 0;
    
}