#pragma once

#include<SFML/Graphics.hpp>
#include<memory>

class GameOverScreen{
    public:
        void init(const std::unique_ptr<sf::Font>& f, const std::unique_ptr<sf::Font>& tf, const sf::Sprite& coin);
        void draw(sf::RenderWindow& window, const sf::View& view, int coinCounter);
        bool isRetryClicked(const sf::RenderWindow& window);
        bool isMenuClicked(const sf::RenderWindow& window);

    private:
        const std::unique_ptr<sf::Font>* font;
        const std::unique_ptr<sf::Font>* titleFont;
        std::unique_ptr<sf::Sprite> coinSprite;
        std::unique_ptr<sf::Text> retryText, menuText;
        std::unique_ptr<sf::RectangleShape> retryButton, menuButton;
};