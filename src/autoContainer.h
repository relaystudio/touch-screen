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

//#define AWESOMIUM 1

class AutoContainer : public Container {
    
public:
    
    AutoContainer(int _width, int _height, int _padding);
    ~AutoContainer();
    
    void update();
    void draw();
    
    void setPage(string _url);
    
    void open();
    void close();
    bool isClosed();
    void updateAnimation();
    
    void exit();
    void guiEvent(ofxUIEventArgs &e);
    
    void setupGUI();
    void drawGUI();
    void updateGUI();
    
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
private:
    AboutPage * about;
    
    ofFbo * container;
    
    string url;
    
    ofImage * footer;
    ofImage * content;
    ofImage * header;
    ofImage * logo;
    ofImage * buttonBlue;
    ofImage * buttonGreen;
    int padding, totalHeight;
    float easing;
    ofPoint * cursor;
    ofPoint loc;
    bool isOpen;
    const int tweenSpeed = 10;
    ofxUICanvas * gui;
#ifdef AWESOMIUM
    Awesomium::WebView* webView;
	Awesomium::WebCore* webCore;
#endif
};

#endif /* defined(__BCAA__autoContainer__) */
