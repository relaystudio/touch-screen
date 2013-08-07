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
//    
//    buttonBlue = new ofImage();
//    buttonBlue->loadImage("img/module_button_blue.png");
//    
//    buttonGreen = new ofImage();
//    buttonGreen->loadImage("img/module_button_green.png");
//    
    setupAnimation();
    loc.y += _padding;
    loc.y += footer->getHeight();
    loc.x += _padding;
    
    setupGUI();
}

AutoContainer::~AutoContainer() {
    
}

void AutoContainer::update() {
    updateAnimation();
    about->update();
    
    container->begin();
    ofClear(0,0,0,0);
    content->draw(0,0);
    about->draw();
    footer->draw(0,content->getHeight());
   // buttonBlue->draw(10,content->getHeight()+5);
    drawGUI();
    
    
    container->end();
}

void AutoContainer::draw() {
    container->draw(loc.x, loc.y);
}

void Container::setupGUI() {
    gui = new ofxUICanvas(0,0,container->getWidth(),container->getHeight());
    gui->setAutoDraw(false);
    gui->addImageButton("IMAGE BUTTON", "img/button_home.png", false, 44, 85, container->getWidth()-44, 0);
    ofAddListener(gui->newGUIEvent,this,&Container::guiEvent);
}


void Container::drawGUI() {
    gui->draw();
}

void Container::updateGUI() {
    
}

void Container::exit() {
    gui->saveSettings("GUI/guiSettings.xml");
    delete gui;
}

void Container::guiEvent(ofxUIEventArgs &e) {
    string name = e.widget->getName();
	int kind = e.widget->getKind();
    
    if(kind == OFX_UI_WIDGET_IMAGEBUTTON)
    {
        ofxUIImageButton *button = (ofxUIImageButton *) e.widget;
        cout << name << "\t value: " << button->getValue() << endl;
        close();
    }
}


