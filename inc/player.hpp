
class Player {
    private:
        int winWidth;
        int winHeight;

        //center x and y, must calculate these for top corner
        int x;
        int y;
        int yVel;

        //from center
        int paddleWidth; 
        int paddleHeight;
        Rectangle paddleBox;

    public:
        Player(int startX);
        void update();
        void draw();
        int getScore();
        bool checkCollisions(Vector2 ballPos);
};