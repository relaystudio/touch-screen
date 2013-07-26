//
//  autoContainer.cpp
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-26.
//
//

#include "autoContainer.h"

AutoContainer::AutoContainer(int _width, int _height, int _padding) {
    container = new ofFbo();
    container->allocate(_width - _padding*2, _height - _padding*2);
}

AutoContainer::~AutoContainer() {
    
}

void AutoContainer::update() {
    container->begin();
    ofBackgroundGradient(70,120);
    ofDrawBitmapString("TEST CONTRAINER", ofGetWidth()/3, ofGetHeight()/2);
    container->end();
}

void AutoContainer::draw() {
    container->draw(loc.x, loc.y);
}