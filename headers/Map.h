#pragma once

#include<SFML/Graphics.hpp>
#include<vector>

#include"Global.h"
#include"Object.h"
#include"Renderer.h"

class Map{
    public:
        Map();
        void createTestMap(int lenght);
        void draw(Renderer& renderer);
        void update(float deltaTime) {};


        std::vector<std::vector<Object*>>& getMap2D() {return map2D;}; 


    private:
        std::vector<std::vector<Object*>> map2D;    //mappa 2D

};