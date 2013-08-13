//
//  waitTime.h
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-08-11.
//
//

#ifndef __BCAA__waitTime__
#define __BCAA__waitTime__

#include <iostream>
#include "ofMain.h"

class WaitTimeBar {
public:
    WaitTimeBar();
    ~WaitTimeBar();
    
    void update();
    void draw();
    void setState(int _transparency);
    
    void fetchData();
    
private:
    int width, height, padding;
    ofImage * background;
    ofImage * car;
    ofImage * house;
    ofImage * travel;
    ofImage * member;
    
    int carTime, houseTime, travelTime, memberTime;
    int state;
};


#endif /* defined(__BCAA__waitTime__) */
