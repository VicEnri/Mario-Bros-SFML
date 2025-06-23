#include "../../headers/UI/UIutils.h"

sf::Text makeStyledText(const std::string& str, const sf::Font& font, unsigned int size, sf::Color fill, sf::Color outline, float thickness){
    sf::Text text(font, str, size);
    text.setFillColor(fill);
    text.setOutlineColor(outline);
    text.setOutlineThickness(thickness);
    return text;
}
