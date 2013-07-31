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
    origin = getPosition();
    wasActivated= false;
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
    ofDrawBitmapString( wasActivated ? "Is Active" : "Is Not Active"	, ofPoint(0,0));
    ofPopStyle();
    ofPopStyle();
	ofPopMatrix();
}

void HomeIcon::update(ofxBox2d * world) {
    if(world->mouseJoint && body->GetJointList() != NULL) {
        origin = getPosition();
    }
    else if (!body->GetJointList()->other) {
        touchDistance = getPosition().squareDistance(origin);
    }
    
    if(touchDistance > touchThreshold && touchTimer > 0) {
        wasActivated = true;
        touchTimer = touchDistance = 0;
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