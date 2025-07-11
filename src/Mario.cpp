#include<iostream>

#include"../headers/Mario.h"
#include"../headers/Global.h"
#include"../headers/Map.h"
#include"../headers/Collision.h"
#include "../headers/TextureManager.h"

extern Collision collision;
extern Map map;

Mario::Mario(sf::Vector2f position) : 
    Object(ObjectType::MARIO),
    speed(300),
    verticalSpeed(0),
    jumpSpeed(-600),
    isGrounded(false),
    facingLeft(false),
    runAnimation(0.45f){

    rect = sf::FloatRect(position, sf::Vector2f{45.f, 45.f});

}

void Mario::setPosition(float x, float y){
    rect.position = {x,y};
    sprite->setPosition({x, y});
}

void Mario::init(){
    textures[0] = TextureManager::getTexture("../assets/images/Mario/MarioWalk1.png");
    textures[1] = TextureManager::getTexture("../assets/images/Mario/MarioWalk2.png");
    textures[2] = TextureManager::getTexture("../assets/images/Mario/MarioWalk3.png");
    textures[3] = TextureManager::getTexture("../assets/images/Mario/MarioIdle.png");
    textures[4] = TextureManager::getTexture("../assets/images/Mario/MarioJump.png");
    textures[5] = TextureManager::getTexture("../assets/images/Mario/MarioDeath.png");

    sprite = std::make_unique<sf::Sprite>(textures[3]);
    sprite->setTexture(textures[3]);

    sprite->setScale(sf::Vector2f(
        (float)rect.size.x / textures[3].getSize().x,
        (float)rect.size.y / textures[3].getSize().y
    ));

    runAnimation.addFrame(Frame(&textures[0], 0.15f));
    runAnimation.addFrame(Frame(&textures[1], 0.30f));
    runAnimation.addFrame(Frame(&textures[2], 0.45f));

}

void Mario::update(float deltaTime){
    if(dead || win) return;
    float velocity = 0.0f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left)){
        velocity = -speed * deltaTime;
        facingLeft = true;
    }if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right)){
        velocity = speed * deltaTime;
        facingLeft = false;
    }if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up) && isGrounded){
        verticalSpeed = jumpSpeed;
        isGrounded = false;
    }

    if(deltaTime > 0.1f)   deltaTime = 0.1f;
    verticalSpeed += GRAVITY * deltaTime;

    if(collision.checkCollision(rect.position.x + velocity, rect.position.y, rect.size.x, rect.size.y, verticalSpeed).collided)
        velocity = 0;

    checkCollisionResult result = collision.checkCollision(rect.position.x, rect.position.y + verticalSpeed * deltaTime, rect.size.x, rect.size.y, verticalSpeed);
    
    if(result.collided)
        verticalSpeed = 0;

    isGrounded = result.grounded;

    rect.position.x += velocity;
    rect.position.y += verticalSpeed * deltaTime;

    if(!isGrounded) //se salta
        sprite->setTexture(textures[4]);
    else if(std::abs(velocity) > 0.02f) //se si muove
        sprite->setTexture(*runAnimation.update(deltaTime));
    else //se è fermo
        sprite->setTexture(textures[3]);

}

void Mario::draw(Renderer& renderer){
    if (dead)
        sprite->setTexture(textures[5]); // texture morte
    if(facingLeft){
        sprite->setScale(sf::Vector2f(-std::abs(sprite->getScale().x), sprite->getScale().y));
        sprite->setPosition(sf::Vector2f(rect.position.x + rect.size.x, rect.position.y));
    }else{
        sprite->setScale(sf::Vector2f(std::abs(sprite->getScale().x), sprite->getScale().y));
        sprite->setPosition(sf::Vector2f(rect.position.x, rect.position.y));
    }

    renderer.draw(*sprite);
}