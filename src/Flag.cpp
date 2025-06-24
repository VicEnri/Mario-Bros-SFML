#include <iostream>

#include "../headers/Flag.h"
#include "../headers/Global.h"
#include "../headers/TextureManager.h"

Flag::Flag() : Object(ObjectType::FLAG) {}

void Flag::init() {
    
    texture = TextureManager::getTexture("../assets/images/Landscape/Flag.png");
    
    sprite = std::make_unique<sf::Sprite>(texture);
    sprite->setTexture(texture);

   sf::Vector2f size(
        3.f * (float)CELL_SIZE,    //larghezza in pixel di gioco
        10.f * (float)CELL_SIZE    //altezza in pixel di gioco
    );

    sprite->setScale(sf::Vector2f(
        (float)size.x / texture.getSize().x,
        (float)size.y / texture.getSize().y
    ));

    rect = sf::FloatRect(sf::Vector2f{0, 0},sf::Vector2f{ size.x, size.y});
}

void Flag::setPosition(float x, float y){
    rect.position = {x, y};
    sprite->setPosition({x, y});
}

void Flag::draw(Renderer& renderer){
    if(sprite)
        renderer.draw(*sprite);
}