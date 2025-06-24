#include <iostream>

#include "../headers/FloorBlock.h"
#include "../headers/Global.h"
#include "../headers/TextureManager.h"

FloorBlock::FloorBlock() : Object(ObjectType::FLOOR) {
    rect = sf::FloatRect(sf::Vector2f{0, 0}, sf::Vector2f{CELL_SIZE, CELL_SIZE});
}

void FloorBlock::init() {
    
    texture = TextureManager::getTexture("../assets/images/Landscape/FloorBlock.png");
    
    sprite = std::make_unique<sf::Sprite>(texture);
    sprite->setTexture(texture);

    sprite->setScale(sf::Vector2f(
        (float)CELL_SIZE / texture.getSize().x,
        (float)CELL_SIZE / texture.getSize().y
    ));
}

void FloorBlock::setPosition(float x, float y){
    rect.position = {x, y};
    sprite->setPosition({x, y});
}

void FloorBlock::draw(Renderer& renderer){
    if(sprite)
        renderer.draw(*sprite);
}