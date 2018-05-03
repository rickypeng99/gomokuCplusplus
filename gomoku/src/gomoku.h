#pragma once

#include "ofMain.h"

enum DrawType {
    MAKE_BLACK,
    MAKE_WHITE
};

enum GameState {
    CHOOSE,
    START,
    NO_PLACE,
    PLACE,
    END
};

enum PlayType{
    AI,
    VERSUS,
    UNDECIDED
};

enum renjuType {
    RIGHT,
    DOWN,
    DOWNRIGHT,
    DOWNLEFT
};

class gomoku : public ofBaseApp{

    public:

    //constant variables of go pieces
    const int EMPTY = 0;
    const int BLACK = 1;
    const int WHITE = 2;

    //board settings
    const int size = 15;
    int unit_width;
    int unit_height;
    int board[14][14];
    
    //useful global variables
    string winner;
    int xPos;
    int yPos;
    
    //enums initializations
    DrawType current_draw;
    GameState current_state;
    PlayType current_mode;
    
    //openframeworks objects
    ofColor intersection;
    ofSoundPlayer   mySound;



    // Methods to interact with the UI
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    // Methods that help the game functioning
    void changeTurn();
    void drawBoard();
    void drawRecord();
    Boolean isIntersection(int x, int y);
    Boolean autoDraw(int x, int y);
    Boolean isWin();
    Boolean should_update;
    
    
    //Methods that help testing
    void printBoard();
    void getWinnerName(int num);

    // AI related methods
    void robotMove(int x, int y);
    int evaluate(int x, int y);
    int evaluateWhite(int x, int y);
    Boolean checkFree(renjuType type , int renju, int i, int j);


};
