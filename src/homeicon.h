//
//  homeicon.h
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-17.
//
//

#ifndef __BCAA__homeicon__
#define __BCAA__homeicon__

#include <iostream>
#include "ofMain.h"
#include "ofxBox2d.h"
#include "container.h"

class HomeIcon : public ofxBox2dCircle {
public:
    HomeIcon(string _title,
             string _apiPath, string _iconPath, string _moviePath);
    ~HomeIcon();
    
    void draw();
    void update(ofxBox2d * world);
    
    bool isActivated();
    
    void playVideo();
    bool videoStopped();
    
private:
    
    int fetchTimer(); // Get timer from connection
    
    ofImage * bg;
    ofImage * ring;
    ofImage * icon;
    //ofVideoPlayer * movie;
	ofVideoPlayer movie;
    
    int radius, activityTimer, touchTimer, touchDistance;
    bool wasActivated, isActive;
    ofPoint origin;
    
    string title, apiPath, iconPath, moviePath;
    Container * container;
    
};

#endif /* defined(__BCAA__homeicon__) */
