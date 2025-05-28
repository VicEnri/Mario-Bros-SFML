#pragma once

#include<memory>

constexpr const char* TITLE = "Mario Bros";
constexpr unsigned SCREEN_WIDTH = 800;
constexpr unsigned SCREEN_HEIGHT = 600;
constexpr float FRAMERATE = 60;

#define CELL_SIZE 30
#define CELL_WIDTH (SCREEN_WIDTH / CELL_SIZE)
#define CELL_HEIGHT (SCREEN_HEIGHT / CELL_SIZE)

#define Map2D std::vector<std::vector<std::unique_ptr<Object>>>
#define Column std::vector<std::unique_ptr<Object>>
#define Obj std::unique_ptr<Object>

#define GRAVITY 981.f