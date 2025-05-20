#pragma once

#include<SFML/Graphics.hpp>

class Renderer{
    public:
        Renderer(sf::RenderWindow &window);

        void draw(const sf::Sprite &sprite);

    private:
        sf::RenderWindow &window;
};