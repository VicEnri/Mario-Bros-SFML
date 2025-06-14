#pragma once

#include<SFML/Graphics.hpp>
#include<memory>

#include"HUD.h"
#include"StartScreen.h"
#include"GameOver.h"
#include"../Mario.h"
#include"../Map.h"
#include"../TextureManager.h"

class State{
    public:
        void init();
        void draw(sf::RenderWindow& window, const sf::View& view, int coinCounter);
        void checkGameOver(const sf::View& view, const Mario& mario);
        bool isStartClicked(const sf::RenderWindow& window);
        bool isRetryClicked(const sf::RenderWindow& window);
        bool isMenuClicked(const sf::RenderWindow& window);
        void resetGame(Map& map, int& coinCounter, Mario& mario, const char* mapFile);

        bool showStartScreen = true;
        bool gameOver = false;

    private:
        std::unique_ptr<sf::Font> font;
        std::unique_ptr<sf::Font> titleFont;
        std::unique_ptr<sf::Sprite> coinSprite;
        HUD hud;
        StartScreen startScreen;
        GameOverScreen gameOverScreen;
};
