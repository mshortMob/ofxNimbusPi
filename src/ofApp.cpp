#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for (unsigned int i =0; i<4; i++){
        vidsList[i].load("videos/vid" + ofToString(i) + ".mp4");
    }
    for (unsigned int i =0; i<NUM_WARP_OBJECTS; i++){
        warpObjects[i].setup(0);
    }
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (unsigned int i =0; i<NUM_WARP_OBJECTS; i++){
        warpObjects[i].update();
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    for (unsigned int i =0; i<NUM_WARP_OBJECTS; i++){
        warpObjects[i].draw();
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  bool bDeactivateOthers = false;
    switch (key) {
        case '1':
            // std::cout << "value: " << 11111 << endl;
            warpObjects[0].warper.activate();
            warpObjects[1].warper.deactivate();
            break;
        case '2':
            warpObjects[1].warper.activate();
            warpObjects[0].warper.deactivate();
            break;
        case '3':
            warpObjects[1].warper.deactivate();
            warpObjects[0].warper.deactivate();
            break;
        case 'f':
            for (unsigned int i =0; i<NUM_WARP_OBJECTS; i++){
                if(warpObjects[i].warper.isActive()){
                    warpObjects[i].changeVideo();
                }
            }
            break;
        case 'v':
            for (unsigned int i =0; i<NUM_WARP_OBJECTS; i++){
                if(warpObjects[i].warper.isActive()){
                    warpObjects[i].toggleVisible();
                }
            }
            break;
        case 'm':
            for (unsigned int i =0; i<NUM_WARP_OBJECTS; i++){
                if(warpObjects[i].warper.isActive()){
                    warpObjects[i].changeMask();
                }
            }
            break;
        case ',':
            for (unsigned int i =0; i<NUM_WARP_OBJECTS; i++){
                if(warpObjects[i].warper.isActive()){
                    warpObjects[i].warper.selectCorner(ofxGLWarper::TOP_LEFT);
                }
            }
            break;
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){}
//--------------------------------------------------------------
void ofApp::mouseReleased(){}