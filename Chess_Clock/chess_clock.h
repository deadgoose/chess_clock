//
//  chess_clock.h
//  Chess_Clock
//
//  Created by Ben de Haan on 6/16/14.
//  Copyright (c) 2014 Rainero. All rights reserved.
//

#ifndef __Chess_Clock__chess_clock__
#define __Chess_Clock__chess_clock__

#include <iostream>
#include <countdown_clock.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class chessClock {
    countdownClock clock;
    
    int time_player[3];

    
    int player_lose(); // returns 1 if player 1 loses, 2 if player 2 loses
public:
    int startClock();   // returns 1 if clock was paused
    void setTimePlayer(int* time, int player);
    int stopClock();    // returns 1 if clock was running
    
    
    int* getTimePlayer(int player);//returns time as an array - minutes - seconds - milliseconds
    
    
    
};

#endif /* defined(__Chess_Clock__chess_clock__) */
