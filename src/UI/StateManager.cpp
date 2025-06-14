#include "../../headers/UI/StateManager.h"
#include "../../headers/UI/UIutils.h"

void State::init(){

    font = std::make_unique<sf::Font>();
    if(!font->openFromFile("../assets/fonts/mario.ttf"))
        throw std::runtime_error("Impossibile caricare il font mario.ttf");

    titleFont = std::make_unique<sf::Font>();
    if(!titleFont->openFromFile("../assets/fonts/mario2.TTF"))
        throw std::runtime_error("Impossibile caricare il font mario2.TTF");

    coinSprite = std::make_unique<sf::Sprite>(TextureManager::getTexture("../assets/images/Coin/Coin2.png"));
    coinSprite->setScale(sf::Vector2f(2.5f, 2.5f));

    hud.init(*font);
    startScreen.init(*font, *titleFont);
    gameOverScreen.init(font, titleFont, *coinSprite);
}

void State::draw(sf::RenderWindow& window, const sf::View& view, int coinCounter){
    if(showStartScreen)
        startScreen.draw(window, view);
    else if(gameOver)
        gameOverScreen.draw(window, view, coinCounter);
    else
        hud.draw(window, view, coinCounter);
}

void State::checkGameOver(const sf::View& view, const Mario& mario){
    float bottom = view.getCenter().y + view.getSize().y / 2.f;
    if(mario.getPosition().y > bottom)
        gameOver = true;
    
}

bool State::isStartClicked(const sf::RenderWindow& window){
    return showStartScreen && startScreen.isClicked(window);
}

bool State::isRetryClicked(const sf::RenderWindow& window){
    return gameOver && gameOverScreen.isRetryClicked(window);
}

bool State::isMenuClicked(const sf::RenderWindow& window){
    return gameOver && gameOverScreen.isMenuClicked(window);
}

void State::resetGame(Map& map, int& coinCounter, Mario& mario, const char* mapFile){
    gameOver = false;
    coinCounter = 0;
    map.createMapFromFile(mapFile);
    mario.resetVerticalSpeed();
}