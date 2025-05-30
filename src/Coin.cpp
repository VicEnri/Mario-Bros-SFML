#include <iostream>

#include "../headers/Coin.h"
#include "../headers/Global.h"
#include "../headers/TextureManager.h"

Coin::Coin() : Object(ObjectType::COIN), runAnimation(2.0f) {}

void Coin::init(){
    
    textures[0] = TextureManager::getTexture("../assets/images/Coin/Coin1.png");
    textures[1] = TextureManager::getTexture("../assets/images/Coin/Coin2.png");
    textures[2] = TextureManager::getTexture("../assets/images/Coin/Coin3.png");
    textures[3] = TextureManager::getTexture("../assets/images/Coin/Coin4.png");
    textures[4] = TextureManager::getTexture("../assets/images/Coin/Coin5.png");
    textures[5] = TextureManager::getTexture("../assets/images/Coin/Coin6.png");
    textures[6] = TextureManager::getTexture("../assets/images/Coin/Coin7.png");
    textures[7] = TextureManager::getTexture("../assets/images/Coin/Coin8.png");
    textures[8] = TextureManager::getTexture("../assets/images/Coin/Coin9.png");
    textures[9] = TextureManager::getTexture("../assets/images/Coin/Coin10.png");
    
    sprite = std::make_unique<sf::Sprite>(textures[0]);
    sprite->setTexture(textures[0]);

    sprite->setScale(sf::Vector2f(
        (float)CELL_SIZE / textures[0].getSize().x,
        (float)CELL_SIZE / textures[0].getSize().y
    ));

    for(int i = 0; i < 10; ++i)
        runAnimation.addFrame(Frame(&textures[i], (i + 1) * 0.20f));
}

void Coin::update(float deltaTime){
    sf::Texture* currentTexture = runAnimation.update(deltaTime);
    if(currentTexture)
        sprite->setTexture(*currentTexture);
}

void Coin::draw(Renderer& renderer){
    if(sprite)
        renderer.draw(*sprite);
}