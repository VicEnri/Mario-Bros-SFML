#include <iostream>

#include "../headers/Block.h"
#include "../headers/Global.h"
#include "../headers/TextureManager.h"

Block::Block() : Object(ObjectType::BLOCK) {}

void Block::init(){

    texture = TextureManager::getTexture("../assets/images/Landscape/Block.png");
    
    sprite = std::make_unique<sf::Sprite>(texture);
    sprite->setTexture(texture);

    sprite->setScale(sf::Vector2f(
        (float)CELL_SIZE / texture.getSize().x,
        (float)CELL_SIZE / texture.getSize().y
    ));
}

void Block::draw(Renderer& renderer){
    if(sprite)
        renderer.draw(*sprite);
}