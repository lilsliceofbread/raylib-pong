#include <raylib.h>
#include <stdlib.h> //rounding
#include <time.h> //for round
#include <cmath> //round
#include "ball.hpp"

int randomSign() {
    srand(time(NULL));
    if(rand() % 10 <= 5) {
        return -1;
    } else {
        return 1;
    }
}

Ball::Ball() {
    m_ballRadius = 10.0f;

    m_winWidth = GetScreenWidth(); //if initialised before screen is created it is null
    m_winHeight = GetScreenHeight();

    leftScore = 0;
    rightScore = 0;

    int minVel = std::floor(m_winHeight/100);
    m_x = m_winWidth/2;
    m_y = m_winHeight/2;

    srand(time(NULL));
    m_xVel = rand() % 3 + minVel * randomSign(); 
    m_yVel = rand() % 3 + minVel * randomSign();
}

void Ball::update() {

    if(m_x <= 0) { //left - score for right
        rightScore++;
        m_xVel = m_xVel * -1;
        reset();
    } else if(m_x >= m_winWidth) { //right - score for left
        leftScore++;
        m_xVel = m_xVel * -1;
        reset();
    } else if(m_y <= 0) { //up
        m_y = (int)m_ballRadius;
        m_yVel = m_yVel * -1;
    } else if(m_y >= m_winHeight) { //down
        m_y = m_winHeight - (int)m_ballRadius;
        m_yVel = m_yVel * -1;
    }

    m_x = m_x + m_xVel;
    m_y = m_y + m_yVel;

}

void Ball::draw() {
    DrawCircle(m_x, m_y, m_ballRadius, RAYWHITE);
}

void Ball::bounce() {
    m_xVel = m_xVel * -1;
    //resets m_x - bad but works
    if(m_x > m_winWidth/2) {
        m_x = (m_winWidth - m_winWidth/20) - 12; //left side of right paddle
    } else {
        m_x = m_winWidth/20 + 12; //right side of left paddle
    }
}

void Ball::reset() {
    m_x = m_winWidth/2;
    m_y = m_winHeight/2;
}

Vector2 Ball::getPos() {
    Vector2 pos = {
        (float)m_x, (float)m_y
    };
    return pos;
}