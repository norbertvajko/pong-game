#pragma once

#include "SFML/Graphics.hpp"

class Paddle 
{
    protected:
    //Paddle variables
    sf::RectangleShape paddle;

    private:
    //Paddle position
    sf::Vector2f pPosition;
    
    //Paddle size
    sf::Vector2f pSize;


    //Paddle moveSpeed
    float moveSpeed;

    //Initialization
    void initPaddle();


    public:
    
    //Ctors / Dtors
    Paddle();
    ~Paddle();

    //Functions
    void updateInput();
    void updateWindowColision(sf::RenderTarget *target);
    void update(sf::RenderTarget *target);
    void render(sf::RenderTarget *target);

};