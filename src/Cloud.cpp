#include <iostream>

#include "../headers/Cloud.h"
#include "../headers/Global.h"
#include "../headers/TextureManager.h"

Cloud::Cloud() : Object(ObjectType::CLOUD) {}

void Cloud::init() {
    
    texture = TextureManager::getTexture("../assets/images/Landscape/Cloud.png");
    
    sprite = std::make_unique<sf::Sprite>(texture);
    sprite->setTexture(texture);

    sprite->setScale(sf::Vector2f(
        (float)CELL_SIZE / texture.getSize().x,
        (float)CELL_SIZE / texture.getSize().y
    ));
}

void Cloud::draw(Renderer& renderer){
    if(sprite)
        renderer.draw(*sprite);
}