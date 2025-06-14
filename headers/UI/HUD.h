#pragma once

#include<SFML/Graphics.hpp>
#include<memory>

class HUD{
    public:
        void init(const sf::Font& font);
        void draw(sf::RenderWindow& window, const sf::View& view, int coinCounter);

    private:
        std::unique_ptr<sf::Text> coinText;
        std::unique_ptr<sf::Sprite> coinSprite;
};
