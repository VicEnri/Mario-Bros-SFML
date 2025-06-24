#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Renderer.h"

class FinalVictoryScreen {
public:
    void init(const std::unique_ptr<sf::Font>& font, const std::unique_ptr<sf::Font>& titleFont);
    void draw(Renderer& renderer, const sf::View& view, const sf::Vector2f& mousePos);

    bool isMenuClicked(const sf::Vector2f& mousePos) const;

    

private:
    const std::unique_ptr<sf::Font>* font;
    const std::unique_ptr<sf::Font>* titleFont;
    std::unique_ptr<sf::Text> menuText;
    std::unique_ptr<sf::RectangleShape> menuButton;
};