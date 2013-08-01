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
    about = new AboutPage("path");
    
    footer = new ofImage();
    footer->loadImage("img/module_footer.png");
    
    content = new ofImage();
    content->loadImage("img/module_content.png");
    
    buttonBlue = new ofImage();
    buttonBlue->loadImage("img/module_button_blue.png");
    
    buttonGreen = new ofImage();
    buttonGreen->loadImage("img/module_button_green.png");
    
    setupAnimation();
    loc.y += _padding;
    loc.y += footer->getHeight();
    loc.x += _padding;
}

AutoContainer::~AutoContainer() {
    
}

void AutoContainer::update() {
    updateAnimation();
    
    container->begin();
    ofClear(0,0,0,0);
    content->draw(0,0);
    footer->draw(0,content->getHeight());
    buttonBlue->draw(10,content->getHeight()+5);
    container->end();
}

void AutoContainer::draw() {
    container->draw(loc.x, loc.y);
}
