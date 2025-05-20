#pragma once
#include <SFML/Graphics.hpp>


struct State{
    void update(float deltaTime) {};
    void draw(sf::RenderWindow& window) {}
};


void handle_close(sf::RenderWindow& window) { window.close(); };


template<typename Event, typename StateT>
void handle(const Event&, StateT&) {}