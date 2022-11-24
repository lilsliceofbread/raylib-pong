
class Player {
    private:
        int winWidth;
        int winHeight;

        //center x and y, must calculate these for top corner
        int x;
        int y;
        int yVel;

        KeyboardKey m_up;
        KeyboardKey m_down;

        //from center
        int paddleWidth; 
        int paddleHeight;
        Rectangle paddleBox;

    public:
        Player(int startX, bool controlType);
        void update();
        void draw();
        int getScore();
        bool checkCollisions(Vector2 ballPos);
};