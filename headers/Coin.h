#pragma once

#include<memory>

#include"Object.h"
#include"Animation.h"


class Coin : public Object{
    public:
        Coin();
        
        void init() override;
        void draw(Renderer& renderer) override;
        void update(float deltaTime) override;

        void setPosition(float x, float y) override {sprite->setPosition({x, y});}
        sf::Vector2f getPosition() const override {return sprite->getPosition();}

    private:
        std::unique_ptr<sf::Sprite> sprite;
        sf::Texture textures[10];

        Animation runAnimation;
};