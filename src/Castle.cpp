#include <iostream>

#include "../headers/Castle.h"
#include "../headers/Global.h"
#include "../headers/TextureManager.h"

Castle::Castle() : Object(ObjectType::CASTLE) {}

void Castle::init() {
    
    texture = TextureManager::getTexture("../assets/images/Landscape/Castle.png");
    
    sprite = std::make_unique<sf::Sprite>(texture);
    sprite->setTexture(texture);

    sprite->setScale(sf::Vector2f(
        10.0f * (float)CELL_SIZE / texture.getSize().x,
        12.f * (float)CELL_SIZE / texture.getSize().y
    ));
}

void Castle::setPosition(float x, float y){
    rect.position = {x, y};
    sprite->setPosition({x, y});
}

void Castle::draw(Renderer& renderer){
    if(sprite)
        renderer.draw(*sprite);
}