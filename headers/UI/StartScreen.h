#pragma once

#include<SFML/Graphics.hpp>
#include<memory>

class StartScreen{
    public:
        void init(const sf::Font& font, const sf::Font& titleFont);
        void draw(sf::RenderWindow& window, const sf::View& view);
        bool isClicked(const sf::RenderWindow& window);

    private:
        std::unique_ptr<sf::Text> text;
        std::unique_ptr<sf::RectangleShape> button;
        const sf::Font* titleFont;
};