//
//  touch.cpp
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-19.
//
//

#include "touch.h"

Touch::Touch(int _port) {
    ofLog() << "Starting Tuio Client";
    tuioClient.start(_port);
    
    ofAddListener(tuioClient.cursorAdded,this,&Touch::tuioAdded);
	ofAddListener(tuioClient.cursorRemoved,this,&Touch::tuioRemoved);
	ofAddListener(tuioClient.cursorUpdated,this,&Touch::tuioUpdated);
    
  //  ofRegisterTouchEvents(this);
    lastMoved = ofGetUnixTime();
}

Touch::Touch() {
    Touch(3333);
}

Touch::~Touch() {
    
}

void Touch::update() {
    tuioClient.getMessage();
}

void Touch::draw() {
    tuioClient.drawCursors();
}

vector<ofPoint> * Touch::getPoints() {
    vector<ofxTuioCursor*> cursor(tuioClient.getTuioCursors().begin(), tuioClient.getTuioCursors().end());
    pnt.clear();
    for(size_t i=0;i<cursor.size();i++) {
        pnt.push_back(ofPoint(cursor.at(i)->getX(), cursor.at(i)->getY()));
    }
    return &pnt;
}

ofPoint * Touch::getPoint() {
	return new ofPoint();
}

long Touch::getLastMoved() {
    return lastMoved;
}

/////////////////////////////////////////////////////////////////
/////////////   Event management    /////////////////////////////
/////////////////////////////////////////////////////////////////
void Touch::tuioAdded(ofxTuioCursor &tuioCursor){
    ofPoint loc = ofPoint(tuioCursor.getX()*ofGetWidth(),tuioCursor.getY()*ofGetHeight());
	ofLog(OF_LOG_VERBOSE) << "Point n" << tuioCursor.getSessionId() << " add at " << loc << endl;
    ofNotifyMousePressed(loc.x, loc.y, 0);
}

void Touch::tuioUpdated(ofxTuioCursor &tuioCursor){
    ofPoint loc = ofPoint(tuioCursor.getX()*ofGetWidth(),tuioCursor.getY()*ofGetHeight());
    ofLog(OF_LOG_VERBOSE) << "Point n" << tuioCursor.getSessionId() << " updated at " << loc << endl;
     ofNotifyMouseDragged(loc.x, loc.y, 0);
    lastMoved = ofGetUnixTime();
}

void Touch::tuioRemoved(ofxTuioCursor &tuioCursor){
    ofPoint loc = ofPoint(tuioCursor.getX()*ofGetWidth(),tuioCursor.getY()*ofGetHeight());
    ofLog(OF_LOG_VERBOSE) << "Point n" << tuioCursor.getSessionId() << " remove at " << loc << endl;
     ofNotifyMouseReleased(loc.x, loc.y, 0);
}