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
#include "AboutPage.h"

class AutoContainer : public Container {
    
public:
    
    AutoContainer(int _width, int _height, int _padding);
    ~AutoContainer();
    
    void update();
    void draw();
    
    void open();
    void close();
    bool isClosed();
    void updateAnimation();
    
    void exit();
    void guiEvent(ofxUIEventArgs &e);
    
    void setupGUI();
    void drawGUI();
    void updateGUI();
    
private:
    AboutPage * about;
    
    ofFbo * container;
    
    ofImage * footer;
    ofImage * content;
    ofImage * header;
    ofImage * logo;
    ofImage * buttonBlue;
    ofImage * buttonGreen;
    int padding;
    ofPoint * cursor;
    ofPoint loc;
    bool isOpen;
    const int tweenSpeed = 40;
    ofxUICanvas * gui;
};

#endif /* defined(__BCAA__autoContainer__) */
