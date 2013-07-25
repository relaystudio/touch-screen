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
             string _apiPath, string _iconPath);
    ~HomeIcon();
    
    void draw();
    void update();
    
    bool isActive();
    
    
private:
    
    int fetchTimer(); // Get timer from connection
    
    ofVec2f loc, acc, vel;
    int radius, activityTimer;
    bool active;
    
    string _title, _apiPath, _iconPath;
    Container * container;
    
};

#endif /* defined(__BCAA__homeicon__) */
