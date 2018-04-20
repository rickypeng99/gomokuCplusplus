#include "ofMain.h"
#include "gomoku.h"

//========================================================================
int main( ){
	ofSetupOpenGL(765,765,OF_WINDOW);			// <-------- setup the GL context
    ofSetBackgroundAuto(false);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new gomoku());


}
