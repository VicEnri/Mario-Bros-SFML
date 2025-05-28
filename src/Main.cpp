#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include"../headers/Global.h"
#include "../headers/Utils.h"
#include "../headers/Map.h"
#include "../headers/Renderer.h"
#include "../headers/Mario.h"
#include"../headers/Camera.h"

Map map;
Mario mario;
Camera camera;

int main(){
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), TITLE);
    window.setFramerateLimit(FRAMERATE);

    sf::Clock clock;
    sf::View view = window.getDefaultView();
    State state;

    Renderer renderer(window);
    map.createMapFromFile("../assets/images/TestMap.png");


    while(window.isOpen()){
        
        window.handleEvents(
            [&window](const sf::Event::Closed&) { handle_close(window); },
            [&state](const auto& event) { handle(event, state); }
        );

        float deltaTime = clock.restart().asSeconds();

        camera.updateView(view, window, mario, map);
        window.setView(view);

        window.clear(sf::Color(0, 219, 255));

        map.draw(renderer);
        mario.update(deltaTime);
        mario.draw(renderer);

        window.display();
    }

    return 0;
}