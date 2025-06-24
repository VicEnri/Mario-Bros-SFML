#pragma once
#include <memory>
#include "Object.h"
#include "Animation.h"

class Goomba : public Object {
public:
    Goomba(sf::Vector2f position = sf::Vector2f(100, 50));

    void init() override;
    void update(float deltaTime) override;
    void draw(Renderer& renderer) override;

    void setPosition(float x, float y) override;
    sf::Vector2f getPosition() const override { return sprite->getPosition(); }
    sf::FloatRect getRect() const { return rect; }


    bool isDead() const { return dead; }
    float getDeathTimer() const { return deathTimer; }
    void kill();

private:
    float speed;
    float direction; //-1 per sinistra, +1 per destra
    bool isGrounded = false;
    float verticalSpeed = 0.f;
    sf::FloatRect rect;
    sf::Texture textures[3];
    std::unique_ptr<sf::Sprite> sprite;
    Animation walkAnimation;
    bool dead = false;
    float deathTimer = 0.f;
};