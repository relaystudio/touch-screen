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
    container->allocate(_width, _height);
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
    
    totalHeight = ofGetHeight();
    padding = _padding;
    setupAnimation();
    loc.y = totalHeight + 10;
    loc.x = padding;
    easing = 0.05;
    isOpen = false;
    setupGUI();
#ifdef AWESOMIUM
    Awesomium::WebCoreConfig config;
	webCore = new Awesomium::WebCore(config);
	webView = webCore->createWebView(webTexWidth, webTexHeight);
#endif
    
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
        ofDrawBitmapString(url, 50,50);
    container->end();
}

void AutoContainer::setPage(string _url) {
    url = _url;
#ifdef AWESOMIUM
	// Load a certain URL into our WebView instance
	webView->loadURL("http://www.google.com");
	webView->focus();
#endif
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
#ifdef AWESOMIUM
    webCore->update();
    
    // Call our display func when the WebView needs rendering
	if (webView->isDirty()) {
        const Awesomium::RenderBuffer* renderBuffer = webView->render();
        if (renderBuffer) {
            webTex.loadData(renderBuffer->buffer, webTexWidth, webTexHeight, GL_BGRA);
        }
    }
#endif
}

void AutoContainer::exit() {
    gui->saveSettings("GUI/guiSettings.xml");
    delete gui;
#ifdef AWESOMIUM
    webView->destroy();
	delete webCore;
#endif
}

void AutoContainer::guiEvent(ofxUIEventArgs &e) {
    string name = e.widget->getName();
	int kind = e.widget->getKind();
    
    if(kind == OFX_UI_WIDGET_IMAGEBUTTON)
    {
        ofLog() << "CLOSING";
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
    return loc.y <= totalHeight ? false : true;
}

// Updates the tween animation.
void AutoContainer::updateAnimation() {
    int dy = isOpen ? (padding - loc.y) : (padding - (loc.y+30));// * tweenSpeed;

    if ( !isOpen && loc.y < totalHeight+10 )
        loc.y -= dy * easing * 2;
    else if ( !isOpen && loc.y > totalHeight+10)
        loc.y = totalHeight+10;
    // Is open
    else if( isOpen && loc.y < padding) loc.y = padding;
    // Is opening
    else if(isOpen && loc.y > 0) loc.y += dy * easing;
    // Is closing
    
    updateGUI();
}

// Gets window moving up to fade icons
int AutoContainer::getFade() {
    int dx = (loc.y - padding);
    int dist = (totalHeight+10) - padding;
    return int(ofMap(dx, 0, dist, 0, 255));
}


void AutoContainer::mouseMoved(int x, int y ){
    #ifdef AWESOMIUM
    webView->injectMouseMove(x, y);
    #endif
}


void AutoContainer::mouseDragged(int x, int y, int button){
    #ifdef AWESOMIUM
    webView->injectMouseMove(x, y);
    #endif
}


void AutoContainer::mousePressed(int x, int y, int button){
    #ifdef AWESOMIUM
    webView->injectMouseDown(Awesomium::LEFT_MOUSE_BTN);
    #endif
}



void AutoContainer::mouseReleased(int x, int y, int button){
    #ifdef AWESOMIUM
    webView->injectMouseUp(Awesomium::LEFT_MOUSE_BTN);
    #endif
}


