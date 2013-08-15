//
//  homeContainer.h
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-22.
//
//

#ifndef __BCAA__homeContainer__
#define __BCAA__homeContainer__

#include <iostream>
#include "container.h"
#include "autoContainer.h"
#include "homeicon.h"
#include "ofxBox2d.h"
#include "touch.h"
#include "waitTime.h"


class HomeContainer : public Container {
  
    
    enum {
        HOME = 0,
        AUTO = 1,
        TRAVEL = 2,
        MEMBER = 3,
        CONTEST = 4
    } State;
    
    public:
    
    HomeContainer();
    ~HomeContainer();
    
    void update();
    void draw();
    void setActive(bool _active);
    
    void addForces();
    void checkActiveButton();
    void animateIcons();
    
    void setupGUI();
    
    private:
    ofFbo * container;
    
    HomeIcon * house;
    HomeIcon * car;
    HomeIcon * travel;
    HomeIcon * membership;

    int activeWindow; // Active or queued
//    int prevWindow; // Still active until -1
    
    WaitTimeBar * waitTime;
    
    ofxBox2d * box2d;
    
    ofPoint * cursor;
    
    AutoContainer * autoBox;
    
};

#endif /* defined(__BCAA__homeContainer__) */
