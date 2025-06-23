#pragma once

#include<SFML/Graphics.hpp>

sf::Text makeStyledText(const std::string& str, const sf::Font& font, unsigned int size, sf::Color fill, sf::Color outline, float thickness);
