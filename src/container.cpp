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
    
}

void Container::draw() {
    
}

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