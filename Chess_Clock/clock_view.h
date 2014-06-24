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
#include "ResourcePath.hpp"
#include <chess_clock.h>
#define GAME_WIDTH 600
#define GAME_HEIGHT 800

class clockView {
    chessClock clock;
    sf::RenderWindow* window;
    sf::Font game_font;
    sf::Image icon;
    
    int init();
    
    std::string p0_time;
    std::string p1_time;
    
    sf::Text* text_p0;
    sf::Text* text_p1;
public:
    void poll();
    void draw();
    void setTime();
    void processInput();
    void launch();
    
    clockView();
    
};

#endif /* defined(__Chess_Clock__clock_view__) */
