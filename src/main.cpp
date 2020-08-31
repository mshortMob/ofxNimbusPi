#include "ofApp.h"
#include "ofMain.h"

//========================================================================
int main( ){

	ofSetupOpenGL(852,480, OF_FULLSCREEN);			// <-------- setup the GL context
	
	ofRunApp(new ofApp());
	
}