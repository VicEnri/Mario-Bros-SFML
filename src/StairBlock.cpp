#include <iostream>

#include "../headers/StairBlock.h"
#include "../headers/Global.h"

StairBlock::StairBlock() : Object(ObjectType::STAIR) {}

void StairBlock::init() {
    if(!texture.loadFromFile("../assets/images/Landscape/StairBlock.png"))
        std::cerr << "Errore: impossibile caricare StairBlock.png\n";
    
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