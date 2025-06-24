#pragma once

#include<SFML/Graphics.hpp>
#include<vector>

#include"Global.h"
#include"Object.h"
#include"Renderer.h"
#include"Goomba.h"

class Map{
    public:
        Map();
        void createMapFromFile(const char* filename, std::vector<std::unique_ptr<Goomba>>& goombas);
        void draw(Renderer& renderer);
        void update(float deltaTime);

        void spawnCoinAboveBlock(int column, int row);

        Map2D& getMap2D() {return map2D;}; 

        sf::FloatRect getFlagRect() const;

    private:
        Map2D map2D;    //mappa 2D

};