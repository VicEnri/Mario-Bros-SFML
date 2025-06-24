#include <iostream>

#include"../headers/Collision.h"
#include "../headers/QuestionBlock.h"

extern Map map;
extern int coinCounter;

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

    sf::FloatRect marioRect(sf::Vector2f(x, y), sf::Vector2f(width, height));

    for(int column = tileColumnStart; column < tileColumnEnd; column++){
        if(column < 0 || column >= map2D.size()) continue;

        int maxRows = map2D[column].size();
        for(int row = tileRowStart; row < std::min(tileRowEnd, maxRows); row++){
            if(row < 0) continue;

            const auto& obj = map2D[column][row];
            if(obj){
                sf::FloatRect objRect(
                    sf::Vector2f(float(column * CELL_SIZE), (float)(row * CELL_SIZE)),
                    sf::Vector2f((float)CELL_SIZE, (float)CELL_SIZE));

                if(obj->getType() == ObjectType::COIN){
                    if(marioRect.findIntersection(objRect)) {
                        map2D[column][row] = nullptr;
                        coinCounter++;
                    }
                }else if(obj->getType() == ObjectType::QUESTION_BLOCK){
                    QuestionBlock* questionBlock = dynamic_cast<QuestionBlock*>(obj.get());

                    //colpo da sotto
                    if(questionBlock && verticalVelocity < 0 && marioRect.findIntersection(objRect) && (y + height) > (row * CELL_SIZE)){
                        if(questionBlock->hit())
                            map.spawnCoinAboveBlock(column, row);
                    }

                    //collisione solo se visibile
                    if(questionBlock && questionBlock->isBlockVisible() && marioRect.findIntersection(objRect)){
                        result.collided = true;
                        //grounded se Mario è sopra il blocco
                        if(row == (int)((y + height) / CELL_SIZE))
                            result.grounded = true;
                    }
                }else if(
                    obj->getType() == ObjectType::FLOOR ||
                    obj->getType() == ObjectType::STAIR ||
                    obj->getType() == ObjectType::BLOCK
                ){
                    if(marioRect.findIntersection(objRect)) {
                        result.collided = true;
                        if(verticalVelocity >= 0 && y + height <= row * CELL_SIZE + CELL_SIZE)
                            result.grounded = true;
                    }
                }
            }
        }
    }
    return result;
}