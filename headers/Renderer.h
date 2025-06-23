#pragma once

#include<SFML/Graphics.hpp>

class Renderer{
    public:
        Renderer(sf::RenderWindow &window);

        void draw(const sf::Drawable& drawable);

        void drawBlackOverlay(const sf::View& view);
        void centerTextInButton(sf::Text& text, const sf::RectangleShape& button, const sf::Vector2f& buttonPos);


        sf::RenderWindow& getWindow() {return window;}

    private:
        sf::RenderWindow &window;
};