#include "../../headers/UI/StateManager.h"
#include "../../headers/UI/UIutils.h"

extern Map map;

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
    victoryScreen.init(font, titleFont, *coinSprite);
}

void State::draw(Renderer& renderer, const sf::View& view, int coinCounter){
    sf::Vector2f mousePos = renderer.getWindow().mapPixelToCoords(sf::Mouse::getPosition(renderer.getWindow()));
    if(showStartScreen)
        startScreen.draw(renderer, view, mousePos);
    else if(victory)
        victoryScreen.draw(renderer, view, coinCounter, mousePos);
    else if(gameOver)
        gameOverScreen.draw(renderer, view, coinCounter, mousePos);
    else
        hud.draw(renderer, view, coinCounter);
}

void State::checkGameOver(const sf::View& view, const Mario& mario, std::vector<std::unique_ptr<Goomba>>& goombas){
    float bottom = view.getCenter().y + view.getSize().y / 2.f;

    if(mario.getPosition().y > bottom){
        gameOver = true;
        victory = false;
    }
    sf::FloatRect flagRect = map.getFlagRect();
        if (mario.getRect().findIntersection(flagRect) && !gameOver && !victory) {
            victory = true;
            gameOver = false;
        }

    for(auto& goomba : goombas){
        if (mario.getRect().findIntersection(goomba->getRect()) && !gameOver && !victory){
            gameOver = true;
            victory = false;
        }
    }

}

bool State::isStartClicked(const sf::Vector2f& mousePos) const{
    return showStartScreen && startScreen.isClicked(mousePos);
}

bool State::isRetryClicked(const sf::Vector2f& mousePos) const{
    return(gameOver && gameOverScreen.isRetryClicked(mousePos)) ||
        (victory && victoryScreen.isRetryClicked(mousePos));
}

bool State::isMenuClicked(const sf::Vector2f& mousePos) const{
    return(gameOver && gameOverScreen.isMenuClicked(mousePos)) ||
        (victory && victoryScreen.isMenuClicked(mousePos));
}

bool State::isContinueClicked(const sf::Vector2f& mousePos) const{
    return victory && victoryScreen.isContinueClicked(mousePos);
}

void State::resetGame(Map& map, int& coinCounter, Mario& mario, std::vector<std::unique_ptr<Goomba>>& goombas, const char* mapFile){
    gameOver = false;
    victory = false;
    coinCounter = 0;
    goombas.clear();
    map.createMapFromFile(mapFile, goombas);
    mario.resetVerticalSpeed();
}