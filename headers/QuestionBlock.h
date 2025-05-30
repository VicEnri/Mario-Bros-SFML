#pragma once

#include<memory>

#include"Object.h"
#include"Animation.h"


class QuestionBlock : public Object{
    public:
        QuestionBlock(int coin = 1);
        
        void init() override;
        void draw(Renderer& renderer) override;
        void update(float deltaTime) override;

        void setPosition(float x, float y) override {sprite->setPosition({x, y});}
        sf::Vector2f getPosition() const override {return sprite->getPosition();}

        bool hit();
        void setInvisible();

    private:
        std::unique_ptr<sf::Sprite> sprite;
        sf::Texture textures[5];

        bool isHit = false;     //controlla se il blocco è stato colpito
        int coins;

        Animation runAnimation;
};