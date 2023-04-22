
class Ball {
    private:
        int m_winWidth;
        int m_winHeight;

        int m_x;
        int m_y;
        int m_xVel;
        int m_yVel;
        float m_ballRadius;

    public:
        int leftScore;
        int rightScore;

        Ball();
        void update();
        void draw();
        void bounce(); //bounce ball from paddle
        void reset();
        Vector2 getPos();
};