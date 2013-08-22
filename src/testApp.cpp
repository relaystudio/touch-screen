#include "testApp.h"

#define NO_INTERACT_DURATION 60 //Attract mode interaction in s - expose to settings.xml

//--------------------------------------------------------------
void testApp::setup(){
    ofSetLogLevel(OF_LOG_NOTICE);
    
    if(XML.loadFile("settings.xml")) ofLog() << "Loaded Settings successfully.";
    XML.pushTag("xml");
    debug = XML.getValue("debug",0) == 1 ? true : false;
    if(XML.pushTag(XML.getValue("Orientation","horizontal"))) ofLog() << "Correctly set orientation";
    ofSetWindowShape(XML.getValue("width", 1920), XML.getValue("height", 1080));
    
    ofEnableSmoothing();
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    
    ofHideCursor();
    waitTime = new WaitTimeBar();
    touch = new Touch(3333);
//    testContainer = new Container();
    home = new HomeContainer();
    
    mainBackground = new ofImage();
    mainBackground->loadImage("img/main_bg.jpg");
//    
//    box2d = home->getBox2d();
//
    attract = new ofVideoPlayer();
    attract->loadMovie(XML.getValue("attractPath", "img/attract.mov"));
    attract->setLoopState(OF_LOOP_NORMAL);
    attract->play();
    fade = 0.f;
    
    XML.popTag();
    
}


void testApp::end() {
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    touch->update();
    home->update();
    waitTime->update();
}

//--------------------------------------------------------------
void testApp::draw(){
    mainBackground->draw(0,0,ofGetWidth(),ofGetHeight());
    home->draw();
    if(debug) touch->draw();
    drawAttract();
}

void testApp::drawAttract() {
    ofPushStyle();
    ofLog() << "touch: " << touch->getLastMoved() << "cur: " << ofGetUnixTime()-10;
	if(touch->getLastMoved() < ofGetUnixTime() - XML.getValue("attractLength", 60)) {
        attract->update();
        //ofLog() << "Attract mode on!";
        if(fade <= 1.0f) fade += 0.05;
        ofSetColor(255,255,255, ofMap(fade,0,1,0,255));
        attract->draw(0,0,ofGetWidth(), ofGetHeight());
        ofSetColor(255,127,127, ofMap(fade,0,1,0,255));
        waitTime->drawRed();
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