#pragma once

#include"Object.h"
#include<memory>

class FloorBlock : public Object{
    public:
        FloorBlock();
        
        void init() override;
        void draw(Renderer& renderer) override;
        void update(float deltaTime) override {};

        void setPosition(float x, float y) override;
        sf::Vector2f getPosition() const override {return sprite->getPosition();}

    private:
        std::unique_ptr<sf::Sprite> sprite;
        sf::Texture texture;
};