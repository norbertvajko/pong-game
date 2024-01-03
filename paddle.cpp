#include "paddle.h"

//Initialization
void Paddle::initPaddle()
{ 

    //Paddle position
    this -> pPosition.x = 500.0f; 
    this -> pPosition.y = 750.0f;
    this -> paddle.setPosition(pPosition);

    //Paddle size
    this -> pSize.x = 250.0f;
    this -> pSize.y = 50.0f;
    this -> paddle.setSize(pSize);

    //Paddle color
    this -> paddle.setFillColor(sf::Color::White);

    //Paddle moveSpeed
    this -> moveSpeed = 20.0f;

}

//Ctors / Dtors
Paddle::Paddle()
{
    this -> initPaddle();
}

Paddle::~Paddle()
{

}

//Keyboard input
void Paddle::updateInput()
{
    //Left 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this -> paddle.move( -this->moveSpeed , 0.f );
    }

    //Right
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this -> paddle.move( this->moveSpeed , 0.f );
    }

/*
    //Up
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this -> paddle.move( 0.f , -this -> moveSpeed );
    }

    //Down
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this -> paddle.move( 0.f , this -> moveSpeed );
    }
*/

}

//Paddle collision with screen
void Paddle::updateWindowColision(sf::RenderTarget *target)
{
    //Left collision w/screen
    if ( this -> paddle.getGlobalBounds().left < 0.f )
    this -> paddle.setPosition(0.f , this->paddle.getPosition().y);

    //Right collision w/screen
    else if( this -> paddle.getGlobalBounds().left + this -> paddle.getGlobalBounds().width > target -> getSize().x )
    this -> paddle.setPosition(target -> getSize().x - this -> paddle.getGlobalBounds().width , this -> paddle.getGlobalBounds().top);

/*   
    //Top
    if ( this -> paddle.getGlobalBounds().top < 0.f)
    this -> paddle.setPosition(this -> paddle.getGlobalBounds().left , 0.f);

    //Bottom
    else if ( this -> paddle.getGlobalBounds().top + this -> paddle.getGlobalBounds().height > target -> getSize().y)
    this -> paddle.setPosition(this -> paddle.getGlobalBounds().left , target -> getSize().y - this -> paddle.getGlobalBounds().height);

*/
    
}

//Functions
void Paddle::update(sf::RenderTarget *target)
{
    this -> updateInput();
    this -> updateWindowColision(target);
}

//Draw object
void Paddle::render(sf::RenderTarget *target)
{
   target->draw(this->paddle);
}

