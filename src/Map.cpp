#include<iostream>

#include"../headers/Map.h"
#include"../headers/FloorBlock.h"
#include"../headers/StairBlock.h"
#include"../headers/Block.h"
#include"../headers/Mario.h"

extern Mario mario;

Map::Map(){}

void Map::createMapFromFile(const char* filename){
    map2D.clear();
    sf::Image image;
    image.loadFromFile(filename);
    
    for(int x = 0; x < image.getSize().x; x++){
        Column column;
        for (int y = 0; y < image.getSize().y; y++){
           Obj obj = nullptr;
            sf::Color pixelColor(image.getPixel(sf::Vector2u(x, y)));

            if(pixelColor == sf::Color::Red){
                mario.init();
                mario.setPosition(x * CELL_SIZE, y * CELL_SIZE);
            }else if(pixelColor == sf::Color::Black){
                obj = std::make_unique<FloorBlock>();
                obj->init();
                obj->setPosition(x * CELL_SIZE, y * CELL_SIZE);
            }else if(pixelColor == sf::Color(80, 40, 10)){
                obj = std::make_unique<StairBlock>();
                obj->init();
                obj->setPosition(x * CELL_SIZE, y * CELL_SIZE);
            }else if(pixelColor == sf::Color(128, 64, 0)){
                obj = std::make_unique<Block>();
                obj->init();
                obj->setPosition(x * CELL_SIZE, y * CELL_SIZE);
            }
            column.push_back(std::move(obj));
        }
        map2D.push_back(std::move(column));
    }
}

void Map::draw(Renderer& renderer){
    for(size_t i = 0; i < map2D.size(); i++){
        for(size_t j = 0; j < map2D[i].size(); j++)
            if(map2D[i][j])    map2D[i][j]->draw(renderer); 
    }
}