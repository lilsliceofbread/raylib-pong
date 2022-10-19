#include <raylib.h>
#include <player.h>
#include <ball.h>

Player::Player(int startX) {

    winWidth = GetScreenWidth();
    winHeight = GetScreenHeight();

    x = startX;
    y = winHeight/2;

    paddleWidth = 20;
    paddleHeight = winHeight/40;

}

void Player::update(Ball& ball, bool upOrDown) {

    Vector2 ballPos = ball.getPos();
    if(CheckCollisionCircleRec(ballPos, 10.0f, paddleBox)) {
        ball.bounce();
        score++;
    }    
    //checkCollisions() (first or last?)
    //move player based on upOrDown - constrain to win size
    //update rectangle hitbox

}

void Player::draw() {
    DrawRectangleRec(paddleBox, RAYWHITE);
}

int Player::getScore() {
    return score;
}