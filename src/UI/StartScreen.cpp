#include"../../headers/UI/StartScreen.h"
#include"../../headers/UI/UIutils.h"

void StartScreen::init(const sf::Font& font, const sf::Font& titleFont){
    text = std::make_unique<sf::Text>(makeStyledText("INIZIA", font, 40, sf::Color::White, sf::Color::Black, 3.f));

    button = std::make_unique<sf::RectangleShape>(sf::Vector2f(300.f, 60.f));
    button->setFillColor(sf::Color(0,70,200));
    button->setOutlineColor(sf::Color::Black);
    button->setOutlineThickness(4.f);

    this->titleFont = &titleFont;
}

void StartScreen::draw(Renderer& renderer, const sf::View& view, const sf::Vector2f& mousePos){

    sf::Text imageText = makeStyledText("\"", *titleFont, 300, sf::Color::White, sf::Color::Black, 4.f);
    auto imageBounds = imageText.getLocalBounds();
    imageText.setOrigin(sf::Vector2f(imageBounds.size.x / 2.f, imageBounds.size.y / 2.f));
    imageText.setPosition(sf::Vector2f(view.getCenter().x, view.getCenter().y - 120.f));
    renderer.draw(imageText);

    sf::Vector2f pos(view.getCenter().x - 150.f, view.getCenter().y + 20.f);
    button->setPosition(pos);
    renderer.draw(*button);

    text->setFillColor(button->getGlobalBounds().contains(mousePos) ? sf::Color::Yellow : sf::Color::White);
    renderer.centerTextInButton(*text, *button, pos);
    renderer.draw(*text);
}

bool StartScreen::isClicked(const sf::Vector2f& mousePos) const{
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
           button->getGlobalBounds().contains(mousePos);
}
