//
//  page.cpp
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-17.
//
//

#include "page.h"

Page::Page() {
    page = new ofFbo();
    page->allocate();
    name = "";
}

Page::~Page() {
 
}

void Page::update() {
    page->begin();
    ofBackground(70);
    ofDrawBitmapString("TEST PAGE", ofPoint(page->getWidth()/3, page->getHeight()/2));
    page->end();
}

void Page::draw() {
    page->draw(loc.x,loc.y);
}

ofPoint Page::getPosition() {
    return loc;
}

void Page::setPosition(ofPoint _loc) {
    loc = _loc;
}

bool Page::hasName() {
    return name.size()>0 ? true : false;
}

string Page::getName() {
    return name.size()>0 ? name : "untitled";
}

void Page::setName(string _name) {
    name = _name;
}