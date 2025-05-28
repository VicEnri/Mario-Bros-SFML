#pragma once

#include"Object.h"
#include<memory>

class Mario :
    public Object{
        public:

            Mario(sf::Vector2f position = sf::Vector2f(50,50));

            void init() override;
            void draw(Renderer& renderer) override;
            void update(float deltaTime) override;

            void setPosition(float x, float y) override;

            sf::Vector2f getPosition() const override {return sprite->getPosition();}

            sf::FloatRect getRect() const {return rect;}

        private:

            float speed;
            sf::Texture texture;
            std::unique_ptr<sf::Sprite> sprite;

};