
class Ball {

    float ballRadius;
    int x;
    int y;
    int xVel;
    int yVel;
    int winWidth;
    int winHeight;

    public:
        Ball(int scrWidth, int scrHeight);
        void update();
        void draw();

};