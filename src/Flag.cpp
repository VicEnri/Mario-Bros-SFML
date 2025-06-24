#include <iostream>

#include "../headers/Flag.h"
#include "../headers/Global.h"
#include "../headers/TextureManager.h"

Flag::Flag() : Object(ObjectType::FLAG) {}

void Flag::init() {
    
    texture = TextureManager::getTexture("../assets/images/Landscape/Flag.png");
    
    sprite = std::make_unique<sf::Sprite>(texture);
    sprite->setTexture(texture);

    sprite->setScale(sf::Vector2f(
        3.f * (float)CELL_SIZE / texture.getSize().x,
        10.f * (float)CELL_SIZE / texture.getSize().y
    ));
}

void Flag::draw(Renderer& renderer){
    if(sprite)
        renderer.draw(*sprite);
}