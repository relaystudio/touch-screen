    
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
    background->loadImage("img/ticker-01.png");
    
    flipImg = new ofImage();
    flipImg->loadImage("img/ticker_active.png");
    
    car = new ofImage();
    car->loadImage("img/icon_auto_wait.png");
    
    house = new ofImage();
    house->loadImage("img/icon_home_wait.png");
    
    travel = new ofImage();
    travel->loadImage("img/icon_travel_wait.png");
    
    member = new ofImage();
    member->loadImage("img/icon_member_wait.png");
    
    
    carTime = carNum = ofRandom(0,5);
    houseTime = houseNum = ofRandom(0,5);
    travelTime = travelNum = ofRandom(0,5);
    memberTime = memberNum = ofRandom(0,5);
    TTF.loadFont("font/proximanovacond-light.ttf", 29);
    tagNum = 0; flag = false;
    loadXML();
}

WaitTimeBar::~WaitTimeBar() {
    
}

void WaitTimeBar::update() {
    // Pole the xml side of things every minute
    if(ofGetMinutes() != lastCheck) loadXML();
    readXML();

    // Flip them tags every 10 seconds
    flipTag = ofGetSeconds() % 10;
    if(flipTag == 0) flag = true;
    if(flipTag == 1 && flag == true) { tagNum = (tagNum+1) % 4; flag = false; }

}

void WaitTimeBar::draw() {
    ofPushMatrix();
    ofTranslate(74,50);
    background->draw(0,0);
    ofPushMatrix();
    ofTranslate(0,30);
    ofTranslate(15,0);

    TTF.drawString(carTime > 0 ? "It's your turn!" : ofToString(carTime) + " minutes left!", 158, 35);
    TTF.drawString(houseTime > 0 ? "It's your turn!" : ofToString(houseTime) + " minutes left!", 529,35);
    
    TTF.drawString(travelTime > 0 ? "It's your turn!" : ofToString(travelTime) + " minutes left!", 1048, 35);
    
    TTF.drawString(memberTime > 0 ? "It's your turn!" : ofToString(memberTime) + " minutes left!", 1469, 35);
    ofPopMatrix();
    ofTranslate(0,17);
    drawFlipTag();
    ofPopMatrix();
}

void WaitTimeBar::drawFlipTag() {
    int position, scale;
    int * ppl;
    switch(tagNum) {
        case 0:
            position = 0;
            ppl = &carNum;
            break;
        case 1:
            position = 415;
            ppl = &houseNum;
            break;
        case 2:
            position = 930;
            ppl = &travelNum;
            break;
        case 3:
            position = 1350;
            ppl = &memberNum;
            break;
        default:
            break;
    }
    ofPushMatrix();
    ofTranslate(position,0);
    flipImg->draw(0,0);
    TTF.drawString(*ppl == 0 ? "You're next" : ofToString(*ppl) + " people ahead of you", 10, 45);
    ofPopMatrix();
}

void WaitTimeBar::setState(int _transparency) {
    
}

void WaitTimeBar::loadXML() {
//	XML.loadFile("xml/WaitTime.xml");
    ofxHttpResponse resp = web.getUrl("http://google.com");
    if(XML.loadFromBuffer(resp.responseBody)) ofLog() << "Loaded XML";
    else {
        ofLog() << "Couldn't GET xml";
         if(XML.loadFile("xml/WaitTime.xml")) ofLog() << "Loaded file";
    }
    lastCheck = ofGetMinutes();
    ofLog() << (XML.tagExists("WaitTime",0) ? "WaitTime Works!" : "Waittime ain't there homie");
    XML.pushTag("WaitTime",0);
    XML.pushTag("module",0);
//    ofLog() << XML.doc;
}

void WaitTimeBar::readXML() {
//   <?xml version="1.0" encoding="UTF-8"?>
//   <WaitTime>
//    <status>OK</status>
//    <module show="1" locationId="04">
//          <totalCustomersInQueue>0</totalCustomersInQueue>
//          <customerNumberByService>
//              <service name="Auto">3</service>
//          </customerNumberByService>
//          <estimatedStartTimeByService>
//              <service name="Auto">July-25-13 4:46:20 PM</service>
//          </estimatedStartTimeByService>
//      </module>
//    </WaitTime>
    
    XML.pushTag("estimatedStartTimeByService", 0);
    
    int numTags = XML.getNumTags("service");
    // ofLog() << "Num of service tags: " << numTags;
    for(int i=0;i<numTags;i++) {
        
        if(XML.getAttribute("service","name", "", 0) == "Auto") {
            carTime = getDiff(XML.getValue("service", "", i));
            ofLog() << "Car time: " << carTime;
        } else
        if(XML.getAttribute("service","name", "", 0) == "Home") {
            houseTime = XML.getValue("service", 0, i);
            ofLog() << "Home time: " << houseTime;
        } else
        if(XML.getAttribute("service","name", "", 0) == "Travel") {
            travelTime = XML.getValue("service", 0, i);
            ofLog() << "Travel time: " << travelTime;
        } else
        if(XML.getAttribute("service","name", "", 0) == "Member") {
            memberTime = XML.getValue("service", 0, i);
            ofLog() << "Member service time: " << memberTime;
        }
    }
    XML.popTag();
    
    XML.pushTag("customerNumberByService", 0);
    numTags = XML.getNumTags("service");
    // ofLog() << "Num of service tags: " << numTags;
    for(int i=0;i<numTags;i++) {
        
        if(XML.getAttribute("service","name", "", 0) == "Auto") {
            carNum = XML.getValue("service", 0, i);
            ofLog() << "Car queue: " << carNum;
        } else
        if(XML.getAttribute("service","name", "", 0) == "Home") {
            houseNum = XML.getValue("service", 0, i);
            ofLog() << "Home queue: " << houseNum;
        } else
        if(XML.getAttribute("service","name", "", 0) == "Travel") {
            travelNum = XML.getValue("service", 0, i);
            ofLog() << "Travel queue: " << travelNum;
        } else
        if(XML.getAttribute("service","name", "", 0) == "Member") {
            memberNum = XML.getValue("service", 0, i);
            ofLog() << "Member service queue: " << memberNum;
        }
    }
    
    XML.popTag();
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
    long secondsDiff;
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

    secondsDiff = difftime(now,mktime(&buf));;
    ofLog() << "Dif:" << secondsDiff;
    return secondsDiff;
}