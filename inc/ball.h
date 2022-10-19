
class Ball {

    int winWidth;
    int winHeight;

    int x;
    int y;
    int xVel;
    int yVel;
    float ballRadius;
    

    public:
        Ball();
        void update();
        void draw();
        void bounce(); //bounce ball from paddle
        Vector2 getPos();
};