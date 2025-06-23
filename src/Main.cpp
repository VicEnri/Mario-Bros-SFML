#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include"../headers/Global.h"
#include"../headers/UI/StateManager.h"
#include"../headers/Map.h"
#include"../headers/Renderer.h"
#include"../headers/Mario.h"
#include"../headers/Camera.h"
#include"../headers/Collision.h"

Map map;
Mario mario;
Camera camera;
Collision collision(map.getMap2D());
int coinCounter = 0;

const char* mapFiles[] = {
    "../assets/images/Map/Level1.png",
};

const int numMaps = 1;
int currentMapIndex = 0;

int main(){
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), TITLE);
    window.setFramerateLimit(FRAMERATE);

    sf::Clock clock;
    sf::View view = window.getDefaultView();
    State state;
    state.init();

    Renderer renderer(window);

    static bool mouseWasPressed = false;
    bool justStarted = false;

    map.createMapFromFile(mapFiles[currentMapIndex]);

    while(window.isOpen()){

        window.handleEvents(
            [&window](const sf::Event::Closed&) { window.close(); },
            [](const auto&) {}
        );

        float deltaTime = clock.restart().asSeconds();

        window.setView(view);
        window.clear(sf::Color(0, 219, 255));

        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window)); // calcolo mouse

        //--- SCHERMATA INIZIALE ---
        if(state.showStartScreen){

            camera.updateView(view, window, mario, map);
            window.setView(view);

            //inizializzo mappa e mario ma non aggiorno
            map.draw(renderer);
            mario.draw(renderer);

            state.draw(renderer, view, coinCounter);

            //click su inizia
            if(state.isStartClicked(mousePos)){
                if(!mouseWasPressed) {
                    state.showStartScreen = false;
                    justStarted = true;
                }
                mouseWasPressed = true;
            }else
                mouseWasPressed = false;
            
            window.display();
            continue;
        }

        //---RESET CLOCK DOPO SCHERMATA INIZIALE---
        if(justStarted){
            clock.restart();
            justStarted = false;
        }

        //---AGGIORNAMENTO GIOCO---
        mario.update(deltaTime);
        map.update(deltaTime);
        camera.updateView(view, window, mario, map);
        window.setView(view);

        //controllo stato mario
        state.checkGameOver(view, mario);

        window.clear(sf::Color(0, 219, 255));
        map.draw(renderer);
        mario.draw(renderer);
        state.draw(renderer, view, coinCounter);

        //click su riprova o menu
        if(state.isRetryClicked(mousePos)) {
            if(!mouseWasPressed)
                state.resetGame(map, coinCounter, mario, mapFiles[currentMapIndex]);
            mouseWasPressed = true;
        }else if(state.isMenuClicked(mousePos)){
            if(!mouseWasPressed){
                state.showStartScreen = true;
                state.gameOver = false;
                state.resetGame(map, coinCounter, mario, mapFiles[currentMapIndex]);
            }
            mouseWasPressed = true;
        }else
            mouseWasPressed = false;

        window.display();
    }
    return 0;
}
