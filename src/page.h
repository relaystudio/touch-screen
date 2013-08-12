//
//  page.h
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-17.
//
//

#ifndef __BCAA__page__
#define __BCAA__page__

#include <iostream>
#include "ofMain.h"
#include "settings.h"

#ifdef TARGET_OS_WIN32
#include "Awesomium\WebCore.h"
#elif TARGET_OS_MAC
#include "WebCore.h"
#endif

class Page {
public:
    Page();
    ~Page();
    
    void loadPage();
    void open();
    void close();
    
    void draw();
    void update();
    
    void fetchData();
    bool isForm();
    ofPoint getPosition();
    void setPosition(ofPoint _loc);
    // getData ??? Json?
    
    bool hasName();
    void setName(string _name);
    string getName();
    
private:
    ofFbo * page;
    ofPoint loc;
    
    string name;
};

#endif /* defined(__BCAA__page__) */
