#pragma once

#include "ofMain.h"
enum DrawType {
    MAKE_BOARD,
    BLACK,
    WHITE
};

class ofApp : public ofBaseApp{


	public:

    DrawType current_draw = MAKE_BOARD;
    const int size = 15; // The size of the board, 15 means 15*15
    ofColor intersection;
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

    Boolean isIntersection(int x, int y);
    Boolean autoDraw(int x, int y);
    
    Boolean should_update;

    std::tuple<int, int, int> dot;
    vector<std::tuple<int, int, int>> records;
};
