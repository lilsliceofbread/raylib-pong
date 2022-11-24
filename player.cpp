#include <raylib.h>
#include "player.hpp"

Player::Player(int startX, bool controlType) /*: ball(ball_)*/ {
    winWidth = GetScreenWidth();
    winHeight = GetScreenHeight();

    controls = controlType;

    x = startX;
    y = winHeight/2;

    yVel = 0;

    paddleWidth = 12;
    paddleHeight = winHeight/8;

    //hitbox from height and width
    Player::paddleBox = {
        (float)(x - paddleWidth), (float)(y - paddleHeight),
        (float)paddleWidth*2, (float)paddleHeight*2
    };
}

void Player::update() { 
    //check inputs
    if(IsKeyDown(controls ? KEY_UP : 87)) {
        yVel = -8; //up
    } else if(IsKeyDown(controls ? KEY_DOWN : 83)) {
        yVel = 8; //down
    } else {
        yVel = 0;
    }
    y = y + yVel; //update y

    //constrain between scr height
    if(y - paddleHeight/2 < 0) {
        y = paddleHeight/2;
    } else if(y + paddleHeight/2 > winHeight) {
        y = winHeight - paddleHeight/2;
    }

    //update hitbox
    Player::paddleBox = {
        (float)(x - paddleWidth/2), (float)(y - paddleHeight/2),
        (float)paddleWidth, (float)paddleHeight
    };
}

bool Player::checkCollisions(Vector2 ballPos) {
    if(CheckCollisionCircleRec(ballPos, 10.0f, paddleBox)) {
        return true;
    } else {
        return false;
    }
}

void Player::draw() {
    DrawRectangleRec(paddleBox, RAYWHITE);
}