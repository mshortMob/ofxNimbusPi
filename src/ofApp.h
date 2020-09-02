#pragma once

#include "ofMain.h"
#include "warpObject.h"

#define NUM_WARP_OBJECTS 2

class ofApp : public ofBaseApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();

		warpObject warpObjects[NUM_WARP_OBJECTS];
		ofVideoPlayer vidsList[4];
        // ofXml XML;
		// ofFbo mask;
    	// int activeWarper;
};