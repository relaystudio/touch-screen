//
//  homeicon.cpp
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-17.
//
//

#include "homeicon.h"

HomeIcon::HomeIcon(string _title,
                   string _apiPath, string _iconPath) {
    title = _title;
    apiPath = _apiPath;
    iconPath = _iconPath;
    
    bg = new ofImage();
    bg->loadImage("img/icon_bg.png");
    
    ring = new ofImage();
    ring->loadImage("img/icon_time_fg.png");
    
    icon = new ofImage();
    icon->loadImage(iconPath);
    
    radius = 20;  // This isn't used for anything atm
    touchTimer = touchDistance = 0;
    origin = ofPoint(-1,-1);
    wasActivated = isActive = false;
}

HomeIcon::~HomeIcon() {
    
}

void HomeIcon::draw() {
    if(!isBody()) return;
	ofPushMatrix();
    ofPushStyle();
    ofEnableAlphaBlending();
    ofTranslate(getPosition().x-150, getPosition().y-150);
    bg->draw(0,0);
    ring->draw(0,0);
    icon->draw(0,0);
    ofPushStyle();
    ofSetColor(255,0,0);
    ofDrawBitmapString( body->GetJointList() ? "Being Touched" : "Kinda Lonely", ofPoint(0,0));
    ofPopStyle();
    ofPopStyle();
	ofPopMatrix();
}

void HomeIcon::update(ofxBox2d * world) {
    if(body->GetJointList()) {
        origin = getPosition();
        isActive = true;
    }
    else if (!body->GetJointList() && isActive) {
        touchDistance = getPosition().squareDistance(origin);
        ofLog() << title << " : " << touchDistance;
        isActive = false;
        
        if(touchDistance < touchThreshold) {
            wasActivated = true;
        }
    }
}

bool HomeIcon::isActivated() {
    if(wasActivated) {
        wasActivated = false;
        return true;
    }
    else return false;
}

int HomeIcon::fetchTimer() {
    // To
    return 0;
}