#pragma once

#include<SFML/Graphics.hpp>

enum class ObjectType{
    WALL
};

class Object {
    public:
        Object(ObjectType type);

        virtual void init() = 0;
        virtual void draw(sf::RenderWindow& window) = 0;
        virtual void update(float deltaTime) = 0;

        virtual void setPosition(float x, float y) = 0;
        virtual sf::Vector2f getPosition() const = 0;

        ObjectType getType() const { return type; }

    protected:
        sf::FloatRect rect; //rettangolo di collisione
        ObjectType type;
};