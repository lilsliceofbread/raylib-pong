#include <raylib.h>
#include <stdlib.h> //rounding
#include <time.h> //for round
#include <iostream> //only for testing
#include <cmath> //round
#include <algorithm> //clamp?

#include <ball.h>

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

    winWidth = GetScreenWidth();
    winHeight = GetScreenHeight();

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
    if(x < 0) {
        x = (int)ballRadius;
        xVel = xVel * -1;
    } else if(x > winWidth) {
        x = winWidth - (int)ballRadius;
        xVel = xVel * -1;
    } else if(y < 0) {
        y = (int)ballRadius;
        yVel = yVel * -1;
    } else if(y > winHeight) {
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
    //reset x through param of which side?
    xVel = xVel * -1;
}

Vector2 Ball::getPos() {
    Vector2 pos = {
        (float)x, (float)y
    };
    return pos;
}