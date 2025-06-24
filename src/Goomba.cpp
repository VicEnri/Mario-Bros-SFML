#include "../headers/Goomba.h"
#include "../headers/Global.h"
#include "../headers/Collision.h"
#include "../headers/TextureManager.h"

extern Collision collision;

Goomba::Goomba(sf::Vector2f position)
    : Object(ObjectType::GOOMBA),
      speed(150),
      direction(-1.f), //parte da sx
      verticalSpeed(0),
      isGrounded(false),
      walkAnimation(0.30f)
{
    rect = sf::FloatRect(position, sf::Vector2f{60.f, 60.f});
}

void Goomba::setPosition(float x, float y){
    rect.position = {x, y};
    sprite->setPosition({x, y});
}

void Goomba::init(){
    textures[0] = TextureManager::getTexture("../assets/images/Enemy/GoombaWalk1.png");
    textures[1] = TextureManager::getTexture("../assets/images/Enemy/GoombaWalk2.png");
    textures[2] = TextureManager::getTexture("../assets/images/Enemy/GoombaDeath.png");
    sprite = std::make_unique<sf::Sprite>(textures[0]);
    sprite->setTexture(textures[0]);
    sprite->setScale(sf::Vector2f(
        (float)rect.size.x / textures[0].getSize().x,
        (float)rect.size.y / textures[0].getSize().y
    ));
    walkAnimation.addFrame(Frame(&textures[0], 0.15f));
    walkAnimation.addFrame(Frame(&textures[1], 0.30f));
}

void Goomba::kill(){
    dead = true;
    deathTimer = 0.f;
}


void Goomba::update(float deltaTime){
    if(deltaTime > 0.1f) deltaTime = 0.1f;

    if(dead){
        deathTimer += deltaTime;
        sprite->setTexture(textures[2]);
        return;
    }

    float velocity = direction * speed * deltaTime;
    verticalSpeed += GRAVITY * deltaTime;

    //collisione orizzontale
    checkCollisionResult result = collision.checkCollision(rect.position.x + velocity, rect.position.y, rect.size.x, rect.size.y, verticalSpeed);
    if(result.collided){
        direction *= -1.f;
        velocity = direction * speed * deltaTime; //aggiorna direzione
    }

    //collisione verticale(pavimento)
    checkCollisionResult downResult = collision.checkCollision(rect.position.x, rect.position.y + verticalSpeed * deltaTime, rect.size.x, rect.size.y, verticalSpeed);
    if(downResult.collided){
        verticalSpeed = 0.f;
        isGrounded = downResult.grounded;
    }else
        isGrounded = false;

    rect.position.x += velocity;
    rect.position.y += verticalSpeed * deltaTime;

    sprite->setTexture(*walkAnimation.update(deltaTime));
    sprite->setPosition(rect.position);
}

void Goomba::draw(Renderer& renderer){
    sprite->setPosition(rect.position);
    renderer.draw(*sprite);
}
