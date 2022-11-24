#include <raylib.h>
#include <stdlib.h> //rounding
#include <time.h> //for round
#include <cmath> //round
#include "ball.hpp"

//add check for goal

int randomSign() {
    srand(time(NULL));
    if(rand() % 10 <= 5) {
        return -1;
    } else {
        return 1;
    }
}

Ball::Ball() {
    ballRadius = 10.0f;

    winWidth = GetScreenWidth(); //if initialised before screen is created it is null
    winHeight = GetScreenHeight();

    leftScore = 0;
    rightScore = 0;

    int minVel = std::floor(winHeight/100);
    x = winWidth/2;
    y = winHeight/2;

    srand(time(NULL));
    xVel = rand() % 3 + minVel * randomSign(); //is this bad?
    yVel = rand() % 3 + minVel * randomSign();
}

void Ball::update() {

    //invert velocity when hitting edges
    //ensure ball does not exceed edges and bounce in and out
    //remove x later (change game state?)
    if(x <= 0) { //left - score for right
        rightScore++;
        xVel = xVel * -1;
        reset();
    } else if(x >= winWidth) { //right - score for left
        leftScore++;
        xVel = xVel * -1;
        reset();
    } else if(y <= 0) { //up
        y = (int)ballRadius;
        yVel = yVel * -1;
    } else if(y >= winHeight) { //down
        y = winHeight - (int)ballRadius;
        yVel = yVel * -1;
    }

    x = x + xVel;
    y = y + yVel;

}

void Ball::draw() {
    DrawCircle(x, y, ballRadius, RAYWHITE);
}

void Ball::bounce() {
    xVel = xVel * -1;
    //resets x - scuffed but it works
    if(x > winWidth/2) {
        x = (winWidth - winWidth/20) - 12; //left side of right paddle
    } else {
        x = winWidth/20 + 12; //right side of left paddle
    }
}

void Ball::reset() {
    x = winWidth/2;
    y = winHeight/2;
}

Vector2 Ball::getPos() {
    Vector2 pos = {
        (float)x, (float)y
    };
    return pos;
}