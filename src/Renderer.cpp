#include "../headers/Renderer.h"

Renderer::Renderer(sf::RenderWindow &window) : window(window){}

void Renderer::draw(const sf::Sprite &sprite){
    window.draw(sprite);
}