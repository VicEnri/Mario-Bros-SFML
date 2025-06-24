#include<iostream>

#include"../headers/Map.h"
#include"../headers/FloorBlock.h"
#include"../headers/StairBlock.h"
#include"../headers/Block.h"
#include"../headers/Mario.h"
#include"../headers/Coin.h"
#include"../headers/Global.h"
#include"../headers/QuestionBlock.h"
#include"../headers/Cloud.h"
#include"../headers/Bush.h"
#include"../headers/Hill.h"
#include"../headers/Flag.h"
#include"../headers/Castle.h"


extern Mario mario;

Map::Map(){}

void Map::createMapFromFile(const char* filename, std::vector<std::unique_ptr<Goomba>>& goombas){
    map2D.clear();
    sf::Image image;
    if(!image.loadFromFile(filename))
        std::cerr << "Errore: impossibile caricare MarioIdle.png\n";
    
    for(int x = 0; x < image.getSize().x; x++){
        Column column;
        for (int y = 0; y < image.getSize().y; y++){
           Obj obj = nullptr;
            sf::Color pixelColor(image.getPixel(sf::Vector2u(x, y)));

            if(pixelColor == sf::Color::Red){
                mario.init();
                mario.setPosition(x * CELL_SIZE, y * CELL_SIZE);
            }else if(pixelColor == sf::Color::Black){ //nero
                obj = std::make_unique<FloorBlock>();
                obj->init();
                obj->setPosition(x * CELL_SIZE, y * CELL_SIZE);
            }else if(pixelColor == sf::Color(80, 40, 10)){ //marrone scuro
                obj = std::make_unique<StairBlock>();
                obj->init();
                obj->setPosition(x * CELL_SIZE, y * CELL_SIZE);
            }else if(pixelColor == sf::Color(128, 64, 0)){  //marrone chiaro
                obj = std::make_unique<Block>();
                obj->init();
                obj->setPosition(x * CELL_SIZE, y * CELL_SIZE);
            }else if(pixelColor == sf::Color(255,165,0)){   //arancione
                obj = std::make_unique<QuestionBlock>();
                obj->init();
                obj->setPosition(x * CELL_SIZE, y * CELL_SIZE);
            }else if(pixelColor == sf::Color(255,255,255)){ //bianco
                obj = std::make_unique<QuestionBlock>();
                obj->init();
                obj->setPosition(x * CELL_SIZE, y * CELL_SIZE);
                if(auto qb = dynamic_cast<QuestionBlock*>(obj.get()))  qb->setInvisible();
            }else if(pixelColor == sf::Color(255,255,0)){ //giallo
                obj = std::make_unique<Coin>();
                obj->init();
                obj->setPosition(x * CELL_SIZE, y * CELL_SIZE);
            }else if(pixelColor == sf::Color(128,128,128)){ //grigio
                obj = std::make_unique<Cloud>();
                obj->init();
                obj->setPosition(x * CELL_SIZE, y * CELL_SIZE);
            }else if(pixelColor == sf::Color(144,238,144)){ //verde chiaro
                obj = std::make_unique<Bush>();
                obj->init();
                obj->setPosition(x * CELL_SIZE, y * CELL_SIZE);
            }else if(pixelColor == sf::Color(0,100,0)){ //verde scuro
                obj = std::make_unique<Hill>();
                obj->init();
                obj->setPosition(x * CELL_SIZE, y * CELL_SIZE);
            }else if(pixelColor == sf::Color(255,215,0)){ //oro
                obj = std::make_unique<Flag>();
                obj->init();
                obj->setPosition(x * CELL_SIZE, y * CELL_SIZE);
            }else if(pixelColor == sf::Color(0,0,255)){ //blu
                obj = std::make_unique<Castle>();
                obj->init();
                obj->setPosition(x * CELL_SIZE, y * CELL_SIZE);
            }else if(pixelColor == sf::Color(139,69,19)){ //marrone scuro
                auto goomba = std::make_unique<Goomba>();
                goomba->init();
                goomba->setPosition(x * CELL_SIZE, y * CELL_SIZE);
                goombas.push_back(std::move(goomba));
            }
            column.push_back(std::move(obj));
        }
        map2D.push_back(std::move(column));
    }
}

void Map::update(float deltaTime){
    for (const auto& column : map2D) {
        for(const auto& obj : column)
            if (obj) obj->update(deltaTime);
    }
}

void Map::spawnCoinAboveBlock(int column, int row){
    if (row - 1 >= 0){  //controlla che ci sia spazio sopra il blocco
        if (!map2D[column][row - 1]){  //se la posizione sopra il blocco è vuota
            Obj coin = std::make_unique<Coin>();
            coin->init();
            coin->setPosition(column * CELL_SIZE, (row - 1) * CELL_SIZE);   //posiziona la moneta sopra il blocco
            map2D[column][row - 1] = std::move(coin);   //aggiungi la moneta alla mappa
        }
    }
}

void Map::draw(Renderer& renderer){
    sf::View view = renderer.getWindow().getView();
    sf::FloatRect viewRect(
        view.getCenter() - view.getSize() / 2.f,
        view.getSize()
    );

    for(const auto& column : map2D){
        for(const auto& objPtr : column){
            if (!objPtr) continue;

            auto intersectionOpt = objPtr->getRect().findIntersection(viewRect);
                if(intersectionOpt.has_value() && intersectionOpt->size.x > 0 && intersectionOpt->size.y > 0)
                    objPtr->draw(renderer);
        }
    }
}


sf::FloatRect Map::getFlagRect() const{
    for(const auto& column : map2D){
        for (const auto& obj : column){
            if(obj && obj->getType() == ObjectType::FLAG)
                return obj->getRect();
        }
    }
    return sf::FloatRect(); //flag non trovata, empty rect
}
