#pragma once

#include<SFML/Graphics.hpp>
#include<memory>

#include"../Renderer.h"

class HUD{
    public:
        void init(const sf::Font& font);
        void draw(Renderer& renderer, const sf::View& view, int coinCounter);

    private:
        std::unique_ptr<sf::Text> coinText;
};
