#include "../headers/State.h"
#include <stdexcept>

void State::init(){
    font = std::make_unique<sf::Font>();
    if (!font->openFromFile("../assets/fonts/ARIAL.TTF"))
        throw std::runtime_error("Impossibile caricare il font");

    coinText = std::make_unique<sf::Text>(*font, "Monete: 0", 20);
    coinText->setFillColor(sf::Color::White);
    coinText->setOutlineColor(sf::Color::Black);
    coinText->setOutlineThickness(2.f);
}

void State::draw(sf::RenderWindow& window) {
    coinText->setString("Monete: " + std::to_string(coinCounter));
    const auto& view = window.getView();
    coinText->setPosition(sf::Vector2f(
        view.getCenter().x - view.getSize().x / 2.f + 20.f,
        view.getCenter().y - view.getSize().y / 2.f + 20.f
    ));
    window.draw(*coinText);
}
