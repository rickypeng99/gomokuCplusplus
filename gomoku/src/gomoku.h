#pragma once

#include "ofMain.h"
enum DrawType {
    MAKE_BLACK,
    MAKE_WHITE
};

enum GameState {
    START,
    NO_PLACE,
    PLACE,
    END
};

class gomoku : public ofBaseApp{

    public:

    const int EMPTY = 0;
    const int BLACK = 1;
    const int WHITE = 2;

    const int size = 15; // The size of the board, 15 means 15*15
    int unit_width;
    int unit_height;

    int board[14][14];
    
    DrawType current_draw;
    GameState current_state;
    ofColor intersection;

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

    void changeTurn();
    void drawBoard();
    void drawRecord();
    int xPos;
    int yPos;
    void printBoard();
    

    Boolean isIntersection(int x, int y);
    Boolean autoDraw(int x, int y);
    Boolean isWin();

    Boolean should_update;

    //std::tuple<int, int, int> dot;
    //vector<std::tuple<int, int, int>> records;
};
