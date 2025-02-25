#pragma once

#include "ofMain.h"

#include "settings.h"
#include "connection.h"
#include "touch.h"

#include "container.h"
#include "homeContainer.h"

class testApp : public ofBaseApp{

	public:
		void setup();
        void end();
		void update();
		void draw();
        void drawAttract();
    
		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        ofVideoPlayer * attract;
    
        Touch * touch;
        WaitTimeBar * waitTime;
        Container * testContainer;
        HomeContainer * home;
        ofImage * mainBackground;
        float fade;
        bool debug;
        ofxXmlSettings XML;
};
