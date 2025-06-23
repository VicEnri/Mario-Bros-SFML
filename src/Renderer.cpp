#include "../headers/Renderer.h"

Renderer::Renderer(sf::RenderWindow &window) : window(window){}

void Renderer::draw(const sf::Drawable& drawable){
    window.draw(drawable);
}

void Renderer::drawBlackOverlay(const sf::View& view){
    sf::RectangleShape overlay(view.getSize());
    overlay.setFillColor(sf::Color(0, 0, 0, 150)); //semi-trasparente
    overlay.setPosition(view.getCenter() - view.getSize() / 2.f);
    window.draw(overlay);
}

void Renderer::centerTextInButton(sf::Text& text, const sf::RectangleShape& button, const sf::Vector2f& buttonPos){
    auto textRect = text.getLocalBounds();
     text.setPosition(sf::Vector2f(
        buttonPos.x + (button.getSize().x - textRect.size.x) / 2.f - textRect.position.x,
        buttonPos.y + (button.getSize().y - textRect.size.y) / 2.f - textRect.position.y
    ));
}