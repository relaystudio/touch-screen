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
             string _apiPath, string _iconPath, string _moviePath, bool _iconOnly);
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
    ofImage * bgAlpha;
    //ofVideoPlayer * movie;
	ofVideoPlayer movie;
    
    int radius, activityTimer, touchTimer, touchDistance;
    bool wasActivated, isActive, iconOnly;
    ofPoint origin;
    
    string title, apiPath, iconPath, moviePath;
    Container * container;
    ofShader shader;
    
};

#endif /* defined(__BCAA__homeicon__) */
