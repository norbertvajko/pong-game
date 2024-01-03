#include "game.h"
#include "game.cpp"
#include "paddle.h"
#include "paddle.cpp"
#include "ball.h"
#include "ball.cpp"


int main()
{ 
    Game pong;

    while (pong.running)
    {
        pong.update();
        pong.render();
    }
}