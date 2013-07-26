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
    
    radius = 20;
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