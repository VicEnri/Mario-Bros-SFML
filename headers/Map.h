#pragma once

#include<SFML/Graphics.hpp>
#include<vector>

#include"Global.h"
#include"Object.h"
#include"Renderer.h"

class Map{
    public:
        Map();
        void createMapFromFile(const char* filename);
        void draw(Renderer& renderer);
        void update(float deltaTime);

        void spawnCoinAboveBlock(int column, int row);

        Map2D& getMap2D() {return map2D;}; 

    private:
        Map2D map2D;    //mappa 2D

};