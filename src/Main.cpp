#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include"../headers/Global.h"
#include "../headers/Utils.h"
#include "../headers/Map.h"
#include "../headers/Renderer.h"

int main(){
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), TITLE);
    window.setFramerateLimit(FRAMERATE);

    State state;

    Renderer renderer(window);
    Map map;
    map.createTestMap(CELL_WIDTH);

    while(window.isOpen()){
        
        window.handleEvents(
            [&window](const sf::Event::Closed&) { handle_close(window); },
            [&state](const auto& event) { handle(event, state); }
        );

        window.clear(sf::Color(0, 219, 255));
        map.draw(renderer);
        window.display();
    }

    return 0;
}