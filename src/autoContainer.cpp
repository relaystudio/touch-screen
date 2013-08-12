//
//  autoContainer.cpp
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-26.
//
//

#include "autoContainer.h"

const int tweenSpeed = 40;

AutoContainer::AutoContainer(int _width, int _height, int _padding) {
    container = new ofFbo();
    container->allocate(_width - _padding*2, _height - _padding*2);
    about = new AboutPage("path");
    about->setName("Auto About Page");
    
    footer = new ofImage();
    footer->loadImage("img/module_footer.png");
    
    header = new ofImage();
    header->loadImage("img/module_header.png");
    
    content = new ofImage();
    content->loadImage("img/module_content.png");

    logo = new ofImage();
    logo->loadImage("img/icon_auto_header.png");
    
    padding = _padding;
    setupAnimation();
    loc.y = -container->getHeight();
    loc.x = padding;
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
    header->draw(0,0);
    logo->draw(0,20);
    about->draw();
    footer->draw(0,container->getHeight()-footer->getHeight());
   // buttonBlue->draw(10,content->getHeight()+5);
   // drawGUI();
    
    
    container->end();
}

void AutoContainer::draw() {
    container->draw(loc.x, loc.y);
}

void AutoContainer::setupGUI() {
    gui = new ofxUICanvas(loc.x,loc.y,container->getWidth(),container->getHeight());
    gui->setName("AutoGUI");
    gui->setDrawWidgetPadding(false);
    gui->setDrawBack(false);

    ofxUIColor cb = ofxUIColor( 0, 0, 0, 0 );
    gui->setColorBack(cb);
//    gui->setColorOutline(cb);
//    gui->setColorOutlineHighlight(cb);
//    gui->setColorFill(cb);
//    gui->setColorFillHighlight(cb);
//    gui->setColorPadded(cb);
//    gui->setColorPaddedOutline(cb);
    
    ofxUIWidget *w;
    
    w = gui->addSpacer(container->getWidth()-85, container->getHeight()-footer->getHeight()-5, "HeaderSpacer");
    w->setColorFill(cb);
    
    gui->addWidgetEastOf(new ofxUIImageButton(0,0,44, 85,true,"img/button_home.png", "HOME"),"HeaderSpacer");
    
    
//    gui->addWidgetDown(new ofxUILabel("CUSTOM WIDGET LAYOUT", OFX_UI_FONT_LARGE), OFX_UI_ALIGN_RIGHT);
//    
//    gui->addWidget(new ofxUILabel(360, 300, "2D PAD", OFX_UI_FONT_MEDIUM));
    gui->addWidgetSouthOf(new ofxUIImageButton(0,0,215,78,true,"img/module_button_blue.png", "backButton"), "HeaderSpacer");
    w = gui->addWidgetEastOf(new ofxUISpacer(container->getWidth()-230*2,78,"buttonSpacer"), "backButton");
    w->setColorFill(cb);
    gui->addWidgetEastOf(new ofxUIImageButton(0,0,215,78,true,"img/module_button_green.png", "forwardButton"), "buttonSpacer");
//    gui->setWidgetColor(gui->getWidget("buttonSpader"), ofColor(0,0,0,0));
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
    if(isOpen && loc.y < padding)
        loc.y += tweenSpeed;
    else if( isOpen && loc.y > 0) {
        loc.y = padding;
    }
    else if ( !isOpen && loc.y > -container->getHeight() )
        loc.y -= tweenSpeed;
    
    updateGUI();
}



