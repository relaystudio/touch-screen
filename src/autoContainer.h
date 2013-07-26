//
//  autoContainer.h
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-26.
//
//

#ifndef __BCAA__autoContainer__
#define __BCAA__autoContainer__

#include <iostream>
#include "container.h"
#include "homeicon.h"
#include "ofxBox2d.h"
#include "touch.h"

class AutoContainer : public Container {
    
public:
    
    AutoContainer(int _width, int _height, int _padding);
    ~AutoContainer();
    
    void update();
    void draw();
    
private:
    ofFbo * container;
    
    ofPoint * cursor;
    ofPoint loc;
    Container * testContainer;
};

#endif /* defined(__BCAA__autoContainer__) */
