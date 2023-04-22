
class Player {
    private:
        int m_winWidth;
        int m_winHeight;

        //center x and y, must calculate these for top corner
        int m_x;
        int m_y;
        int m_yVel;

        KeyboardKey m_up;
        KeyboardKey m_down;

        //from center
        int m_paddleWidth; 
        int m_paddleHeight;
        Rectangle m_paddleBox;

    public:
        Player(int startX, bool controlType);
        void update();
        void draw();
        int getScore();
        bool checkCollisions(Vector2 ballPos);
};