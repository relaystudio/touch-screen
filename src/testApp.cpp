#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetLogLevel(OF_LOG_NOTICE);
    ofEnableSmoothing();
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    
    ofHideCursor();
    
    touch = new Touch(3333);
//    testContainer = new Container();
    home = new HomeContainer();
    
    mainBackground = new ofImage();
    mainBackground->loadImage("img/main_bg.jpg");
//    
//    box2d = home->getBox2d();
//
    attract = new ofVideoPlayer();
    attract->loadMovie("img/attract.mov");
    attract->setLoopState(OF_LOOP_NORMAL);
    attract->play();
    fade = 0.f;
}


void testApp::end() {
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    touch->update();
    home->update();
}

//--------------------------------------------------------------
void testApp::draw(){
    mainBackground->draw(0,0,ofGetWidth(),ofGetHeight());
    home->draw();
    touch->draw();
    drawAttract();
}

void testApp::drawAttract() {
    ofPushStyle();
    //ofLog() << "touch: " << touch->getLastMoved() << "cur: " << ofGetUnixTime()-1000;
    if(touch->getLastMoved() < ofGetUnixTime()-10) {
        attract->update();
        //ofLog() << "Attract mode on!";
        if(fade <= 1.0f) fade += 0.05;
        ofSetColor(255,255,255, ofMap(fade,0,1,0,255));
        attract->draw(0,0,ofGetWidth(), ofGetHeight());
    } else {
        fade = 0;
        attract->setFrame(0);
    }
    ofPopStyle();
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
///////////////////////// Event management /////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'f')
        ofGetWindowMode() != OF_FULLSCREEN ? ofSetFullscreen(true) : ofSetFullscreen(false);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}