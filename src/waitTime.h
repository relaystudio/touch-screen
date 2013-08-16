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
    void setState(int _transparency);
    
    void fetchData();
    void loadXML();
    void readXML();
    long getDiff(string _date);
    
private:
    int width, height, padding;
    ofImage * background;
    ofImage * car;
    ofImage * house;
    ofImage * travel;
    ofImage * member;
    
    int carTime, houseTime, travelTime, memberTime;
    int carNum, houseNum, travelNum, memberNum;
    
    int state;
    
    ofxHttpUtils web;  
    
    ofxXmlSettings XML;
    ofTrueTypeFont TTF;
    
    string xmlStructure;

    int lineCount;
    int lastTagNumber;

};


#endif /* defined(__BCAA__waitTime__) */
