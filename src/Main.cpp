#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include"../headers/Global.h"
#include "../headers/Utils.h"
#include "../headers/Map.h"
#include "../headers/Renderer.h"
#include "../headers/Mario.h"

int main(){
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), TITLE);
    window.setFramerateLimit(FRAMERATE);

    sf::Clock clock;
    sf::View view = window.getDefaultView();
    State state;

    Renderer renderer(window);
    Map map;
    map.createTestMap(CELL_WIDTH);

    Mario mario(sf::Vector2f(50, 50));
    mario.init();

    while(window.isOpen()){
        
        window.handleEvents(
            [&window](const sf::Event::Closed&) { handle_close(window); },
            [&state](const auto& event) { handle(event, state); }
        );

        float deltaTime = clock.restart().asSeconds();

        window.setView(view);

        window.clear(sf::Color(0, 219, 255));

        map.draw(renderer);
        mario.update(deltaTime);
        mario.draw(renderer);

        window.display();
    }

    return 0;
}