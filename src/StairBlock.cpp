#include <iostream>

#include "../headers/StairBlock.h"
#include "../headers/Global.h"
#include "../headers/TextureManager.h"

StairBlock::StairBlock() : Object(ObjectType::STAIR) {}

void StairBlock::init() {
    
    texture = TextureManager::getTexture("../assets/images/Landscape/StairBlock.png");
    
    sprite = std::make_unique<sf::Sprite>(texture);
    sprite->setTexture(texture);

    sprite->setScale(sf::Vector2f(
        (float)CELL_SIZE / texture.getSize().x,
        (float)CELL_SIZE / texture.getSize().y
    ));
}

void StairBlock::draw(Renderer& renderer){
    if(sprite)
        renderer.draw(*sprite);
}