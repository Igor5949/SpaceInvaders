#pragma once
#include "player.h"
#include "bullet.h"
#include <vector>
#include <SFML/Graphics.hpp>
 constexpr unsigned int Width = 800;
 constexpr unsigned int Height = 600;
 constexpr unsigned int aliens_rows = 5;
 constexpr unsigned int aliens_columns = 12;
 constexpr float playerspeed = 350.f;
//static int aliensnum = aliens_columns * aliens_rows;
extern std::vector<Ship*> ships;
extern sf::Texture spritesheet;
extern Player* player;
//static unsigned char bulletPointer = 0;
//static Bullet bullets[256];
 const Keyboard::Key controls[3] = {
    Keyboard::A,   // left
    Keyboard::D,   // right
    Keyboard::Space
};