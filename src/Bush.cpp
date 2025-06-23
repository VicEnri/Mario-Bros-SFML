#include <iostream>

#include "../headers/Bush.h"
#include "../headers/Global.h"
#include "../headers/TextureManager.h"

Bush::Bush() : Object(ObjectType::BUSH) {}

void Bush::init() {
    
    texture = TextureManager::getTexture("../assets/images/Landscape/Bush.png");
    
    sprite = std::make_unique<sf::Sprite>(texture);
    sprite->setTexture(texture);

    sprite->setScale(sf::Vector2f(
        2.f * (float)CELL_SIZE / texture.getSize().x,
        (float)CELL_SIZE / texture.getSize().y
    ));
}

void Bush::draw(Renderer& renderer){
    if(sprite)
        renderer.draw(*sprite);
}