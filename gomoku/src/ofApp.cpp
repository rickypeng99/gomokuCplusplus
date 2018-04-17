#include "ofApp.h"
#include <math.h>
//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundColor(182, 155, 76);
    intersection.r = 169;
    intersection.g = 169;
    intersection.b = 169;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    drawBoard();
    drawRecord();
    if (current_draw == BLACK) {
        ofSetColor(0, 0, 0);
        ofDrawCircle(xPos, yPos, 25);
        records.push_back(make_tuple(xPos, yPos, 0));
    } else if (current_draw == WHITE) {
        ofSetColor(255, 255, 255);
        ofDrawCircle(xPos, yPos, 25);
        records.push_back(make_tuple(xPos, yPos, 1));
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int upper_key = toupper(key);
    if (upper_key == 'W') {
        should_update = true;
        update();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (button == 0) {
        if (autoDraw(x, y)) {
            update();
            changeTurn();
        }
    }


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

void ofApp::drawBoard(){
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

void ofApp::drawRecord(){
    for (int i = 0; i < records.size(); i++) {
        int x = std::get<0>(records.at(i));
        int y = std::get<1>(records.at(i));
        if (std::get<2>(records.at(i)) == 0) {
            ofSetColor(0, 0, 0);
            ofDrawCircle(x, y, 25);
        } else if (std::get<2>(records.at(i)) == 1) {
            ofSetColor(255, 255, 255);
            ofDrawCircle(x, y, 25);
        }
    }
}



Boolean ofApp::isIntersection(int x, int y) {
    if (x == 0 || y == 0) {
        return false;
    }
    return ((x % (ofGetWindowWidth() / 15) == 0) && (y % (ofGetWindowHeight() / 15) == 0));
}

Boolean ofApp::autoDraw(int x, int y) {
    for (int xp = 0; xp < ofGetWindowWidth(); xp++) {
        for (int yp = 0; yp < ofGetWindowHeight(); yp++) {
            if (isIntersection(xp, yp) && (sqrt(pow((xp - x), 2) + pow((yp-y), 2))) <= 5){
                xPos = xp;
                yPos = yp;
                return true;
            }
        }
    }
    return false;
}

void ofApp::changeTurn() {
    if (current_draw == BLACK) {
        current_draw = WHITE;
    } else {
        current_draw = BLACK;
    }
}
