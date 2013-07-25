#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofEnableSmoothing();
    ofSetVerticalSync(true);
    
    touch = new Touch(3333);
//    testContainer = new Container();
    home = new HomeContainer();
    
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
    home->draw();
    touch->draw();
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