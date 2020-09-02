#include "warpObject.h"
warpObject::warpObject(){

}

void warpObject::setup(int vidNum){
    maskNumber=0;
    vidNumber=vidNum;
    visible=true;
    vid.load("videos/vid" + ofToString(vidNumber) + ".mp4");
    vid.play();
    warper.setup(vid.getWidth(),vid.getHeight(),vid.getWidth(), vid.getHeight());

	mask.allocate( vid.getWidth(), vid.getHeight() ) ;
    drawMaskNone( vid.getWidth(), vid.getHeight() ) ;
    vid.getTexture().setAlphaMask( mask.getTexture() );
}

void warpObject::update(){
    vid.update();
}

void warpObject::draw(){
    warper.begin();
    vid.draw(vid.getWidth(),vid.getHeight());
    warper.end();
}

void warpObject::changeVideo(){
    vidNumber=(vidNumber+1)%4;
    vid.close();
    vid.load("videos/vid" + ofToString(vidNumber) + ".mp4");
    vid.play();
}

void warpObject::changeMask(){
    float w = vid.getWidth() ;
	float h = vid.getHeight() ;
    if(maskNumber==0){
        maskNumber=1;
        drawMaskCircle( vid.getWidth(), vid.getHeight() ) ;
    }else{
        maskNumber=0;
        drawMaskNone( vid.getWidth(), vid.getHeight() ) ;
    }
}

void warpObject::drawMaskCircle(float w, float h){
    mask.begin() ;
    ofClear( 0.f, 0.f ) ;
    ofDrawCircle( w / 2.f, h / 2.f, h / 2.f ) ;
    mask.end() ;
}

void warpObject::drawMaskNone(float w, float h){
    mask.begin() ;
    ofClear( 0.f, 0.f ) ;
    ofDrawRectangle(0.f, 0.f, w/1.f, h/1.f ) ;
    mask.end() ;
}

void warpObject::toggleVisible(){
    visible=!visible;
    if(visible){
        vid.load("videos/vid" + ofToString(vidNumber) + ".mp4");
        vid.play();
    }else{
        vid.close();
    }
}