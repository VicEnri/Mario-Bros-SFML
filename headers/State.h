#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

extern int coinCounter;

struct State{
    std::unique_ptr<sf::Font> font;
    std::unique_ptr<sf::Text> coinText;

    void init();
    void update(float) {};
    void draw(sf::RenderWindow& window);
};
inline void handle_close(sf::RenderWindow& window) { window.close(); }

template<typename Event, typename StateT>
void handle(const Event&, StateT&) {}