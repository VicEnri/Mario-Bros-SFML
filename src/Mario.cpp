#include<iostream>

#include"../headers/Mario.h"
#include"../headers/Global.h"
#include"../headers/Map.h"

Mario::Mario(sf::Vector2f position) : 
    Object(ObjectType::MARIO),
    speed(300),
    verticalSpeed(0),
    jumpSpeed(-600){

    rect = sf::FloatRect(position, sf::Vector2f{45.f, 45.f});

}

void Mario::setPosition(float x, float y){
    rect.position = {x,y};
    sprite->setPosition({x, y});
}

void Mario::init(){
    if(!texture.loadFromFile("../assets/images/Mario/MarioIdle.png"))
        std::cerr << "Errore: impossibile caricare MarioIdle.png\n";

    sprite = std::make_unique<sf::Sprite>(texture);
    sprite->setTexture(texture);

    sprite->setScale(sf::Vector2f(
        (float)rect.size.x / texture.getSize().x,
        (float)rect.size.y / texture.getSize().y
    ));


}

void Mario::update(float deltaTime){

    float velocity = 0.0f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left))
        velocity = -speed * deltaTime;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right))
        velocity = speed * deltaTime;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up))
        verticalSpeed = -speed * deltaTime;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down))
        verticalSpeed = speed * deltaTime;

    verticalSpeed += GRAVITY * deltaTime;

    rect.position.x += velocity;
    rect.position.y += verticalSpeed * deltaTime;

}

void Mario::draw(Renderer& renderer){
    sprite->setPosition(sf::Vector2f(rect.position.x, rect.position.y));
    renderer.draw(*sprite);
}