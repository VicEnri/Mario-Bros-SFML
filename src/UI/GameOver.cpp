#include"../../headers/UI/GameOver.h"
#include"../../headers/UI/UIutils.h"

void GameOverScreen::init(const std::unique_ptr<sf::Font>& f, const std::unique_ptr<sf::Font>& tf, const sf::Sprite& coin){
    font = &f;
    titleFont = &tf;
    coinSprite = std::make_unique<sf::Sprite>(coin);

    retryText = std::make_unique<sf::Text>(makeStyledText("RIPROVA", **font, 40, sf::Color::White, sf::Color::Black, 3.f));
    retryButton = std::make_unique<sf::RectangleShape>(sf::Vector2f(200.f, 60.f));
    retryButton->setFillColor(sf::Color(228, 0, 15));
    retryButton->setOutlineColor(sf::Color::Black);
    retryButton->setOutlineThickness(4.f);

    menuText = std::make_unique<sf::Text>(makeStyledText("MENU PRINCIPALE", **font, 32, sf::Color::White, sf::Color::Black, 3.f));
    menuButton = std::make_unique<sf::RectangleShape>(sf::Vector2f(340.f, 55.f));
    menuButton->setFillColor(sf::Color(228, 0, 15));
    menuButton->setOutlineColor(sf::Color::Black);
    menuButton->setOutlineThickness(4.f);
}

void GameOverScreen::draw(Renderer& renderer, const sf::View& view, int coinCounter, const sf::Vector2f& mousePos){

    renderer.drawBlackOverlay(view);

    sf::Text gameOverText = makeStyledText("GAME OVER", **font, 100, sf::Color::Red, sf::Color::Black, 5.f);
    auto bounds = gameOverText.getLocalBounds();
    float centerX = view.getCenter().x - (bounds.position.x + bounds.size.x / 2.f);
    float centerY = view.getCenter().y - 100.f - (bounds.position.y + bounds.size.y / 2.f);
    gameOverText.setPosition(sf::Vector2f(centerX, centerY));
    renderer.draw(gameOverText);

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

    sf::Vector2f retryPos(view.getCenter().x - 90.f, view.getCenter().y + 20.f);
    retryButton->setPosition(retryPos);
    renderer.draw(*retryButton);

    sf::Vector2f menuPos(view.getCenter().x - 170.f, view.getCenter().y + 100.f);
    menuButton->setPosition(menuPos);
    renderer.draw(*menuButton);

    retryText->setFillColor(retryButton->getGlobalBounds().contains(mousePos) ? sf::Color::Yellow : sf::Color::White);
    menuText->setFillColor(menuButton->getGlobalBounds().contains(mousePos) ? sf::Color::Yellow : sf::Color::White);

    renderer.centerTextInButton(*retryText, *retryButton, retryPos);
    renderer.draw(*retryText);

    renderer.centerTextInButton(*menuText, *menuButton, menuPos);
    renderer.draw(*menuText);
}

bool GameOverScreen::isRetryClicked(const sf::Vector2f& mousePos) const{
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
           retryButton->getGlobalBounds().contains(mousePos);
}

bool GameOverScreen::isMenuClicked(const sf::Vector2f& mousePos) const{
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
           menuButton->getGlobalBounds().contains(mousePos);
}
