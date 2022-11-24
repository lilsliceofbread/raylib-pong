#include <raylib.h>
#include "player.hpp"

Player::Player(int startX, bool controlType) /*: ball(ball_)*/ {
    winWidth = GetScreenWidth();
    winHeight = GetScreenHeight();

    //sets up and down keys
    m_up = controlType ? KEY_UP : KEY_W;
    m_down = controlType ? KEY_DOWN : KEY_S;

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
    if(IsKeyDown(m_up)) {
        yVel = -8; //up
    } else if(IsKeyDown(m_down)) {
        yVel = 8; //down
    } else {
        yVel = 0; //stop if no key pressed
    }
    y = y + yVel; //update y

    //constrain within window
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
    return CheckCollisionCircleRec(ballPos, 10.0f, paddleBox);
}

void Player::draw() {
    DrawRectangleRec(paddleBox, RAYWHITE);
}