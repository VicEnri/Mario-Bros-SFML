#include <iostream>

#include "../headers/QuestionBlock.h"
#include "../headers/Global.h"
#include "../headers/TextureManager.h"

QuestionBlock::QuestionBlock(int coins) : Object(ObjectType::QUESTION_BLOCK), runAnimation(2.0f), isHit(false), coins(coins), isVisible(true) {
    rect = sf::FloatRect(sf::Vector2f{0, 0}, sf::Vector2f{CELL_SIZE, CELL_SIZE});
}

void QuestionBlock::init(){
    textures[0] = TextureManager::getTexture("../assets/images/QuestionBlock/QuestionBlock1.png");
    textures[1] = TextureManager::getTexture("../assets/images/QuestionBlock/QuestionBlock2.png");
    textures[2] = TextureManager::getTexture("../assets/images/QuestionBlock/QuestionBlock3.png");
    textures[3] = TextureManager::getTexture("../assets/images/QuestionBlock/QuestionBlock4.png");
    textures[4] = TextureManager::getTexture("../assets/images/QuestionBlock/QuestionBlock5.png");

    sprite = std::make_unique<sf::Sprite>(textures[0]);
    sprite->setTexture(textures[0]);

    sprite->setScale(sf::Vector2f(
        (float)CELL_SIZE / textures[0].getSize().x,
        (float)CELL_SIZE / textures[0].getSize().y
    ));

    for(int i = 0; i < 4; ++i)
        runAnimation.addFrame(Frame(&textures[i], (i + 1) * 0.20f));

}

void QuestionBlock::setPosition(float x, float y){
    rect.position = {x, y};
    sprite->setPosition({x, y});
}

void QuestionBlock::update(float deltaTime){
    if(!isHit){
        sf::Texture* currentTexture = runAnimation.update(deltaTime);
        if(currentTexture)
            sprite->setTexture(*currentTexture);
    }
}

bool QuestionBlock::hit(){
    if(!isVisible){
        isVisible = true;
        sprite->setColor(sf::Color(255, 255, 255, 255)); //visibile
    }

    if(coins <= 0)
        return false;

    coins--;
    
    if(coins == 0){
        isHit = true;
        sprite->setTexture(textures[4]);
    }

    return true;
}

void QuestionBlock::setInvisible(){
    sprite->setColor(sf::Color(255, 255, 255, 0));
    isVisible = false;
}

void QuestionBlock::draw(Renderer& renderer){
    renderer.draw(*sprite);
}