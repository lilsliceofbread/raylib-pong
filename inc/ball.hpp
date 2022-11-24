
class Ball {
    private:
        int winWidth;
        int winHeight;

        int x;
        int y;
        int xVel;
        int yVel;
        float ballRadius;

    public:
        int leftScore;
        int rightScore;

        Ball();
        void update();
        void draw();
        void bounce(); //bounce ball from paddle
        Vector2 getPos();
};