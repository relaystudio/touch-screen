    
//  waitTime.cpp
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-08-11.
//
//

#include "waitTime.h"

//using namespace boost::posix_time;

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
    readXML();
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
    // http://stackoverflow.com/questions/321849/strptime-equivalent-on-windows
    time(&now);
    strTime     = XML.getAttribute("WaitTime:module:customerNumberByService","Auto", 0);
    // July-25-13 4:46:20 PM
//    strptime(strTime,"%B-%d-%y %H:%M:%S %p", &buf);
//
//    
//	carTime		= difftime(now, mktime(&buf);
    carNum      = XML.getAttribute("WaitTime:module:estimatedStartTimeByService","Auto", 0);
    
	houseTime	= XML.getAttribute("WaitTime:module:customerNumberByService","Home", 0);
    houseNum    = XML.getAttribute("WaitTime:module:estimatedStartTimeByService","Home", 0);
    
	travelTime	= XML.getAttribute("WaitTime:module:customerNumberByService","Travel", 0);
    travelNum   = XML.getAttribute("WaitTime:module:estimatedStartTimeByService","Travel", 0);
    
    memberTime	= XML.getAttribute("WaitTime:module:customerNumberByService","Member", 0);
    memberNum   = XML.getAttribute("WaitTime:module:estimatedStartTimeByService","Member", 0);
}