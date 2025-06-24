#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <algorithm>

#include "../headers/Global.h"
#include "../headers/UI/StateManager.h"
#include "../headers/Map.h"
#include "../headers/Renderer.h"
#include "../headers/Mario.h"
#include "../headers/Camera.h"
#include "../headers/Collision.h"
#include "../headers/Goomba.h"


Map map;
Mario mario;
Camera camera;
Collision collision(map.getMap2D());
std::vector<std::unique_ptr<Goomba>> goombas;
int coinCounter = 0;

const char* mapFiles[] = {
    "../assets/images/Map/TestMap.png",
    "../assets/images/Map/Level1.png"
};
const int numMaps = sizeof(mapFiles) / sizeof(mapFiles[0]);
int currentMapIndex = 0;


void handleMouseClicks(State& state, const sf::Vector2f& mousePos, bool& mouseWasPressed, bool& justStarted, sf::Clock& clock){
    if(state.isRetryClicked(mousePos)){
        if(!mouseWasPressed){
            state.resetGame(map, coinCounter, mario, goombas, mapFiles[currentMapIndex]);
            justStarted = true;
            clock.restart();
        }
        mouseWasPressed = true;
    }else if(state.isMenuClicked(mousePos)){
        if(!mouseWasPressed){
            state.showStartScreen = true;
            state.gameOver = false;
            currentMapIndex = 0;
            state.resetGame(map, coinCounter, mario, goombas, mapFiles[currentMapIndex]);
            justStarted = true;
            clock.restart();
        }
        mouseWasPressed = true;
    }else if(state.isContinueClicked(mousePos)){
        if(!mouseWasPressed) {
            if(currentMapIndex == numMaps - 1){
                state.finalVictory = true;
            }else{
                state.victory = false;
                currentMapIndex = (currentMapIndex + 1) % numMaps;
                state.resetGame(map, coinCounter, mario, goombas, mapFiles[currentMapIndex]);
                justStarted = true;
                clock.restart();
            }
        }
        mouseWasPressed = true;
    }else
        mouseWasPressed = false;
}

int main() {
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), TITLE, sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(FRAMERATE);

    sf::Clock clock;
    sf::View view = window.getDefaultView();
    Renderer renderer(window);

    State state;
    state.init();

    bool justStarted = false;
    static bool mouseWasPressed = false;

    map.createMapFromFile(mapFiles[currentMapIndex], goombas);

    while (window.isOpen()){
        
        window.handleEvents(
            [&window](const sf::Event::Closed&) { window.close(); },
            [&window](const sf::Event::Resized&) { window.setSize(sf::Vector2u(SCREEN_WIDTH, SCREEN_HEIGHT)); },
            [](const auto&) {}
        );

        float deltaTime = clock.restart().asSeconds();

        window.setView(view);
        window.clear(sf::Color(0, 219, 255));

        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        //schermata finale di vittoria
        if(state.finalVictory){
            camera.updateView(view, window, mario, map);
            window.setView(view);

            map.draw(renderer);
            mario.draw(renderer);
            state.getFinalVictoryScreen().draw(renderer, view, mousePos);

            if(state.getFinalVictoryScreen().isMenuClicked(mousePos)){
                if(!mouseWasPressed){
                    state.finalVictory = false;
                    state.showStartScreen = true;
                    currentMapIndex = 0;
                    state.resetGame(map, coinCounter, mario, goombas, mapFiles[currentMapIndex]);
                    justStarted = true;
                    clock.restart();
                }
                mouseWasPressed = true;
            }else
                mouseWasPressed = false;

            window.display();
            continue;
        }

        //schermata di inizio
        if(state.showStartScreen){
            camera.updateView(view, window, mario, map);
            window.setView(view);

            map.draw(renderer);
            mario.draw(renderer);
            state.draw(renderer, view, coinCounter);

            if(state.isStartClicked(mousePos)){
                if(!mouseWasPressed){
                    state.showStartScreen = false;
                    justStarted = true;
                }
                mouseWasPressed = true;
            }else
                mouseWasPressed = false;
            
            window.display();
            continue;
        }

        if(justStarted){
            clock.restart();
            justStarted = false;
            continue;
        }


        mario.update(deltaTime);
        for(auto& goomba : goombas)
            goomba->update(deltaTime);

        //rimuovo i goomba morti da piu di 1 secondo
        goombas.erase(
            std::remove_if(goombas.begin(), goombas.end(),
                [](const std::unique_ptr<Goomba>& g) { return g->isDead() && g->getDeathTimer() > 1.0f; }),
            goombas.end()
        );

        map.update(deltaTime);

        camera.updateView(view, window, mario, map);
        window.setView(view);

        state.checkGameOver(view, mario, goombas);

        
        window.clear(sf::Color(0, 219, 255));
        map.draw(renderer);
        mario.draw(renderer);

        //disegno i goomba vivi
        for(auto& goomba : goombas)
            if(!goomba->isDead() || goomba->getDeathTimer() < 1.0f)
                goomba->draw(renderer);

        state.draw(renderer, view, coinCounter);

        handleMouseClicks(state, mousePos, mouseWasPressed, justStarted, clock);

        window.display();
    }

    return 0;
}