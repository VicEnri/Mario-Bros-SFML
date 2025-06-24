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
    finalVictoryScreen.init(font, titleFont);
}

void State::draw(Renderer& renderer, const sf::View& view, int coinCounter){
    sf::Vector2f mousePos = renderer.getWindow().mapPixelToCoords(sf::Mouse::getPosition(renderer.getWindow()));
    if(showStartScreen)
        startScreen.draw(renderer, view, mousePos);
    else if (finalVictory)
        finalVictoryScreen.draw(renderer, view, mousePos);
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
        const_cast<Mario&>(mario).setDead(true);
    }
    sf::FloatRect flagRect = map.getFlagRect();
        if(mario.getRect().findIntersection(flagRect) && !gameOver && !victory){
            victory = true;
            gameOver = false;
            const_cast<Mario&>(mario).setWin(true);
        }

    for(auto& goomba : goombas){
        if(goomba->isDead()) continue;

        //salvo rettangoli di collisione
        auto marioRect = mario.getRect();
        auto goombaRect = goomba->getRect();
        if(marioRect.findIntersection(goombaRect) && !gameOver && !victory){
            //salvo le posizioni dei rettangoli
            float marioBottom = marioRect.position.y + marioRect.size.y;
            float goombaTop = goombaRect.position.y;
            float marioPrevY = marioRect.position.y;

            if(marioBottom - goombaTop > 0 && marioRect.position.y < goombaTop && marioRect.size.y > 10){
                //Mario colpisce da sopra
                goomba->kill();
                const_cast<Mario&>(mario).setVerticalSpeed(-400.f);
            }else{
                gameOver = true;
                victory = false;
                const_cast<Mario&>(mario).setDead(true);
            }
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
        (victory && victoryScreen.isMenuClicked(mousePos)) ||
        (finalVictory && finalVictoryScreen.isMenuClicked(mousePos));
}

bool State::isContinueClicked(const sf::Vector2f& mousePos) const{
    return victory && victoryScreen.isContinueClicked(mousePos) ||
        (finalVictory && finalVictoryScreen.isMenuClicked(mousePos));
}


void State::resetGame(Map& map, int& coinCounter, Mario& mario, std::vector<std::unique_ptr<Goomba>>& goombas, const char* mapFile){
    gameOver = false;
    victory = false;
    coinCounter = 0;
    goombas.clear();
    map.createMapFromFile(mapFile, goombas);
    mario.resetVerticalSpeed();
    mario.setDead(false);
    mario.setWin(false);
}