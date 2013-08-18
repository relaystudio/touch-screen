//
//  homeContainer.cpp
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-22.
//
//

#include "homeContainer.h"

HomeContainer::HomeContainer() {
    
    const int padding = 20; // Around container
    const int iconWidth = 150; // Radius of icons
    
    container = new ofFbo();
    container->allocate(ofGetWidth(),ofGetHeight());
    
    waitTime = new WaitTimeBar();
    
    autoBox = new AutoContainer(1500, 510, 210);
    
    float density = 4.0;
    float bounce = .3;
    float friction = 2.1;
    
    box2d = new ofxBox2d();
    box2d->init();
	box2d->setGravity(0, 0);
	box2d->setFPS(30.0);
    box2d->createBounds(0,0,container->getWidth(), container->getHeight());
    
    setActive(true);
    
    house = new HomeIcon("House", "/api/home", "img/icon_home.png", "img/ani_house.mov");
    house->setPhysics(density, bounce, friction);
    house->setup(box2d->getWorld(), ofRandom(iconWidth,container->getWidth()-iconWidth), ofRandom(iconWidth,container->getHeight()-iconWidth), iconWidth);
    
    car = new HomeIcon("Car", "/api/car", "img/icon_auto.png","img/ani_car.mov");
    car->setPhysics(density, bounce, friction);
    car->setup(box2d->getWorld(), ofRandom(iconWidth,container->getWidth()-iconWidth), ofRandom(iconWidth,container->getHeight()-iconWidth), iconWidth);
    
    travel = new HomeIcon("Travel", "/api/travel", "img/icon_travel.png","img/ani_trav.mov");
    travel->setPhysics(density, bounce, friction);
    travel->setup(box2d->getWorld(), ofRandom(iconWidth,container->getWidth()-iconWidth), ofRandom(iconWidth,container->getHeight()-iconWidth), iconWidth);
    
    membership = new HomeIcon("BCAA Membership", "/api/member", "img/icon_membership.png","img/ani_membership.mov");
    membership->setPhysics(density, bounce, friction);
    membership->setup(box2d->getWorld(), ofRandom(iconWidth,container->getWidth()-iconWidth), ofRandom(iconWidth,container->getHeight()-iconWidth), iconWidth);

    setActive(true);
    activeWindow = -1;
}

HomeContainer::~HomeContainer() {
    
}

void HomeContainer::addForces() {
    
    const float rep = 0.3;
    
    house->addRepulsionForce(membership->getPosition(),rep);
    house->addRepulsionForce(car->getPosition(), rep);
    house->addRepulsionForce(travel->getPosition(), rep);
    
    car->addRepulsionForce(house->getPosition(),rep);
    car->addRepulsionForce(membership->getPosition(), rep);
    car->addRepulsionForce(travel->getPosition(), rep);
    
    travel->addRepulsionForce(house->getPosition(),rep);
    travel->addRepulsionForce(car->getPosition(), rep);
    travel->addRepulsionForce(membership->getPosition(), rep);
    
    membership->addRepulsionForce(house->getPosition(),rep);
    membership->addRepulsionForce(car->getPosition(), rep);
    membership->addRepulsionForce(travel->getPosition(), rep);
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
    
//    if(autoBox->isClosed()) activeWindow = -1;
    checkActiveButton();
    animateIcons();
    
    if(activeWindow != -1) {
        switch(activeWindow) {
            case HOME:
                autoBox->setPage("html/home");
                break;
            case TRAVEL:
                autoBox->setPage("html/travel");
                break;
            case AUTO:
                autoBox->setPage("html/auto");
                break;
            case MEMBER:
                autoBox->setPage("html/member");
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
            ofSetColor(255,255,255,autoBox->getFade());
            house->draw();
            car->draw();
            travel->draw();
            membership->draw();
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
    if(house->videoStopped()
       && car->videoStopped()
       && travel->videoStopped()
       && membership->videoStopped())
    {
        int playRandom = ofRandom(0,3);
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
}

void HomeContainer::draw() {
    container->draw(0,0);
}