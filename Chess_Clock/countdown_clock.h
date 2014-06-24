//
//  countdown_clock.h
//  Chess_Clock
//
//  Created by Ben de Haan on 6/16/14.
//  Copyright (c) 2014 Rainero. All rights reserved.
//

#ifndef __Chess_Clock__countdown_clock__
#define __Chess_Clock__countdown_clock__

#include <iostream>
#include <SFML/Graphics.hpp>

#define CLOCK_PAUSED 0
#define CLOCK_RUNNING 1
#define CLOCK_SET 2
#define CLOCK_TERMINATE 3

class countdownClock {
    sf::Clock clock;
    sf::Int32 time[2];
    int clock_state;
    int current_player;
    
    
    
public:
    int toggleClock();   //both return 1 if able to start/stop
    int stopClock();
    void startClock();
    
    void setTime(sf::Int32 time, int player); //sets the time (in ms) and resets the clock, player has to be 0 or 1
    sf::Int32 getTime(int player); //returns the time (in ms), player has to be 0 or 1
    
    countdownClock();
    
};

#endif /* defined(__Chess_Clock__countdown_clock__) */
