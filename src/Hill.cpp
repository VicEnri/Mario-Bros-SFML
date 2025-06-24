#include <iostream>

#include "../headers/Hill.h"
#include "../headers/Global.h"
#include "../headers/TextureManager.h"

Hill::Hill() : Object(ObjectType::HILL) {}

void Hill::init() {
    
    texture = TextureManager::getTexture("../assets/images/Landscape/Hill.png");
    
    sprite = std::make_unique<sf::Sprite>(texture);
    sprite->setTexture(texture);

    sf::Vector2f size(
        12.f * (float)CELL_SIZE,    //larghezza in pixel di gioco
        6.f * (float)CELL_SIZE    //altezza in pixel di gioco
    );

    sprite->setScale(sf::Vector2f(
        (float)size.x / texture.getSize().x,
        (float)size.y / texture.getSize().y
    ));

    rect = sf::FloatRect(sf::Vector2f{0, 0},sf::Vector2f{ size.x, size.y});
}

void Hill::setPosition(float x, float y){
    rect.position = {x, y};
    sprite->setPosition({x, y});
}

void Hill::draw(Renderer& renderer){
    if(sprite)
        renderer.draw(*sprite);
}