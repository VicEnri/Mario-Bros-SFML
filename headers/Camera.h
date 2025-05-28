#pragma once

#include"../headers/Mario.h"
#include"../headers/Map.h"


class Camera{
    public:
        void updateView(sf::View &view, sf::RenderWindow &window, const Mario &mario, Map &map);
    
    private:
        constexpr static float SIZE = 900.0f; //dimensione base della vista
};