#include <iostream>

#include "../headers/Bush.h"
#include "../headers/Global.h"
#include "../headers/TextureManager.h"

Bush::Bush() : Object(ObjectType::BUSH) {}

void Bush::init() {
    
    texture = TextureManager::getTexture("../assets/images/Landscape/Bush.png");
    
    sprite = std::make_unique<sf::Sprite>(texture);
    sprite->setTexture(texture);

    sf::Vector2f size(
        2.f * (float)CELL_SIZE,    //larghezza in pixel di gioco
        (float)CELL_SIZE    //altezza in pixel di gioco
    );

    sprite->setScale(sf::Vector2f(
        (float)size.x / texture.getSize().x,
        (float)size.y / texture.getSize().y
    ));

    rect = sf::FloatRect(sf::Vector2f{0, 0},sf::Vector2f{ size.x, size.y});
}

void Bush::setPosition(float x, float y){
    rect.position = {x, y};
    sprite->setPosition({x, y});
}

void Bush::draw(Renderer& renderer){
    if(sprite)
        renderer.draw(*sprite);
}