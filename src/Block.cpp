#include <iostream>

#include "../headers/Block.h"
#include "../headers/Global.h"

Block::Block() : Object(ObjectType::BLOCK) {}

void Block::init() {
    if(!texture.loadFromFile("../assets/images/Landscape/Block.png"))
        std::cerr << "Errore: impossibile caricare Block.png\n";
    
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