#include <string>
#include <iostream>
#include <raylib.h>
#include "player.hpp"
#include "ball.hpp"

int main() {

    const int scrWidth = 1600;
    const int scrHeight = 900;

    //for dashed line
    const int boxWidth = 10;  //10
    const int boxHeight = 40; //50
    const int dashSpace = 20; //22

    std::string tempStrL;
    std::string tempStrR;
    

    Vector2 ballPos;

    InitWindow(scrWidth, scrHeight, "Pong");

    Ball *ball = new Ball();
    
    //choose player controls in 
    Player *playerLeft = new Player(scrWidth/20, false);
    Player *playerRight = new Player(scrWidth - scrWidth/20, true);

    ballPos = ball->getPos();

    SetTargetFPS(60);
    while(!WindowShouldClose()) {

        ClearBackground(BLACK);

        ball->update();
        playerLeft->update(); 
        playerRight->update();

        ballPos = ball->getPos();
        if(playerLeft->checkCollisions(ballPos) || playerRight->checkCollisions(ballPos)) {
            ball->bounce();
        }

        tempStrL = std::to_string(ball->leftScore);
        tempStrR = std::to_string(ball->rightScore);
        const char *c_leftScore = tempStrL.c_str();
        const char *c_rightScore = tempStrR.c_str();

        BeginDrawing();

            //make middle dashed line
            for(int i = 0; i * (boxHeight + dashSpace) <= scrHeight - boxHeight; i++) {
                DrawRectangle(scrWidth/2 - boxWidth/2, i * (boxHeight + dashSpace), boxWidth, boxHeight, GRAY);
            }

            DrawText(c_leftScore, scrWidth/4, 50, 70, GRAY); 
            DrawText(c_rightScore, scrWidth - scrWidth/4, 50, 70, GRAY);

            ball->draw();
            playerLeft->draw();
            playerRight->draw();

        EndDrawing();

    }

    delete playerLeft;
    delete playerRight;
    delete ball;
    CloseWindow();
    return 0;

}