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
#include <time.h>
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxHttpUtils.h"

//#include <boost/date_time/posix_time/posix_time.hpp>

class WaitTimeBar {
public:
    WaitTimeBar();
    ~WaitTimeBar();
    
    void update();
    void draw();
    void drawRed();
    void setState(int _transparency);
    
    void fetchData();
    void loadXML();
    void readXML();
    void drawFlipTag(bool red=false);
    long getDiff(string _date);
    
private:
    int width, height, padding;
    ofImage * background;
    ofImage * flipImg;
    ofImage * car;
    ofImage * house;
    ofImage * travel;
    ofImage * member;
    
    int carTime, houseTime, travelTime, memberTime;
    int carNum, houseNum, travelNum, memberNum;
    
    int state;
    
    long lastCheck;
    bool flag;
    ofxHttpUtils web;  
    float scale;
    ofxXmlSettings XML;
    ofTrueTypeFont TTF;
    
    string xmlStructure;

    int lineCount;
    int lastTagNumber;
    int flipTag,tagNum;
    
};


#endif /* defined(__BCAA__waitTime__) */
