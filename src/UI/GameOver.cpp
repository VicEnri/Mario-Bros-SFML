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

void GameOverScreen::draw(sf::RenderWindow& window, const sf::View& view, int coinCounter){

    drawBlackOverlay(window, view);

    sf::Text gameOverText = makeStyledText("GAME OVER", **font, 100, sf::Color::Red, sf::Color::Black, 5.f);
    auto bounds = gameOverText.getLocalBounds();
    float centerX = view.getCenter().x - (bounds.position.x + bounds.size.x / 2.f);
    float centerY = view.getCenter().y - 100.f - (bounds.position.y + bounds.size.y / 2.f);
    gameOverText.setPosition(sf::Vector2f(centerX, centerY));
    window.draw(gameOverText);

    float marginTop = 30.f;
    float coinsY = view.getCenter().y - view.getSize().y / 2.f + marginTop;
    sf::Sprite coin = *coinSprite;
    sf::Text coinsText = makeStyledText("x " + std::to_string(coinCounter), **font, 35, sf::Color::Yellow, sf::Color::Black, 2.f);
    float totalWidth = coin.getGlobalBounds().size.x + 10.f + coinsText.getLocalBounds().size.x;
    float startX = view.getCenter().x - totalWidth / 2.f;
    coin.setPosition(sf::Vector2f(startX, coinsY));
    coinsText.setPosition(sf::Vector2f(startX + coin.getGlobalBounds().size.x + 10.f, coinsY - 5.f));
    window.draw(coin);
    window.draw(coinsText);

    float mY = (coinsY + view.getCenter().y - 100.f) / 2.f + 20.f;
    sf::Text mText = makeStyledText("m", **titleFont, 100, sf::Color::Black, sf::Color::White, 4.f);
    auto mBounds = mText.getLocalBounds();
    mText.setOrigin(sf::Vector2f(mBounds.size.x / 2.f, mBounds.size.y / 2.f));
    mText.setPosition(sf::Vector2f(view.getCenter().x, mY));
    window.draw(mText);

    sf::Vector2f retryPos(view.getCenter().x - 90.f, view.getCenter().y + 20.f);
    retryButton->setPosition(retryPos);
    window.draw(*retryButton);

    sf::Vector2f menuPos(view.getCenter().x - 170.f, view.getCenter().y + 100.f);
    menuButton->setPosition(menuPos);
    window.draw(*menuButton);

    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    retryText->setFillColor(retryButton->getGlobalBounds().contains(mouse) ? sf::Color::Yellow : sf::Color::White);
    menuText->setFillColor(menuButton->getGlobalBounds().contains(mouse) ? sf::Color::Yellow : sf::Color::White);

    centerTextInButton(*retryText, *retryButton, retryPos);
    window.draw(*retryText);

    centerTextInButton(*menuText, *menuButton, menuPos);
    window.draw(*menuText);
}

bool GameOverScreen::isRetryClicked(const sf::RenderWindow& window){
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) return false;
    sf::Vector2f pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    return retryButton->getGlobalBounds().contains(pos);
}

bool GameOverScreen::isMenuClicked(const sf::RenderWindow& window){
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) return false;
    sf::Vector2f pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    return menuButton->getGlobalBounds().contains(pos);
}