#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include"../headers/Global.h"
#include "../headers/Utils.h"

int main(){
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), TITLE);
    window.setFramerateLimit(FRAMERATE);

    State state;
    sf::Clock clock;

    while(window.isOpen()){
        
        window.handleEvents(
            [&window](const sf::Event::Closed&) { handle_close(window); },
            [&state](const auto& event) { handle(event, state); }
        );

        state.update(clock.restart().asSeconds());

        window.clear(sf::Color(0, 219, 255));
        state.draw(window);
        window.display();
    }

    return 0;
}