#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "paddle.h"



class Ball :public Paddle 
{
   protected:
    //Ball variables
    sf::CircleShape circle;


    private:
    //Ball position
    sf::Vector2f bPosition;

    //Ball steps
    float xStep;
    float yStep;
        
    public:

    //Initialization
    void initBall();
    
    //Ctors / Dtors
    Ball();
    ~Ball();
    
    //Functions
    void ballMove();
    void ballWindowCollision();
    
    bool checkballPaddleCollision();


    //math alg for collision
    float clamp(float value , float minn , float maxx);
    int checkCollision(sf::RectangleShape &R1 , sf::CircleShape &C1);

    void updateCollision(sf::RectangleShape &R1 , sf::CircleShape &C1);

    void update();
    void render(sf::RenderTarget *target);

};