
#include <iostream>

#include"../headers/Collision.h"

extern Map map;

Collision::Collision(Map2D& map2D) : map2D(map2D){}

checkCollisionResult Collision::checkCollision(float x, float y, float width, float height, float verticalVelocity){
    checkCollisionResult result;
    int tileColumnStart = (int)(x / CELL_SIZE);
    int tileColumnEnd = (int)((x + width) / CELL_SIZE) + 1; 
    int tileRowStart = (int)(y / CELL_SIZE);
    int tileRowEnd = (int)((y + height) / CELL_SIZE) + 1;

    if(x < 0 || (x + width) > map2D.size() * CELL_SIZE){
        result.collided = true;
        return result;
    }
    
    for(int column = tileColumnStart; column < tileColumnEnd; column++){
        if(column < 0 || column >= map2D.size()) continue;

        int maxRows = map2D[column].size();
        for(int row = tileRowStart; row < std::min(tileRowEnd, maxRows); row++){
            if(row < 0) continue;

            const auto& obj = map2D[column][row];
            if(obj){
                if(obj->getType() == ObjectType::FLOOR || obj->getType() == ObjectType::STAIR || obj->getType() == ObjectType::BLOCK){
                    result.collided = true;
                    if(verticalVelocity >= 0 && y + height <= row * CELL_SIZE + CELL_SIZE)
                        result.grounded = true;
                }
            }
        }
    }
    return result;
}
