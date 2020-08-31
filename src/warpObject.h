#ifndef _warpObject 
#define _warpObject 
#include "ofMain.h"
#include "ofxGLWarper.h"
class warpObject {

    public:

    void setup(int vidNum);
    void update();
    void draw();
    void changeVideo();
    void changeMask();
    void toggleVisible();

    int maskNumber;
    int vidNumber;
    bool visible;

	ofxGLWarper warper;
    ofVideoPlayer vid;
    ofFbo mask;

    warpObject();

    private:

    void drawMaskCircle(float w, float h);
    void drawMaskNone(float w, float h);
};
#endif