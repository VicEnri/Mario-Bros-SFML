#include "../../headers/UI/UIutils.h"

sf::Text makeStyledText(const std::string& str, const sf::Font& font, unsigned int size, sf::Color fill, sf::Color outline, float thickness){
    sf::Text text(font, str, size);
    text.setFillColor(fill);
    text.setOutlineColor(outline);
    text.setOutlineThickness(thickness);
    return text;
}

void centerTextInButton(sf::Text& text, const sf::RectangleShape& button, const sf::Vector2f& buttonPos) {
    auto textRect = text.getLocalBounds();
    text.setPosition(sf::Vector2f(
        buttonPos.x + (button.getSize().x - textRect.size.x) / 2.f - textRect.position.x,
        buttonPos.y + (button.getSize().y - textRect.size.y) / 2.f - textRect.position.y
    ));
}

void drawBlackOverlay(sf::RenderWindow& window, const sf::View& view) {
    sf::RectangleShape overlay(view.getSize());
    overlay.setFillColor(sf::Color::Black);
    overlay.setPosition(view.getCenter() - view.getSize() / 2.f);
    window.draw(overlay);
}