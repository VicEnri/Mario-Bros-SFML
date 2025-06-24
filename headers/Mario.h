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

            void setVerticalSpeed(float v) { verticalSpeed = v; }

            void setDead(bool d) { dead = d; }
            void setWin(bool d) { win = d; }
        
        private:

            float speed;
            float verticalSpeed;
            float jumpSpeed;
            bool isGrounded;
            bool facingLeft;

            bool dead = false;
            bool win = false;

            sf::Texture textures[6];
            std::unique_ptr<sf::Sprite> sprite;

            Animation runAnimation;

};