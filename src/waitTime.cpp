    
//  waitTime.cpp
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-08-11.
//
//

#include "waitTime.h"

WaitTimeBar::WaitTimeBar() {

    background = new ofImage();
    background->loadImage("img/module_button_blue.png");
    
    car = new ofImage();
    
    
    house = new ofImage();
    travel = new ofImage();
    member = new ofImage();
}

WaitTimeBar::~WaitTimeBar() {
    
}

void WaitTimeBar::update() {
    
}

void WaitTimeBar::draw() {
    ofPushMatrix();
    ofTranslate(50,50);
    background->draw(0,0,ofGetWidth()-100,50);
    ofPopMatrix();
}

void WaitTimeBar::setState(int _transparency) {
    
}