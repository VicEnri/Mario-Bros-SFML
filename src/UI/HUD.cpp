#include"../../headers/UI/HUD.h"
#include"../../headers/UI/UIutils.h"
#include"../../headers/TextureManager.h"

void HUD::init(const sf::Font& font){
    coinText = std::make_unique<sf::Text>(makeStyledText("Monete x 0", font, 20, sf::Color::White, sf::Color::Black, 2.f));

    coinSprite = std::make_unique<sf::Sprite>(TextureManager::getTexture("../assets/images/Coin/Coin2.png"));
    coinSprite->setScale(sf::Vector2f(2.5f, 2.5f));
}

void HUD::draw(sf::RenderWindow& window, const sf::View& view, int coinCounter){
    coinText->setString("Monete x " + std::to_string(coinCounter));
    coinText->setPosition(sf::Vector2f(
        view.getCenter().x - view.getSize().x / 2.f + 20.f,
        view.getCenter().y - view.getSize().y / 2.f + 20.f
    ));
    window.draw(*coinText);
}