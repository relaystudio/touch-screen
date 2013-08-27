//
//  homeContainer.cpp
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-22.
//
//

#include "homeContainer.h"

HomeContainer::HomeContainer() {
    
    if(XML.loadFile("settings.xml")) ofLog() << "Loaded Settings successfully.";
    XML.pushTag("xml");
    if(XML.pushTag(XML.getValue("Orientation","horizontal"))) ofLog() << "Correctly set orientation";
    
    const int padding = 20; // Around container
    const int iconWidth = 160; // Radius of icons
    
    container = new ofFbo();
    container->allocate(XML.getValue("width", 1920), XML.getValue("height", 1080));
    
    waitTime = new WaitTimeBar();
    
    autoBox = new AutoContainer(XML.getValue("cwidth", 1500), XML.getValue("cheight", 818), XML.getValue("cpad", 210));
	ofAddListener(ofEvents().mousePressed, autoBox, &AutoContainer::mousePressed); // Working
	ofAddListener(ofEvents().mouseDragged, autoBox, &AutoContainer::mouseMoved);
    ofAddListener(ofEvents().mouseReleased, autoBox, &AutoContainer::mouseReleased);

    float density = 4.0;
    float bounce = .3;
    float friction = 2.1;
    
    box2d = new ofxBox2d();
    box2d->init();
	box2d->setGravity(0, 0);
	box2d->setFPS(30.0);
    box2d->createBounds(0,170,container->getWidth(), container->getHeight()-170);
    
    setActive(true);
    
    house = new HomeIcon("House", "/api/home", "img/icon_home.png", "img/ani_house.mov", false);
    house->setPhysics(density, bounce, friction);
    house->setup(box2d->getWorld(), ofRandom(iconWidth,container->getWidth()-iconWidth), ofRandom(iconWidth,container->getHeight()-iconWidth-170)+170, iconWidth);
    
    car = new HomeIcon("Car", "/api/car", "img/icon_auto.png","img/ani_car.mov", false);
    car->setPhysics(density, bounce, friction);
    car->setup(box2d->getWorld(), ofRandom(iconWidth,container->getWidth()-iconWidth), ofRandom(iconWidth,container->getHeight()-iconWidth-170)+170, iconWidth);
    
    travel = new HomeIcon("Travel", "/api/travel", "img/icon_travel.png","img/ani_travel.mov", false);
    travel->setPhysics(density, bounce, friction);
    travel->setup(box2d->getWorld(), ofRandom(iconWidth,container->getWidth()-iconWidth), ofRandom(iconWidth,container->getHeight()-iconWidth-170)+170, iconWidth);
    
    membership = new HomeIcon("BCAA Membership", "/api/member", "img/icon_membership.png","img/ani_membership.mov", false);
    membership->setPhysics(density, bounce, friction);
    membership->setup(box2d->getWorld(), ofRandom(iconWidth,container->getWidth()-iconWidth), ofRandom(iconWidth,container->getHeight()-iconWidth)+170, iconWidth);

    contest = new HomeIcon("Contest", "/api/contest", "img/win_icon.png","img/ani_travel.mov", true);
    contest->setPhysics(density, bounce, friction);
    contest->setup(box2d->getWorld(), ofRandom(iconWidth,container->getWidth()-iconWidth), ofRandom(iconWidth,container->getHeight()-iconWidth-170)+170, iconWidth);
    
    evolve = new HomeIcon("Evolve", "/api/evolve", "img/evolve_icon.png","img/ani_membership.mov", true);
    evolve->setPhysics(density, bounce, friction);
    evolve->setup(box2d->getWorld(), ofRandom(iconWidth,container->getWidth()-iconWidth), ofRandom(iconWidth,container->getHeight()-iconWidth)+170, iconWidth);

    
    setActive(true);
    activeWindow = -1;
    
}

HomeContainer::~HomeContainer() {
    
}

void HomeContainer::addForces() {
    
    const float rep = 0.4;
    const float rep2 = 0.1;
    
    house->addRepulsionForce(membership->getPosition(),rep2);
    house->addRepulsionForce(car->getPosition(), rep2);
    house->addRepulsionForce(travel->getPosition(), rep2);
    
    car->addRepulsionForce(house->getPosition(),rep2);
    car->addRepulsionForce(membership->getPosition(), rep2);
    car->addRepulsionForce(travel->getPosition(), rep2);
    
    travel->addRepulsionForce(house->getPosition(),rep2);
    travel->addRepulsionForce(car->getPosition(), rep2);
    travel->addRepulsionForce(membership->getPosition(), rep2);
    
    membership->addRepulsionForce(house->getPosition(),rep2);
    membership->addRepulsionForce(car->getPosition(), rep2);
    membership->addRepulsionForce(travel->getPosition(), rep2);
    
    contest->addRepulsionForce(house->getPosition(),rep2);
    contest->addRepulsionForce(car->getPosition(), rep2);
    contest->addRepulsionForce(travel->getPosition(), rep2);
    contest->addRepulsionForce(evolve->getPosition(), rep2);
    
    evolve->addRepulsionForce(house->getPosition(),rep2);
    evolve->addRepulsionForce(car->getPosition(), rep2);
    evolve->addRepulsionForce(travel->getPosition(), rep2);
    evolve->addRepulsionForce(evolve->getPosition(),rep2);
    
    house->addRepulsionForce(ofGetWidth()/2, ofGetHeight()/2, -(rep*2));
    car->addRepulsionForce(ofGetWidth()/2, ofGetHeight()/2, -(rep*2));
    travel->addRepulsionForce(ofGetWidth()/2, ofGetHeight()/2, -(rep*2));
    membership->addRepulsionForce(ofGetWidth()/2, ofGetHeight()/2, -(rep*2));
    contest->addRepulsionForce(ofGetWidth()/2, ofGetHeight()/2, -(rep*2));
    evolve->addRepulsionForce(ofGetWidth()/2, ofGetHeight()/2, -(rep*2));
}

void HomeContainer::update() {
    box2d->update();
    autoBox->update();
    addForces();
    waitTime->update();

    

    house->update(box2d);
    car->update(box2d);
    travel->update(box2d);
    membership->update(box2d);
    contest->update(box2d);
    evolve->update(box2d);

    
//    if(autoBox->isClosed()) activeWindow = -1;
    checkActiveButton();
    animateIcons();
    
    if(activeWindow != -1) {
        switch(activeWindow) {
            case HOME:
                autoBox->setPage("http://localhost/InsuranceHome.aspx"); // PROD: http://localhost/Insurance.aspx?section=home
                break;
            case TRAVEL:
                autoBox->setPage("http://localhost/InsuranceTravel.aspx"); // PROD: http://localhost/Insurance.aspx?section=travel
                break;
            case AUTO:
                autoBox->setPage("http://localhost/InsuranceCar.aspx"); // PROD: http://localhost/Insurance.aspx?section=car
                break;
            case MEMBER:
                autoBox->setPage("http://localhost/InsuranceMembership.aspx"); // PROD: http://localhost/Insurance.aspx?section=membership
                break;
            default:
                break;
        }
        autoBox->open();
        activeWindow = -1;
    }
    
    

    container->begin();
        ofClear(0,0,0,0);
        waitTime->draw();
        ofPushStyle();
  //      glEnable(GL_BLEND);
//        glBlendFunc(GL_ONE,GL_ZERO);
            ofSetColor(255,255,255,autoBox->getFade());
    
            // Draw movie first
            if(!house->videoStopped()) house->draw();
            if(!car->videoStopped()) car->draw();
            if(!travel->videoStopped()) travel->draw();
            if(!membership->videoStopped()) membership->draw();
            if(!contest->videoStopped()) contest->draw();
            if(!evolve->videoStopped()) evolve->draw();
    
            // draw others later
            if(house->videoStopped()) house->draw();
            if(car->videoStopped()) car->draw();
            if(travel->videoStopped()) travel->draw();
            if(membership->videoStopped()) membership->draw();
            if(contest->videoStopped()) contest->draw();
            if(evolve->videoStopped()) evolve->draw();
    //        glDisable(GL_BLEND);
        ofPopStyle();
    
        autoBox->draw();
    
    container->end();
}

void HomeContainer::setActive(bool _active) {
    if(_active) {
        ofAddListener(ofEvents().mousePressed, box2d, &ofxBox2d::mousePressed);
        ofAddListener(ofEvents().mouseDragged, box2d, &ofxBox2d::mouseDragged);
        ofAddListener(ofEvents().mouseReleased, box2d, &ofxBox2d::mouseReleased);
    } else if(!_active) {
        ofRemoveListener(ofEvents().mousePressed, box2d, &ofxBox2d::mousePressed);
        ofRemoveListener(ofEvents().mouseDragged, box2d, &ofxBox2d::mouseDragged);
        ofRemoveListener(ofEvents().mouseReleased, box2d, &ofxBox2d::mouseReleased);
    }
}

void HomeContainer::animateIcons() {
	//cout << "Videos Stopped: " << house->videoStopped() << ", " << car->videoStopped() << ", " << travel->videoStopped() << ", " << membership->videoStopped() << endl; // Travel always seems to be playing

    if(house->videoStopped()
       && car->videoStopped()
       && travel->videoStopped()
       && membership->videoStopped())
    {
        int playRandom = ofRandom(0,3);
		//cout << "Select Icon to play: " << playRandom << endl;
        switch(playRandom) {
            case 0:
                car->playVideo();
                break;
            case 1:
                house->playVideo();
                break;
            case 2:
                travel->playVideo();
                break;
            case 3:
                membership->playVideo();
                break;
            default:
                break;
        }
    }
}

void HomeContainer::setupGUI() {
    
}

void HomeContainer::checkActiveButton() {
    // Make sure touch is activated
    if(autoBox->getFade() < 200 ) setActive(false);
    else setActive(true);
    
    if(house->isActivated()) {
        ofLog() << "Activating Home page";
        activeWindow = HOME;
    }
    
    if(car->isActivated()) {
        ofLog() << "Activating Auto page";
        activeWindow = AUTO;
    }
    
    if(travel->isActivated()) {
        ofLog() << "Activating Travel page";
        activeWindow = TRAVEL;
    }
    
    if(membership->isActivated()) {
        ofLog() << "Activating Membership page";
        activeWindow = MEMBER;
    }
    
    
    if(evolve->isActivated()) {
        ofLog() << "Activating Travel page";
        activeWindow = EVOLVE;
    }
    
    if(contest->isActivated()) {
        ofLog() << "Activating Membership page";
        activeWindow = CONTEST;
    }
}

void HomeContainer::draw() {
    container->draw(0,0);
}