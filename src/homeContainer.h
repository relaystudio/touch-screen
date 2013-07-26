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

class HomeContainer : public Container {
  
    public:
    
    HomeContainer();
    ~HomeContainer();
    
    void update();
    void draw();
    
    void addForces();
    
    private:
    ofFbo * container;
    
    HomeIcon * house;
    HomeIcon * car;
    HomeIcon * travel;
    HomeIcon * membership;
    
    const int iconNumber = 4;
    
    ofxBox2d * box2d;
    
    ofPoint * cursor;
    
    AutoContainer * autoBox;
    
};

#endif /* defined(__BCAA__homeContainer__) */
