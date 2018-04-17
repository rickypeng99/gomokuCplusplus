#include "ofApp.h"

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
    current_draw = BLACK;
    drawRecord();
    if (current_draw == BLACK) {
        ofSetColor(0, 0, 0);
        ofDrawCircle(xPos, yPos, 10);
        records.push_back(make_tuple(xPos, yPos, 0));
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
    if (button == 0 || isIntersection(xPos, yPos)) {
        xPos = x;
        yPos = y;
        update();
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
            ofDrawCircle(x, y, 10);
        }
    }
}



Boolean ofApp::isIntersection(int x, int y) {
    if (x == 0 || y == 0) {
        return false;
    }
    return ((x % (ofGetWindowWidth() / 15) == 0) && (y % (ofGetWindowHeight() / 15) == 0));
}
