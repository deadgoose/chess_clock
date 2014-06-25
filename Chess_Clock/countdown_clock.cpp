//
//  countdown_clock.cpp
//  Chess_Clock
//
//  Created by Ben de Haan on 6/16/14.
//  Copyright (c) 2014 Rainero. All rights reserved.
//

#include "countdown_clock.h"

void countdownClock::startClock() {
    std::cout << "entering thread\n";
    sf::Time elapsed_time;

    while (clock_state != CLOCK_TERMINATE) {
        //std::cout << "clock state is " << this->clock_state << "\n";
        this->clock.restart();
        while (clock_state == CLOCK_RUNNING) {
            //std::cout << "clock running !\n";
            
            elapsed_time = this->clock.restart();
            if (elapsed_time.asMilliseconds() < this->time[this->current_player]) {
                this->time[this->current_player] -= elapsed_time.asMilliseconds();
                //std::cout << "player " << this->current_player << "time is " << this->time[this->current_player] << "\n";
            }
            else {
                this->time[this->current_player] = -1;
                this->clock_state = CLOCK_PAUSED;
            }
            
        }
    }
}


int countdownClock::toggleClock() {
    if (this->clock_state == CLOCK_RUNNING) {
        this->current_player = (this->current_player + 1) % 2;
        return 1;
    }
    else {
        this->clock_state = CLOCK_RUNNING;
    }
    return 1;
    
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


void countdownClock::terminate() {
    this->clock_state = CLOCK_TERMINATE;
    std::cout<<"call terminate in countdown clock\n";
}