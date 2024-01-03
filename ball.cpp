#include "ball.h"

//Initialization
void Ball::initBall()
{   
    //Ball position
    this -> bPosition.x = 600.0f;
    this -> bPosition.y = 270.0f;
    this -> circle.setPosition(bPosition);

    //Ball Radius
    this -> circle.setRadius(15.0f);

    //Ball Origin
    this -> circle.setOrigin(15.0f ,  15.0f);

    //Ball steps
    this -> xStep = 5.0f;
    this -> yStep = 5.0f;


    //Ball color
    this -> circle.setFillColor(sf::Color::Magenta);


}


//Ctors / Dtors
Ball::Ball()
{
    this -> initBall();
}

Ball::~Ball()
{
}

//Functions
//Ball move
void Ball::ballMove()
{    
     this -> circle.move(this -> xStep , this -> yStep);
}


//Ball collision with screen
void Ball::ballWindowCollision()
{    
    //Right window collision
     if ( this -> circle.getPosition().x > 1150)
     {  
        //set reverse speed
        this -> xStep = -7.0f;
        
        //set reverse color
       // this -> circle.setFillColor(sf::Color::Cyan);
     }
     //Left window collision
     else if ( this -> circle.getPosition().x < 0)
     {
        this -> xStep = 7.0f;
      //  this -> circle.setFillColor(sf::Color::Green);
     }
    //Bottom window colision
     if ( this -> circle.getPosition().y > 750)
    {
        this -> yStep = -7.0f;
       // this -> circle.setFillColor(sf::Color::Yellow);
    }
    
    //Top window collision 
    else if ( this -> circle.getPosition().y < 0)
     {
        this -> yStep = 7.0f;
       // this -> circle.setFillColor(sf::Color::Blue);
     }
}

//Check Ball collision with paddle
bool Ball::checkballPaddleCollision()
{
    return this -> circle.getGlobalBounds().intersects(paddle.getGlobalBounds() );
}

//Math ecc for ball collision
float Ball::clamp(float value , float minn , float maxx)
{
   if (value < minn)  return minn;
   else if (value > maxx)  return maxx;
   else return value;
}

//Ball collision with paddle
int Ball::checkCollision(sf::RectangleShape &R1 , sf::CircleShape &C1)
{
    /* **************************

     An INT function that takes in a Rectangle and a circle and returns:
     :3 -> if they hit at corner
     :2 -> if they hit on top or bottom
     :1 -> if they hit on the left or right
     :0 -> if they don't hit
     ****** MAKE SURE CIRCLE ORIGIN IS SET TO CENTER ******
      
    */ 

   //Find the closest point to the circle within the rectangle
   float closestX = clamp(C1.getPosition().x , R1.getPosition().x , R1.getPosition().x + R1.getSize().x );
   float closestY = clamp(C1.getPosition().y , R1.getPosition().y , R1.getPosition().y + R1.getSize().y );
   
   //Calculate the distance between the circle's center and this closest point
   float distanceX = C1.getPosition().x - closestX;
   float distanceY = C1.getPosition().y - closestY;

   //If the distance is less than the circle's radius , an intersection occurs
   float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);

   if (distanceSquared < C1.getRadius() * C1.getRadius() && closestX != C1.getPosition().x && closestY != C1.getPosition().y) { return 3; }
   else if ( distanceSquared < C1.getRadius() * C1.getRadius() && closestX == C1.getPosition().x ) { return 2; }
   else if ( distanceSquared < C1.getRadius() * C1.getRadius() && closestY == C1.getPosition().y ) { return 1; }
   else  { return 0; }
}

void Ball::updateCollision(sf::RectangleShape &R1 , sf::CircleShape &C1)
{
   
    if (checkCollision(this-> paddle, this-> circle) == 3)
   {
     this-> yStep = -yStep;
     this-> xStep = -xStep;
   }
   else if (checkCollision(this -> paddle, this -> circle) == 2)
   {
     this-> yStep = -yStep;
   }
   else if (checkCollision(this-> paddle, this -> circle) == 1)
   {
     this-> xStep = -xStep;
   }
}


//Ball update
void Ball::update()
{
   this -> ballMove();
   this -> ballWindowCollision();
   this -> updateCollision(this -> paddle , this -> circle);
}
//Ball render
void Ball::render(sf::RenderTarget *target)
{
   target -> draw(this->circle);
}


