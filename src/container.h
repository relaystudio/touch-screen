//
//  container.h
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-17.
//
//

#ifndef __BCAA__container__
#define __BCAA__container__

#include <iostream>
#include "ofMain.h"
#include "page.h"
#include "settings.h"
#include "ofxUI.h"

class Container {
public:
    Container();
    ~Container();
    
    void setupAnimation();
    
    void open(); // Start container
    void close(); // Close container
    
    void next(); // Next page
    void prev(); // Prev page
    void submit(); // Submit form from page (called by page)
    
    void jump(int _pageid); // Jumpt to page
    
    void draw();
    void update();
    void updateAnimation();
    
    void addPage(Page * _page);
    
    bool hasName();
    void setName(string _name);
    string getName();
    
    void exit();
    void guiEvent(ofxUIEventArgs &e);
    
    void setupGUI();
    void drawGUI();
    void updateGUI();
    
private:
    ofFbo * container;
    vector<Page*> pages;
    ofxUICanvas * gui;
    
    Page * currentPage;
    
    ofPoint loc;
    ofVec2f size;
    string name;
    bool opening, closing;
    
};

#endif /* defined(__BCAA__container__) */
