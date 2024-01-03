#include "game.h"

//Initialization
//Init Window
void Game::initWindow()
{
   this -> window_width = 1200;
   this -> window_height = 800;
   this -> window_title = "PONG Game";
   this -> window = new sf::RenderWindow(sf::VideoMode(window_width , window_height) , window_title);
   this -> fps = 60;
   this -> window ->setFramerateLimit(fps);
   this -> window ->setVerticalSyncEnabled(true);
   this -> running = true;
}

//Init Circle ( with this function we can delete ball object)
void Game::initCircle()
 {
    this -> circle = new Ball();
 }

//Init Paddle ( with this function we can delete paddle object)
void Game::initPaddle()
{
    this -> player = new Paddle();
}

//Ctors / Dtors
Game::Game()
{
    this -> initWindow();    
    this -> initCircle();
    this -> initPaddle();
}

Game::~Game()
{
   delete this -> window;
   delete this -> circle;
   delete this -> player;
}

//Functions

////



void Game::pollEvents()
{
    while (this -> window->pollEvent(even))
    {
        if (this -> even.type == sf::Event::Closed) { this -> window -> close(); running = false; }
        
        //Escape button close
        if (this -> even.key.code == sf::Keyboard::Escape) { this -> window -> close(); running = false; }
        
        
    }
        
}

//Window update
void Game::update()
{
    this -> pollEvents();
    this -> player -> update(window);
    this -> circle -> update();
    
}

//Window render
void Game::render()
{   
    //Clear the window
    this -> window -> clear();

    //Draw objects
    this -> player -> render(this -> window);
    this -> circle -> render(this -> window);
    
    //Display window
    this -> window -> display();
}