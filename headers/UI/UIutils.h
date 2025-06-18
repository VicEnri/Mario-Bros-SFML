#pragma once

#include<SFML/Graphics.hpp>

sf::Text makeStyledText(const std::string& str, const sf::Font& font, unsigned int size, sf::Color fill, sf::Color outline, float thickness);
void centerTextInButton(sf::Text& text, const sf::RectangleShape& button, const sf::Vector2f& buttonPos);
void drawBlackOverlay(sf::RenderWindow& window, const sf::View& view);