#pragma once

#include<SFML/Graphics.hpp>
#include<memory>

#include"../Renderer.h"

class StartScreen{
    public:
        void init(const sf::Font& font, const sf::Font& titleFont);
        void draw(Renderer& renderer, const sf::View& view, const sf::Vector2f& mousePos);
        bool isClicked(const sf::Vector2f& mousePos) const;

    private:
        std::unique_ptr<sf::Text> text;
        std::unique_ptr<sf::RectangleShape> button;
        const sf::Font* titleFont;
};