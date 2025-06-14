#pragma once
#include<memory>

#include"Object.h"
#include"Animation.h"

class Mario :
    public Object{
        public:

            Mario(sf::Vector2f position = sf::Vector2f(50,50));

            void init() override;
            void draw(Renderer& renderer) override;
            void update(float deltaTime) override;

            void setPosition(float x, float y) override;

            void resetVerticalSpeed() { verticalSpeed = 0.f; }

            sf::Vector2f getPosition() const override {return sprite->getPosition();}

            sf::FloatRect getRect() const {return rect;}

        private:

            float speed;
            float verticalSpeed;
            float jumpSpeed;
            bool isGrounded;
            bool facingLeft;


            sf::Texture textures[5];
            std::unique_ptr<sf::Sprite> sprite;

            Animation runAnimation;

};