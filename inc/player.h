
class Player {

    int winWidth;
    int winHeight;

    int x;
    int y;
    int yVel;

    //from center
    int paddleWidth; 
    int paddleHeight;
    Rectangle paddleBox;

    int score;

    public:
        Player(int startX);
        void update(Ball& ball, bool upOrDown);
        void draw();
        int getScore();

};