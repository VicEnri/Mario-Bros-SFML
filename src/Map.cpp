#include<iostream>

#include"../headers/Map.h"
#include"../headers/FloorBlock.h"


Map::Map(){}

void Map::createTestMap(int length){

    map2D.resize(length, std::vector<Object*>(CELL_HEIGHT, nullptr));

    for(int i = 0; i < length; i++){
        FloorBlock* floor = new FloorBlock();
        floor->init();
        floor->setPosition(i * CELL_SIZE, (CELL_HEIGHT - 1) * CELL_SIZE);
        map2D[i][CELL_HEIGHT - 1] = floor;

        if((i + 1) % 6 == 0){
            for(int j = CELL_HEIGHT - (180 / CELL_SIZE); j < CELL_HEIGHT; j++){
                FloorBlock* verticalFloor = new FloorBlock();
                verticalFloor->init();
                verticalFloor->setPosition(i * CELL_SIZE, j * CELL_SIZE);
                map2D[i][j] = verticalFloor;
            }
        }
    }
}

void Map::draw(Renderer& renderer){
    for(size_t i = 0; i < map2D.size(); i++){
        for(size_t j = 0; j < map2D[i].size(); j++)
            if(map2D[i][j])    map2D[i][j]->draw(renderer); 
    }
}