#include "../../headers/UI/FinalVictoryScreen.h"
#include "../../headers/UI/UIutils.h"

void FinalVictoryScreen::init(const std::unique_ptr<sf::Font>& f, const std::unique_ptr<sf::Font>& tf) {
    font = &f;
    titleFont = &tf;
    menuText = std::make_unique<sf::Text>(makeStyledText("MENU PRINCIPALE", **font, 32, sf::Color::White, sf::Color::Black, 3.f));
    menuButton = std::make_unique<sf::RectangleShape>(sf::Vector2f(340.f, 55.f));
    menuButton->setFillColor(sf::Color(228, 0, 15));
    menuButton->setOutlineColor(sf::Color::Black);
    menuButton->setOutlineThickness(4.f);
}

void FinalVictoryScreen::draw(Renderer& renderer, const sf::View& view, const sf::Vector2f& mousePos) {
    renderer.drawBlackOverlay(view);

    sf::Text victoryText = makeStyledText("GIOCO COMPLETATO!", **font, 80, sf::Color::Red, sf::Color::Black, 5.f);
    auto bounds = victoryText.getLocalBounds();
    float centerX = view.getCenter().x - (bounds.position.x + bounds.size.x / 2.f);
    float centerY = view.getCenter().y - 100.f - (bounds.position.y + bounds.size.y / 2.f);
    victoryText.setPosition(sf::Vector2f(centerX, centerY));
    renderer.draw(victoryText);

    sf::Vector2f menuPos(view.getCenter().x - 170.f, view.getCenter().y + 100.f);
    menuButton->setPosition(menuPos);
    renderer.draw(*menuButton);

    menuText->setFillColor(menuButton->getGlobalBounds().contains(mousePos) ? sf::Color::Yellow : sf::Color::White);
    renderer.centerTextInButton(*menuText, *menuButton, menuPos);
    renderer.draw(*menuText);
}

bool FinalVictoryScreen::isMenuClicked(const sf::Vector2f& mousePos) const {
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
           menuButton->getGlobalBounds().contains(mousePos);
}