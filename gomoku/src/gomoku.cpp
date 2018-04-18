#include "gomoku.h"
#include <math.h>

//--------------------------------------------------------------
void gomoku::setup(){

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            board[i][j] = EMPTY;
        }
    }

    ofSetBackgroundColor(182, 155, 76);

    intersection.r = 169;
    intersection.g = 169;
    intersection.b = 169;
    
    current_draw = MAKE_BOARD;

}

//--------------------------------------------------------------
void gomoku::update(){

}

//--------------------------------------------------------------
void gomoku::draw(){
    drawBoard();
    drawRecord();
    
    if (current_draw == MAKE_BLACK) {
        ofSetColor(0, 0, 0);
        ofDrawCircle(xPos, yPos, 25);
        records.push_back(make_tuple(xPos, yPos, BLACK));
        board[xPos / 15][yPos / 15] = BLACK;
    } else if (current_draw == MAKE_WHITE) {
        ofSetColor(255, 255, 255);
        ofDrawCircle(xPos, yPos, 25);
        records.push_back(make_tuple(xPos, yPos, WHITE));
        board[xPos / 15][yPos / 15] = WHITE;

    }

}

//--------------------------------------------------------------
void gomoku::keyPressed(int key){
    
}

//--------------------------------------------------------------
void gomoku::keyReleased(int key){

}

//--------------------------------------------------------------
void gomoku::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void gomoku::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void gomoku::mousePressed(int x, int y, int button){
    if (button == 0) {
        if (autoDraw(x, y)) {

            update();
            changeTurn();


        }
    }


}

//--------------------------------------------------------------
void gomoku::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void gomoku::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void gomoku::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void gomoku::windowResized(int w, int h){

}

//--------------------------------------------------------------
void gomoku::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void gomoku::dragEvent(ofDragInfo dragInfo){

}

void gomoku::drawBoard(){
    for (int y = 0; y < ofGetWindowHeight(); y += ofGetWindowHeight()/15) {
        ofSetColor(0, 0, 0);
        ofDrawLine(0, y, ofGetWindowWidth() , y);
    }

    for (int x = 0; x < ofGetWindowWidth(); x+=ofGetWindowWidth()/15) {
        ofSetColor(0, 0, 0);
        ofDrawLine(x, 0, x , ofGetWindowHeight());
    }

    for (int x = 0; x < ofGetWindowWidth(); x++) {
        for (int y = 0; y < ofGetWindowHeight(); y++) {
            if (isIntersection(x, y)){
                ofSetColor(intersection);
                ofDrawCircle(x, y, 5);
            }
        }
    }
}

void gomoku::drawRecord(){
    for (int i = 0; i < records.size(); i++) {
        int x = std::get<0>(records.at(i));
        int y = std::get<1>(records.at(i));
        if (std::get<2>(records.at(i)) == BLACK) {
            ofSetColor(0, 0, 0);
            ofDrawCircle(x, y, 25);
        } else if (std::get<2>(records.at(i)) == WHITE) {
            ofSetColor(255, 255, 255);
            ofDrawCircle(x, y, 25);
        }
    }
}



Boolean gomoku::isIntersection(int x, int y) {
    if (x == 0 || y == 0) {
        return false;
    }
    return ((x % (ofGetWindowWidth() / 15) == 0) && (y % (ofGetWindowHeight() / 15) == 0));
}

Boolean gomoku::autoDraw(int x, int y) {
    for (int xp = 0; xp < ofGetWindowWidth(); xp++) {
        for (int yp = 0; yp < ofGetWindowHeight(); yp++) {
            if (isIntersection(xp, yp) && (sqrt(pow((xp - x), 2) + pow((yp-y), 2))) <= 5){
                xPos = xp;
                yPos = yp;
                if (board[xPos / 15][yPos / 15] == EMPTY) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
    return false;
}

void gomoku::changeTurn() {
    if (current_draw == MAKE_BLACK) {
        current_draw = MAKE_WHITE;
    } else {
        current_draw = MAKE_BLACK;
    }
}

void gomoku::printBoard() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}
