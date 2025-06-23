#include <iostream>

#include "../headers/Hill.h"
#include "../headers/Global.h"
#include "../headers/TextureManager.h"

Hill::Hill() : Object(ObjectType::HILL) {}

void Hill::init() {
    
    texture = TextureManager::getTexture("../assets/images/Landscape/Hill.png");
    
    sprite = std::make_unique<sf::Sprite>(texture);
    sprite->setTexture(texture);

    sprite->setScale(sf::Vector2f(
        12.f * (float)CELL_SIZE / texture.getSize().x,
        6.f  * (float)CELL_SIZE / texture.getSize().y
    ));
}

void Hill::draw(Renderer& renderer){
    if(sprite)
        renderer.draw(*sprite);
}