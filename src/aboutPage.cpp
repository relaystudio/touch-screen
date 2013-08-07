//
//  aboutPage.cpp
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-31.
//
//

#include "aboutPage.h"

AboutPage::AboutPage(string _path) {
    page = new ofFbo();
    page->allocate(640, 480);
}

AboutPage::~AboutPage() {
    
}



void AboutPage::update() {
    page->begin();
    ofClear(0,0,0,0);
    ofDrawBitmapString(name,300,300);
    page->end();
}

void AboutPage::draw() {
    page->draw(0,0);
}
