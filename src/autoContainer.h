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
#include "ofxTween.h"

//#define AWESOMIUM 1

#ifdef AWESOMIUM
#include "Awesomium\WebCore.h"
#include "Awesomium\STLHelpers.h"
#include "Awesomium\BitmapSurface.h"
#endif

class AutoContainer : public Container, public ofEventArgs {
    
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
    int getFade();
    
    void exit();
    void guiEvent(ofxUIEventArgs &e);
    
    void setupGUI();
    void drawGUI();
    void updateGUI();
    
    ofTexture getViewTexture();

	void mousePressed(ofMouseEventArgs &e);
	void mouseMoved(ofMouseEventArgs &e);
	void mouseReleased(ofMouseEventArgs &e);
    
private:
    AboutPage * about;
    
    ofFbo * container;
    int w,h;
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
    ofxUICanvas * gui;
#ifdef AWESOMIUM
	Awesomium::WebCore *webCore;
	Awesomium::WebView *view;
	ofTexture webView;
	//JSObject jsCloseNotifier;
#endif
	ofxTween tween;
	ofxEasingElastic easingElastic;
};

#endif /* defined(__BCAA__autoContainer__) */
