//
//  homeicon.cpp
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-17.
//
//

#include "homeicon.h"

const int touchThreshold = 30;

HomeIcon::HomeIcon(string _title,
                   string _apiPath, string _iconPath, string _moviePath) {
    title = _title;
    apiPath = _apiPath;
    iconPath = _iconPath;
    moviePath = _moviePath;
    
    bg = new ofImage();
    bg->loadImage("img/icon_bg.png");
    
    ring = new ofImage();
    ring->loadImage("img/icon_time_fg.png");
    
    bgAlpha = new ofImage();
    bgAlpha->loadImage("img/icon_bg_alpha.png");
    
    //movie = new ofVideoPlayer();
    //movie->loadMovie(moviePath);
    //movie->setLoopState(OF_LOOP_NONE);
    //movie->setFrame(0);
	movie.loadMovie(moviePath);
	movie.setLoopState(OF_LOOP_NONE);
	movie.setFrame(0);
    
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
    //if(movie->isPlaying()) {
    //    movie->draw(0,0);
	if (movie.isPlaying()) {
        glDisable(GL_BLEND);
        bgAlpha->draw(0,0);
        glEnable(GL_BLEND);
//        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_DST_COLOR);
//        glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA);
        glBlendFuncSeparate(GL_DST_ALPHA, GL_ONE_MINUS_DST_ALPHA, GL_ONE, GL_ONE);
        movie.draw(0, 0);
 //       glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_DST_COLOR);
//        glDisable(GL_BLEND);
    } else {
        bg->draw(0,0);
        ring->draw(0,0);
        icon->draw(0,0);
    }
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
    
    //movie->update();
	movie.update();
}

void HomeIcon::playVideo() {
	movie.setFrame(0);
	movie.play();
    //movie->setFrame(0);
    //movie->play();
}

bool HomeIcon::videoStopped() {
    //return movie->isPlaying();
	return !movie.isPlaying();
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