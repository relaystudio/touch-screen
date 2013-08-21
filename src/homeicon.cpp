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
                   string _apiPath, string _iconPath, string _moviePath, bool _iconOnly) {
    title = _title;
    apiPath = _apiPath;
    iconPath = _iconPath;
    moviePath = _moviePath;
    iconOnly = _iconOnly;
    
    bg = new ofImage();
    bg->loadImage("img/icon_bg.png");
    
    ring = new ofImage();
    ring->loadImage("img/icon_time_fg.png");
    
    bgAlpha = new ofImage();
    bgAlpha->loadImage("img/icon_bg_alpha.png");
    
	cout << "LoadMovie: " << moviePath << endl;
	movie.loadMovie(moviePath);
	movie.setLoopState(OF_LOOP_NONE);
	movie.setFrame(0);
    
    icon = new ofImage();
    icon->loadImage(iconPath);
    
    radius = 20;  // This isn't used for anything atm
    touchTimer = touchDistance = 0;
    origin = ofPoint(-1,-1);
    wasActivated = isActive = false;
    
    shader.load("shader/nothing.vert", "shader/halftrans.frag");
    
}

HomeIcon::~HomeIcon() {
    
}

void HomeIcon::draw() {
    if(!isBody()) return;
	ofPushMatrix();
    ofPushStyle();
    ofEnableAlphaBlending();
    ofTranslate(getPosition().x-150, getPosition().y-150);

	if (movie.isPlaying()) {
        glBlendFuncSeparate(GL_ZERO, GL_ONE, GL_SRC_ALPHA, GL_DST_ALPHA);
//        bgAlpha->draw(0,0);
        ofSetColor(255,255,255,255);
        ofSetCircleResolution(48);
        ofCircle(150,150,150);
        glBlendFunc(GL_DST_ALPHA, GL_ONE_MINUS_DST_ALPHA);
        ofSetColor(255,255,255,255);
//        shader.begin();
        ofImage buf; buf.allocate(movie.getWidth(), movie.getHeight(), OF_IMAGE_COLOR);
        buf = movie.getPixelsRef(); buf.setImageType(OF_IMAGE_COLOR_ALPHA);
        for(int i=0;i<buf.getPixelsRef().size()-4; i+=4) {
            if(   buf.getPixelsRef()[i] >= 235
               && buf.getPixelsRef()[i+1] >= 235
               && buf.getPixelsRef()[i+2] >= 235)
            {
                buf.getPixelsRef()[i+3] = 50;
            } else {
                buf.getPixelsRef()[i+3] = 255;
            }
        }
        buf.reloadTexture();
        buf.draw(0,0);
  //      shader.end();
    } else {
        if(!iconOnly) {
            bg->draw(0,0);
            ring->draw(0,0);
        }
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
        //ofLog() << title << " : " << touchDistance;
        isActive = false;
        
        if(touchDistance < touchThreshold) {
            wasActivated = true;
        }
    }
    
	movie.update();
	if (movie.getCurrentFrame() == movie.getTotalNumFrames()) {
		movie.stop();
	}
}

void HomeIcon::playVideo() {
	movie.setFrame(0);
	movie.play();
}

bool HomeIcon::videoStopped() {
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