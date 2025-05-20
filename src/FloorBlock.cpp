#include <iostream>

#include "../headers/FloorBlock.h"
#include "../headers/Global.h"

FloorBlock::FloorBlock() : Object(ObjectType::FLOOR) {}

void FloorBlock::init() {
    if(!texture.loadFromFile("../assets/images/FloorBlock.png"))
        std::cerr << "Errore: impossibile caricare FloorBlock.png\n";
    
    sprite = std::make_unique<sf::Sprite>(texture);
    sprite->setTexture(texture);

    sprite->setScale(sf::Vector2f(
        (float)CELL_SIZE / texture.getSize().x,
        (float)CELL_SIZE / texture.getSize().y
    ));
}

void FloorBlock::draw(Renderer& renderer){
    if(sprite)
        renderer.draw(*sprite);
}