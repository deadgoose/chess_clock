//
//  clock_view.cpp
//  Chess_Clock
//
//  Created by Ben de Haan on 6/21/14.
//  Copyright (c) 2014 Rainero. All rights reserved.
//

#include "clock_view.h"

void startClockFunc(chessClock* clock) {
    clock->beginClockLoop();
}

void clockView::draw() {
    int* p0_time = this->clock->getTimePlayer(0);
    int* p1_time = this->clock->getTimePlayer(1);
    if (p0_time[0] == -1) {
        this->p0_time = "LOSE";
    }
    else if (p1_time[0] == -1) {
        this->p1_time = "LOSE";
    }
    else {
        this->p0_time = std::to_string(this->clock->getTimePlayer(0)[0]) + "::" +
                    std::to_string(this->clock->getTimePlayer(0)[1]) + ":" +
                    std::to_string(this->clock->getTimePlayer(0)[2]);
    
        this->p1_time = std::to_string(this->clock->getTimePlayer(1)[0]) + "::" +
                    std::to_string(this->clock->getTimePlayer(1)[1]) + ":" +
                    std::to_string(this->clock->getTimePlayer(1)[2]);
    }
    this->text_p0->setString(this->p0_time);
    this->text_p1->setString(this->p1_time);
    
    window->draw(*this->text_p1);
    window->draw(*this->text_p0);
    
    
}


void clockView::poll() {
    sf::Event event;
    while (this->window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->window->close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                this->window->close();
            }
            else {
                std::cout<<"clicked key\n";
                this->clock->toggleClock();
            }
            
            
        }
        
    }

}



void clockView::launch() {
    sf::Thread clock_thread(&startClockFunc, this->clock);
    clock_thread.launch();
    
    sf::Time timePerFrame = sf::seconds(1.0f / 60.0f); // 60 frames per second
    sf::Clock deltaClock;  // This will track how much time has past since the last frame
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    
    while (this->window->isOpen()) {
        sf::Time deltaTime = deltaClock.restart();  // Restart returns the time since the last restart call
        timeSinceLastUpdate += deltaTime;
        
        while (timeSinceLastUpdate >= timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;
            
            this->poll();
            window->clear();
            this->draw();  // Notice how I pass the time per frame to the update function
        }
        

        window->display();
    }
    
    this->clock->terminate();
}


int clockView::init() {
    this->window = new sf::RenderWindow(sf::VideoMode(GAME_HEIGHT, GAME_WIDTH), "Chess Clock");
    this->clock = new chessClock();
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
    this->text_p1->setColor(sf::Color::Blue);
    this->text_p0->setPosition(GAME_WIDTH/2, GAME_HEIGHT/2);
    this->text_p1->setPosition(0, 0);
    
    return 1;

    
}

clockView::clockView() {
    std::cout<<"constructor\n";
    this->init();
    
    
}