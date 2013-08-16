    
//  waitTime.cpp
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-08-11.
//
//

#include "waitTime.h"

WaitTimeBar::WaitTimeBar() {

    width = 1500;
    height = 50;
    padding = (ofGetWidth() - width) / 2;
    
    background = new ofImage();
    background->loadImage("img/module_button_blue.png");
    
    car = new ofImage();
    car->loadImage("img/icon_auto_wait.png");
    
    house = new ofImage();
    house->loadImage("img/icon_home_wait.png");
    
    travel = new ofImage();
    travel->loadImage("img/icon_travel_wait.png");
    
    member = new ofImage();
    member->loadImage("img/icon_member_wait.png");
    
    carTime = ofRandom(0,5);
    houseTime = ofRandom(0,5);
    travelTime = ofRandom(0,5);
    memberTime = ofRandom(0,5);
    TTF.loadFont("font/proximanova-light.ttf", 20);
}

WaitTimeBar::~WaitTimeBar() {
    
}

void WaitTimeBar::update() {
//    readXML();
    ofLog() << getDiff("August-15-13 9:50:20 PM");
}

void WaitTimeBar::draw() {
    ofPushMatrix();
    ofTranslate(padding,50);
    background->draw(0,0,width, height);
    ofTranslate(15,0);
    car->draw(0,10);
    TTF.drawString(carTime > 0 ? "It's your turn!" : ofToString(carTime) + " minutes left!", (width*.05)+(60), 25);
    
    house->draw((width * .25),0);
    TTF.drawString(carTime > 0 ? "It's your turn!" : ofToString(carTime) + " minutes left!", (width * .3)+(60), 25);
    
    travel->draw((width * .50),0);
    TTF.drawString(carTime > 0 ? "It's your turn!" : ofToString(carTime) + " minutes left!", (width * .55)+(60), 25);
    
    member->draw((width * .75),0);
    TTF.drawString(carTime > 0 ? "It's your turn!" : ofToString(carTime) + " minutes left!", (width * .8)+(60), 25);
    ofPopMatrix();
}

void WaitTimeBar::setState(int _transparency) {
    
}

void WaitTimeBar::loadXML() {
	XML.loadFile("xml/WaitTime.xml");    
}

void WaitTimeBar::readXML() {
//    <?xml version="1.0" encoding="UTF-8"?>
//    <WaitTime>
//    <status>OK</status>
//      <module show="1" locationId="04">
//          <totalCustomersInQueue>0</totalCustomersInQueue>
//          <customerNumberByService>
//              <service name="Auto">3</service>
//          </customerNumberByService>
//          <estimatedStartTimeByService>
//              <service name="Auto">July-25-13 4:46:20 PM</service>
//          </estimatedStartTimeByService>
//      </module>
//    </WaitTime>
    
    if(XML.getAttribute("WaitTime:module:customerNumberByService:service","Name", "") == "Auto") {
        carTime = XML.getValue("WaitTime:module:customerNumberByService:service", 0);
    }
//    
//    carTime     = XML.getAttribute("WaitTime:module:customerNumberByService","Auto", "");
//    carNum      = XML.getAttribute("WaitTime:module:estimatedStartTimeByService","Auto", 0);
//    
//	houseTime	= XML.getAttribute("WaitTime:module:customerNumberByService","Home", "");
//    houseNum    = XML.getAttribute("WaitTime:module:estimatedStartTimeByService","Home", 0);
//    
//	travelTime	= XML.getAttribute("WaitTime:module:customerNumberByService","Travel", "");
//    travelNum   = XML.getAttribute("WaitTime:module:estimatedStartTimeByService","Travel", 0);
//    
//    memberTime	= getDiff(XML.getAttribute("WaitTime:module:customerNumberByService","Member", ""));
//    memberNum   = XML.getAttribute("WaitTime:module:estimatedStartTimeByService","Member", 0);
}

long WaitTimeBar::getDiff(string _date) {
    // August-15-13 9:46:20 PM
    time_t now;
    tm buf;
    
    vector<string> a, b, c;
    vector<int> yy,mm,dd,hh,m,ss;
    
    a = ofSplitString(_date, " "); // Separate main
    b = ofSplitString(a[0], "-"); // Separate date
    c = ofSplitString(a[1], ":"); // Separate time
    
    time(&now);
    buf = *localtime(&now);
    int mon = 0;
    if(b[0]=="January") mon = 0; else
    if(b[0]=="February") mon = 1; else
    if(b[0]=="March") mon = 2; else
    if(b[0]=="April") mon = 3; else
    if(b[0]=="May") mon = 4; else
    if(b[0]=="June") mon = 5; else
    if(b[0]=="July") mon = 6; else
    if(b[0]=="August") mon = 7; else
    if(b[0]=="September") mon = 8; else
    if(b[0]=="October") mon = 9; else
    if(b[0]=="November") mon = 10; else
    if(b[0]=="December") mon = 11;
    
    //if(a[2] == "PM") c[0] += 12;
    
    buf.tm_sec  = ofToInt(c[2]);
    buf.tm_min  = ofToInt(c[1]);
    buf.tm_hour = ofToInt(c[0]);
    buf.tm_mday = ofToInt(b[1]);
    buf.tm_mon  = mon;
    buf.tm_year = ofToInt(b[2])+100;

    return difftime(now,mktime(&buf));;
}