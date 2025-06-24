#pragma once

#include<SFML/Graphics.hpp>
#include<memory>

#include"../Renderer.h"

class VictoryScreen{
    public:
        void init(const std::unique_ptr<sf::Font>& font, const std::unique_ptr<sf::Font>& titleFont, const sf::Sprite& coin);
        void draw(Renderer& renderer, const sf::View& view, int coinCounter, const sf::Vector2f& mousePos);

        bool isRetryClicked(const sf::Vector2f& mousePos) const;
        bool isMenuClicked(const sf::Vector2f& mousePos) const;
        bool isContinueClicked(const sf::Vector2f& mousePos) const;

    private:
        const std::unique_ptr<sf::Font>* font;
        const std::unique_ptr<sf::Font>* titleFont;

        std::unique_ptr<sf::Text> retryText, menuText, continueText;
        std::unique_ptr<sf::RectangleShape> retryButton, menuButton, continueButton;
        std::unique_ptr<sf::Sprite> coinSprite;
    };
