#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    xPos = 100;
    yPos = 100;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (should_update){
        xPos += 5;
        yPos += 5;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0);
    ofDrawCircle(10, realY(10), 10);
    
    ofSetColor(0, 0, 0);
    ofDrawCircle(300, realY(300), 10);
    //ofDrawLine(xPos, yPos, 100, 100);

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

int ofApp::realY(int y) {
    return ofGetWindowHeight() - 1 - y;
}

