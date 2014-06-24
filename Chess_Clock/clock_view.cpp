//
//  clock_view.cpp
//  Chess_Clock
//
//  Created by Ben de Haan on 6/21/14.
//  Copyright (c) 2014 Rainero. All rights reserved.
//

#include "clock_view.h"

/*void startClockFunc(chessClock clock) {
    clock.startClock();
}*/

void clockView::draw() {
    int* p0_time = this->clock.getTimePlayer(0);
    int* p1_time = this->clock.getTimePlayer(1);
    if (p0_time[0] == -1) {
        this->p0_time = "LOSE";
    }
    else if (p1_time[0] == -1) {
        this->p1_time = "LOSE";
    }
    else {
        this->p0_time = std::to_string(this->clock.getTimePlayer(0)[0]) + "::" +
                    std::to_string(this->clock.getTimePlayer(0)[1]) + ":" +
                    std::to_string(this->clock.getTimePlayer(0)[2]);
    
        this->p1_time = std::to_string(this->clock.getTimePlayer(1)[0]) + "::" +
                    std::to_string(this->clock.getTimePlayer(1)[1]) + ":" +
                    std::to_string(this->clock.getTimePlayer(1)[2]);
    }
    this->text_p0->setString(this->p0_time);
    this->text_p1->setString(this->p1_time);
    
    window->draw(*this->text_p1);
    window->draw(*this->text_p0);
    
    
}


void clockView::poll() {
    sf::Event event;
    while (this->window->pollEvent(event)) {
        //poll events
    }
}





void clockView::launch() {
    //sf::Thread clock_thread(&startClockFunc, this->clock);
    
    while (this->window->isOpen()) {
        
        this->poll();
        window->clear();
        this->draw();
        window->display();
    }
}


int clockView::init() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Chess Clock");
    this->clock = chessClock();
    
    if (!this->icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    this->window->setIcon(this->icon.getSize().x, this->icon.getSize().y,
                          this->icon.getPixelsPtr());
    
    if (!this->game_font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    
    sf::Text text_p0("foo", this->game_font, 50);
    sf::Text text_p1("foo", this->game_font, 50);
    
    this->text_p0 = new sf::Text("foo", this->game_font, 50);
    this->text_p1 = new sf::Text("foo", this->game_font, 50);
    this->text_p0->setColor(sf::Color::Red);
    this->text_p1->setColor(sf::Color::Black);
    
    return 1;

    
}

clockView::clockView() {
    std::cout<<"constructor\n";
    this->init();
    
    
}