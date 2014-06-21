//
//  clock_view.h
//  Chess_Clock
//
//  Created by Ben de Haan on 6/21/14.
//  Copyright (c) 2014 Rainero. All rights reserved.
//

#ifndef __Chess_Clock__clock_view__
#define __Chess_Clock__clock_view__

#include <iostream>
#include <countdown_clock.h>

class clockView {
    countdownClock clock;
public:
    void update();
    void draw();
    void setTime();
    void processInput();
    
    clockView();
    
};

#endif /* defined(__Chess_Clock__clock_view__) */
