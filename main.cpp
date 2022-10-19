#include <raylib.h>
#include <player.h>
#include <ball.h>

//add paddle speed to ball speed?
//game states?

int main() {

    const int scrWidth = 1280;
    const int scrHeight = 720;

    //for dashed line
    const int boxWidth = 10;
    const int boxHeight = 50;
    const int dashSpace = 22;

    bool playerLeftControl;
    bool playerRightControl;

    Player playerLeft(scrWidth/20);
    Player playerRight(scrWidth - scrWidth/20);

    Ball ball;

    InitWindow(scrWidth, scrHeight, "Pong");

    SetTargetFPS(60);
    while(!WindowShouldClose()) {

        ClearBackground(BLACK);

        //get inputs w/s up/down arrow
        //change bools based on that

        ball.update();
        playerLeft.update(ball, playerLeftControl); 
        playerRight.update(ball, playerRightControl);
        //Player.getScore()

        BeginDrawing();

            for(int i = 0; i * (boxHeight + dashSpace) <= scrHeight - boxHeight; i++) {
                DrawRectangle(scrWidth/2 - boxWidth/2, i * (boxHeight + dashSpace), boxWidth, boxHeight, GRAY); //make middle dashed line
            }

            //draw score

            ball.draw();
            playerLeft.draw();
            playerRight.draw();

        EndDrawing();

    }

    CloseWindow();
    return 0;

}