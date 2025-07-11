#pragma once

#include<SFML/Graphics.hpp>

#include"Renderer.h"

enum class ObjectType{
    MARIO,
    FLOOR,
    STAIR,
    BLOCK,
    COIN,
    QUESTION_BLOCK,
    CLOUD,
    HILL,
    BUSH,
    FLAG,
    GOOMBA
};

class Object {
    public:
        Object(ObjectType type);

        virtual void init() = 0;
        virtual void draw(Renderer& renderer) = 0;
        virtual void update(float deltaTime) = 0;

        virtual void setPosition(float x, float y) = 0;
        virtual sf::Vector2f getPosition() const = 0;

        ObjectType getType() const { return type; }

        const sf::FloatRect& getRect() const { return rect; }

        virtual ~Object() = default;

    protected:
        sf::FloatRect rect; //rettangolo di collisione
        ObjectType type;
};