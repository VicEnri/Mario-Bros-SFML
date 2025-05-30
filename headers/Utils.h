#pragma once

#include<SFML/Graphics.hpp>
#include<string>

extern int coinCounter;

struct State{
    std::unique_ptr<sf::Font> font;
    std::unique_ptr<sf::Text> coinText;

    void init(){
        font = std::make_unique<sf::Font>();
        if(!font->openFromFile("../assets/fonts/ARIAL.TTF"))
            throw std::runtime_error("Impossibile caricare il font");
        
        coinText = std::make_unique<sf::Text>(*font, "Monete: 0", 20);
        coinText->setFillColor(sf::Color::White);
        coinText->setOutlineColor(sf::Color::Black);
        coinText->setOutlineThickness(2.f);
    }

    void update(float) {}

    void draw(sf::RenderWindow& window){
        coinText->setString("Monete: " + std::to_string(coinCounter));
        const auto& view = window.getView();
        coinText->setPosition(sf::Vector2f(
            view.getCenter().x - view.getSize().x / 2.f + 20.f,
            view.getCenter().y - view.getSize().y / 2.f + 20.f
        ));
        window.draw(*coinText);
    }
};
void handle_close(sf::RenderWindow& window) { window.close(); }

template<typename Event, typename StateT>
void handle(const Event&, StateT&) {}