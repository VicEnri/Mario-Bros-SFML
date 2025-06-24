#pragma once

#include<SFML/Graphics.hpp>
#include<memory>

#include"HUD.h"
#include"StartScreen.h"
#include"GameOver.h"
#include"../Mario.h"
#include"../Map.h"
#include"../TextureManager.h"
#include"../Renderer.h"
#include"VictoryScreen.h"

class State{
    public:
        void init();
        void draw(Renderer& renderer, const sf::View& view, int coinCounter);
        void checkGameOver(const sf::View& view, const Mario& mario);

        bool isStartClicked(const sf::Vector2f& mousePos) const;
        bool isRetryClicked(const sf::Vector2f& mousePos) const;
        bool isMenuClicked(const sf::Vector2f& mousePos) const;
        bool isContinueClicked(const sf::Vector2f& mousePos) const;

        void resetGame(Map& map, int& coinCounter, Mario& mario, const char* mapFile);

        bool showStartScreen = true;
        bool gameOver = false;
        bool victory = false;


    private:
        std::unique_ptr<sf::Font> font;
        std::unique_ptr<sf::Font> titleFont;
        std::unique_ptr<sf::Sprite> coinSprite;
        
        HUD hud;
        StartScreen startScreen;
        GameOverScreen gameOverScreen;
        VictoryScreen victoryScreen;

        
};
