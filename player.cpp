#include <raylib.h>
#include "player.hpp"

Player::Player(int startX, bool controlType)  {
    m_winWidth = GetScreenWidth();
    m_winHeight = GetScreenHeight();

    //sets up and down keys
    m_up = controlType ? KEY_UP : KEY_W;
    m_down = controlType ? KEY_DOWN : KEY_S;

    m_x = startX;
    m_y = m_winHeight/2;

    m_yVel = 0;

    m_paddleWidth = 12;
    m_paddleHeight = m_winHeight/8;

    //hitbox from height and width
    m_paddleBox = {
        (float)(m_x - m_paddleWidth), (float)(m_y - m_paddleHeight),
        (float)m_paddleWidth*2, (float)m_paddleHeight*2
    };
}

void Player::update() { 
    //check inputs
    if(IsKeyDown(m_up)) {
        m_yVel = -8; //up
    } else if(IsKeyDown(m_down)) {
        m_yVel = 8; //down
    } else {
        m_yVel = 0; //stop if no key pressed
    }
    m_y = m_y + m_yVel; //update y

    //constrain within window
    if(m_y - m_paddleHeight/2 < 0) {
        m_y = m_paddleHeight/2;
    } else if(m_y + m_paddleHeight/2 > m_winHeight) {
        m_y = m_winHeight - m_paddleHeight/2;
    }

    //update hitbox
    m_paddleBox = {
        (float)(m_x - m_paddleWidth/2), (float)(m_y - m_paddleHeight/2),
        (float)m_paddleWidth, (float)m_paddleHeight
    };
}

bool Player::checkCollisions(Vector2 ballPos) {
    return CheckCollisionCircleRec(ballPos, 10.0f, m_paddleBox);
}

void Player::draw() {
    DrawRectangleRec(m_paddleBox, RAYWHITE);
}