//
//  container.cpp
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-17.
//
//

#include "container.h"

Container::Container() {
    container = new ofFbo();
    container->allocate();
    name = "";
}

Container::~Container() {
    
}

void Container::update() {
    container->begin();
    ofBackgroundGradient(70,120);
    ofDrawBitmapString("TEST CONTRAINER", ofGetWidth()/3, ofGetHeight()/2);
    container->end();
}

void Container::draw() {
    container->draw(loc.x, loc.y);
}

///////////////////////////////////////////////////////
//////////////////////   Pages  ///////////////////////
///////////////////////////////////////////////////////

void Container::next() {
    
}

void Container::prev() {
    
}

void Container::submit() {
    
}

void Container::jump(int _pageid) {
    
}

///////////////////////////////////////////////////////
////////////////////// Settings ///////////////////////
///////////////////////////////////////////////////////
void Container::addPage(Page * _page) {
    pages.push_back(_page);
    ofLog() << "Loading page " << _page->getName() << " to " << getName();
}

bool Container::hasName() {
    return name.size()>0 ? true : false;
}

string Container::getName() {
    return name.size()>0 ? name : "untitled";
}

void Container::setName(string _name) {
    name = _name;
}