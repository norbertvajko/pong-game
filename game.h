#pragma once

#include <SFML/Graphics.hpp>
#include "paddle.h"
#include "ball.h"


class Game 
{

private:

// Window variables
int window_width;
int window_height;
std::string window_title;
int fps;
sf::RenderWindow *window;

sf::Event even;

//Paddle
Paddle *player;

//Ball
Ball *circle;


//Initialization
void initWindow();
void initCircle();
void initPaddle();


public:

//Const / Destr
Game();
~Game();

//Functions
bool running = false;
void pollEvents();
void update();
void render();

};