#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include <ball.h>
#include <cmath>

//add check for goal

Ball::Ball(int scrWidth, int scrHeight) {

    ballRadius = 10.0f;

    winWidth = scrWidth;
    winHeight = scrHeight;

    int minVel = std::floor();
    x = winWidth/2;
    y = winHeight/2;

    srand(time(NULL));
    xVel = rand() % 10 + minVel;
    yVel = rand() % 10 + minVel;

}

void Ball::update() {

    //invert velocity when hitting edges
    //ensure ball does not exceed edges and bounce in and out
    if(x < 0) {
        x = 0 + (int)ballRadius;
        xVel = xVel * -1;
    } else if(x > winHeight) {
        x = winHeight;
        xVel = xVel * -1;
    } else if(y < 0) {
        y = 0;
        yVel = yVel * -1;
    } else if(y > winWidth) {
        x = winWidth;
        yVel = yVel * -1;
    }

    x = x + xVel;
    y = y + yVel;

}

void Ball::draw() {
    DrawCircle(x, y, ballRadius, BLUE);
}