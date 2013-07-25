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
    
    
}

HomeIcon::~HomeIcon() {
    
}

void HomeIcon::draw() {
    if(!isBody()) return;
	
	ofPushMatrix();
	ofTranslate(getPosition().x, getPosition().y, 0);
	ofRotate(getRotation(), 0, 0, 1);
	ofCircle(0, 0, 10);
	
	ofLine(0, 0, 30, 0);
    if(isSleeping()) {
        ofSetColor(255, 100);
        ofCircle(0, 0, radius);
    }
    ofPopStyle();
    
	ofPopMatrix();
}

void HomeIcon::update() {
    
}

bool HomeIcon::isActive() {
    // CHECK
    return true;
}

int HomeIcon::fetchTimer() {
    // To
    return 0;
}