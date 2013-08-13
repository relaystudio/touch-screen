    
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
    
    
    house = new ofImage();
    travel = new ofImage();
    member = new ofImage();
    
    carTime = ofRandom(0,5);
    houseTime = ofRandom(0,5);
    travelTime = ofRandom(0,5);
    memberTime = ofRandom(0,5);
}

WaitTimeBar::~WaitTimeBar() {
    
}

void WaitTimeBar::update() {
    if(carTime >= 0) carTime = ofRandom(0,5);
    if(houseTime >= 0) houseTime = ofRandom(0,5);
    if(travelTime >= 0) travelTime = ofRandom(0,5);
    if(memberTime >= 0) memberTime = ofRandom(0,5);
    
    carTime -= ofRandom(0,5);
    houseTime -= ofRandom(0,5);
    travelTime -= ofRandom(0,5);
    memberTime -= ofRandom(0,5);
    
}

void WaitTimeBar::draw() {
    ofPushMatrix();
    ofTranslate(padding,50);
    background->draw(0,0,width, height);
    ofDrawBitmapString(carTime > 0 ? "It's your turn!" : ofToString(carTime) + " minutes left!", 0, 25);
    ofDrawBitmapString(carTime > 0 ? "It's your turn!" : ofToString(carTime) + " minutes left!", width * .25, 25);
    ofDrawBitmapString(carTime > 0 ? "It's your turn!" : ofToString(carTime) + " minutes left!", width * .5, 25);
    ofDrawBitmapString(carTime > 0 ? "It's your turn!" : ofToString(carTime) + " minutes left!", width * .75, 25);
    ofPopMatrix();
}

void WaitTimeBar::setState(int _transparency) {
    
}