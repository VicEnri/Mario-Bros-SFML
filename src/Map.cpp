#include<iostream>

#include"../headers/Map.h"
#include"../headers/FloorBlock.h"


Map::Map(){}

void Map::createTestMap(int length){

    map2D.clear();
    map2D.resize(length);
    for(int i = 0; i < length; i++)
        map2D[i].resize(CELL_HEIGHT);

    for(int i = 0; i < length; i++){
        Obj floor = std::make_unique<FloorBlock>();
        floor->init();
        floor->setPosition(i * CELL_SIZE, (CELL_HEIGHT - 1) * CELL_SIZE);
        map2D[i][CELL_HEIGHT - 1] = std::move(floor);

        if((i + 1) % 6 == 0){
            for(int j = CELL_HEIGHT - (180 / CELL_SIZE); j < CELL_HEIGHT; j++){
                Obj verticalFloor = std::make_unique<FloorBlock>();
                verticalFloor->init();
                verticalFloor->setPosition(i * CELL_SIZE, j * CELL_SIZE);
                map2D[i][j] = std::move(verticalFloor);
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