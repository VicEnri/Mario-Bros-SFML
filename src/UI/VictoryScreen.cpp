#include "../../headers/UI/VictoryScreen.h"
#include "../../headers/UI/UIutils.h"

void VictoryScreen::init(const std::unique_ptr<sf::Font>& f, const std::unique_ptr<sf::Font>& tf, const sf::Sprite& coin){
    font = &f;
    titleFont = &tf;
    coinSprite = std::make_unique<sf::Sprite>(coin);

    continueText = std::make_unique<sf::Text>(makeStyledText("CONTINUA", **font, 40, sf::Color::White, sf::Color::Black, 3.f));
    continueButton = std::make_unique<sf::RectangleShape>(sf::Vector2f(200.f, 60.f));
    continueButton->setFillColor(sf::Color(0, 180, 0));
    continueButton->setOutlineColor(sf::Color::Black);
    continueButton->setOutlineThickness(4.f);

    retryText = std::make_unique<sf::Text>(makeStyledText("RIPROVA", **font, 40, sf::Color::White, sf::Color::Black, 3.f));
    retryButton = std::make_unique<sf::RectangleShape>(sf::Vector2f(200.f, 60.f));
    retryButton->setFillColor(sf::Color(0, 180, 0));
    retryButton->setOutlineColor(sf::Color::Black);
    retryButton->setOutlineThickness(4.f);

    menuText = std::make_unique<sf::Text>(makeStyledText("MENU PRINCIPALE", **font, 32, sf::Color::White, sf::Color::Black, 3.f));
    menuButton = std::make_unique<sf::RectangleShape>(sf::Vector2f(340.f, 55.f));
    menuButton->setFillColor(sf::Color(0, 180, 0));
    menuButton->setOutlineColor(sf::Color::Black);
    menuButton->setOutlineThickness(4.f);
}

void VictoryScreen::draw(Renderer& renderer, const sf::View& view, int coinCounter, const sf::Vector2f& mousePos){
    renderer.drawBlackOverlay(view);

    // Titolo rosso come Game Over
    sf::Text victoryText = makeStyledText("VICTORY", **font, 100, sf::Color::Red, sf::Color::Black, 5.f);
    auto bounds = victoryText.getLocalBounds();
    float centerX = view.getCenter().x - (bounds.position.x + bounds.size.x / 2.f);
    float centerY = view.getCenter().y - 100.f - (bounds.position.y + bounds.size.y / 2.f);
    victoryText.setPosition(sf::Vector2f(centerX, centerY));
    renderer.draw(victoryText);

    // Monete (stesso layout e colori)
    float marginTop = 30.f;
    float coinsY = view.getCenter().y - view.getSize().y / 2.f + marginTop;
    sf::Sprite coin = *coinSprite;
    sf::Text coinsText = makeStyledText("x " + std::to_string(coinCounter), **font, 35, sf::Color::Yellow, sf::Color::Black, 2.f);
    float totalWidth = coin.getGlobalBounds().size.x + 10.f + coinsText.getLocalBounds().size.x;
    float startX = view.getCenter().x - totalWidth / 2.f;
    coin.setPosition(sf::Vector2f(startX, coinsY));
    coinsText.setPosition(sf::Vector2f(startX + coin.getGlobalBounds().size.x + 10.f, coinsY - 5.f));
    renderer.draw(coin);
    renderer.draw(coinsText);

    float mY = (coinsY + view.getCenter().y - 100.f) / 2.f + 20.f;
    sf::Text mText = makeStyledText("m", **titleFont, 100, sf::Color::Black, sf::Color::White, 4.f);
    auto mBounds = mText.getLocalBounds();
    mText.setOrigin(sf::Vector2f(mBounds.size.x / 2.f, mBounds.size.y / 2.f));
    mText.setPosition(sf::Vector2f(view.getCenter().x, mY));
    renderer.draw(mText);

    // Pulsanti (stessi colori e dimensioni di Game Over)
    sf::Vector2f continuePos(view.getCenter().x - 90.f, view.getCenter().y + 60.f);
    continueButton->setPosition(continuePos);
    continueButton->setFillColor(sf::Color(228, 0, 15));
    continueButton->setOutlineColor(sf::Color::Black);
    continueButton->setOutlineThickness(4.f);
    renderer.draw(*continueButton);

    sf::Vector2f retryPos(view.getCenter().x - 90.f, view.getCenter().y + 140.f);
    retryButton->setPosition(retryPos);
    retryButton->setFillColor(sf::Color(228, 0, 15));
    retryButton->setOutlineColor(sf::Color::Black);
    retryButton->setOutlineThickness(4.f);
    renderer.draw(*retryButton);

    sf::Vector2f menuPos(view.getCenter().x - 170.f, view.getCenter().y + 220.f);
    menuButton->setPosition(menuPos);
    menuButton->setFillColor(sf::Color(228, 0, 15));
    menuButton->setOutlineColor(sf::Color::Black);
    menuButton->setOutlineThickness(4.f);
    renderer.draw(*menuButton);

    // Colori testo come Game Over
    continueText->setFillColor(continueButton->getGlobalBounds().contains(mousePos) ? sf::Color::Yellow : sf::Color::White);
    retryText->setFillColor(retryButton->getGlobalBounds().contains(mousePos) ? sf::Color::Yellow : sf::Color::White);
    menuText->setFillColor(menuButton->getGlobalBounds().contains(mousePos) ? sf::Color::Yellow : sf::Color::White);

    renderer.centerTextInButton(*continueText, *continueButton, continuePos);
    renderer.draw(*continueText);

    renderer.centerTextInButton(*retryText, *retryButton, retryPos);
    renderer.draw(*retryText);

    renderer.centerTextInButton(*menuText, *menuButton, menuPos);
    renderer.draw(*menuText);
}

bool VictoryScreen::isRetryClicked(const sf::Vector2f& mousePos) const{
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && 
        retryButton->getGlobalBounds().contains(mousePos);
}

bool VictoryScreen::isMenuClicked(const sf::Vector2f& mousePos) const{
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && 
        menuButton->getGlobalBounds().contains(mousePos);
}

bool VictoryScreen::isContinueClicked(const sf::Vector2f& mousePos) const{
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
           continueButton->getGlobalBounds().contains(mousePos);
}

