#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include"../headers/Global.h"
#include "../headers/Utils.h"
#include "../headers/Map.h"
#include "../headers/Renderer.h"
#include "../headers/Mario.h"
#include"../headers/Camera.h"
#include "../headers/Collision.h"

Map map;
Mario mario;
Camera camera;
Collision collision(map.getMap2D());
int coinCounter = 0;

int main(){
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), TITLE);
    window.setFramerateLimit(FRAMERATE);

    sf::Clock clock;
    sf::View view = window.getDefaultView();
    State state;
    state.init();

    Renderer renderer(window);
    map.createMapFromFile("../assets/images/Map/TestMap.png");


    while(window.isOpen()){
        
        window.handleEvents(
            [&window](const sf::Event::Closed&) { handle_close(window); },
            [&state](const auto& event) { handle(event, state); }
        );

        float deltaTime = clock.restart().asSeconds();

        mario.update(deltaTime);
        map.update(deltaTime);

        camera.updateView(view, window, mario, map);
        window.setView(view);

        window.clear(sf::Color(0, 219, 255));

        map.draw(renderer);
        mario.draw(renderer);

        state.draw(window);

        window.display();
    }

    return 0;
}