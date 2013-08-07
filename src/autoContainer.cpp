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
    about->setName("Auto About Page");
    
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
  //  loc.y += footer->getHeight();
    loc.x += _padding;
    loc.y = -container->getHeight();
    
    setupGUI();
}

AutoContainer::~AutoContainer() {
    
}

void AutoContainer::update() {
    updateAnimation();
    about->update();
    
    container->begin();
    ofClear(0,0,0,0);
    content->draw(0,0,container->getWidth(),container->getHeight()-footer->getHeight());
    about->draw();
    footer->draw(0,container->getHeight()-footer->getHeight());
   // buttonBlue->draw(10,content->getHeight()+5);
    drawGUI();
    
    
    container->end();
}

void AutoContainer::draw() {
    container->draw(loc.x, loc.y);
}

void AutoContainer::setupGUI() {
    gui = new ofxUICanvas(loc.x,loc.y,container->getWidth(),container->getHeight());
    gui->setName("AutoGUI");
    gui->setAutoDraw(false);
    gui->setDrawBack(false);
    gui->addImageButton("HOME", "img/button_home.png", true, 44, 85, container->getWidth()-44, 0);
    
    
//    gui->addWidgetDown(new ofxUILabel("CUSTOM WIDGET LAYOUT", OFX_UI_FONT_LARGE), OFX_UI_ALIGN_RIGHT);
//    
//    gui->addWidget(new ofxUILabel(360, 300, "2D PAD", OFX_UI_FONT_MEDIUM));
//    gui->addWidgetSouthOf(new ofxUI2DPad(320,190, ofPoint(320*.5,190*.5), "PAD"), "2D PAD");
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent,this,&AutoContainer::guiEvent);
}


void AutoContainer::drawGUI() {
    gui->draw();
}

void AutoContainer::updateGUI() {
    gui->setPosition(loc.x,loc.y);
}

void AutoContainer::exit() {
    gui->saveSettings("GUI/guiSettings.xml");
    delete gui;
}

void AutoContainer::guiEvent(ofxUIEventArgs &e) {
    string name = e.widget->getName();
	int kind = e.widget->getKind();
    
    if(kind == OFX_UI_WIDGET_IMAGEBUTTON)
    {
        ofxUIImageButton *button = (ofxUIImageButton *) e.widget;
        cout << name << "\t value: " << button->getValue() << endl;
        close();
    }
}

void AutoContainer::open() {
    isOpen = true;
}

void AutoContainer::close() {
    isOpen = false;
    
}

bool AutoContainer::isClosed() {
    return loc.y <= -container->getHeight() ? true : false;
}

void AutoContainer::updateAnimation() {
    if(isOpen && loc.y < 0)
        loc.y += tweenSpeed;
    else if( isOpen && loc.y > 0) {
        loc.y = 0;
    }
    else if ( !isOpen && loc.y > -container->getHeight() )
        loc.y -= tweenSpeed;
    
    updateGUI();
}



