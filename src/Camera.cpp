#include<algorithm>

#include "../headers/Camera.h"
#include "../headers/Global.h"

void Camera::updateView(sf::View &view, sf::RenderWindow &window, const Mario &mario, Map &map){
    float aspectRatio = (float)window.getSize().x / (float)window.getSize().y;

    if(aspectRatio > 1.0f)
        view.setSize(sf::Vector2f(SIZE * aspectRatio, SIZE));
    else
        view.setSize(sf::Vector2f(SIZE, SIZE / aspectRatio));

    float mapWidth = map.getMap2D().size() * CELL_SIZE;
    float mapHeight = map.getMap2D()[0].size() * CELL_SIZE;
    float viewWidth = view.getSize().x;
    float viewHeight = view.getSize().y;

    const auto& rect = mario.getRect();
    float targetX = rect.position.x + rect.size.x / 2.0f;
    float targetY = rect.position.y + rect.size.y / 2.0f;

    targetX = std::clamp(targetX, viewWidth / 2.0f, mapWidth - viewWidth / 2.0f);
    targetY = std::clamp(targetY, viewHeight / 2.0f, mapHeight - viewHeight / 2.0f);

    view.setCenter(sf::Vector2f(targetX, targetY));
}