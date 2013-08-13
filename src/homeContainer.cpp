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
    float friction = 1.1;
    
    box2d = new ofxBox2d();
    box2d->init();
	box2d->setGravity(0, 0);
	box2d->setFPS(30.0);
    box2d->createBounds(0,0,container->getWidth(), container->getHeight());
    
    setActive(true);
    
    house = new HomeIcon("House", "/api/home", "img/icon_home.png");
    house->setPhysics(density, bounce, friction);
    house->setup(box2d->getWorld(), ofRandom(iconWidth,container->getWidth()-iconWidth), ofRandom(iconWidth,container->getHeight()-iconWidth), iconWidth);
    
    car = new HomeIcon("Car", "/api/car", "img/icon_auto.png");
    car->setPhysics(density, bounce, friction);
    car->setup(box2d->getWorld(), ofRandom(iconWidth,container->getWidth()-iconWidth), ofRandom(iconWidth,container->getHeight()-iconWidth), iconWidth);
    
    travel = new HomeIcon("Travel", "/api/travel", "img/icon_travel.png");
    travel->setPhysics(density, bounce, friction);
    travel->setup(box2d->getWorld(), ofRandom(iconWidth,container->getWidth()-iconWidth), ofRandom(iconWidth,container->getHeight()-iconWidth), iconWidth);
    
    membership = new HomeIcon("BCAA Membership", "/api/member", "img/icon_membership.png");
    membership->setPhysics(density, bounce, friction);
    membership->setup(box2d->getWorld(), ofRandom(iconWidth,container->getWidth()-iconWidth), ofRandom(iconWidth,container->getHeight()-iconWidth), iconWidth);

    
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
    addForces();
    waitTime->update();
    //touch->getPoint();

    house->update(box2d);
    car->update(box2d);
    travel->update(box2d);
    membership->update(box2d);
    
    if(house->isActivated()) {
        ofLog() << "Activating Home page";
        prevWindow = activeWindow;
        activeWindow = HOME;
    }
    if(car->isActivated()) {
        ofLog() << "Activating Auto page";
        prevWindow = activeWindow;
        autoBox->open();
        setActive(false);
        activeWindow = AUTO;
    }
    if(travel->isActivated()) {
        ofLog() << "Activating Travel page";
        prevWindow = activeWindow;
       activeWindow = TRAVEL;
    }
    if(membership->isActivated()) {
        ofLog() << "Activating Membership page";
        prevWindow = activeWindow;
       activeWindow = MEMBER;
    }
    
    if(prevWindow != -1 && autoBox->isClosed()) {
        // Allow for animation out
        
        switch(prevWindow) {
            case -1:
                break;
            case HOME:
                prevWindow = -1;
                break;
            case AUTO:
                autoBox->close();
                autoBox->update();
                if(autoBox->isClosed()){
                 prevWindow = -1;
                    setActive(true);
                }
                break;
            case TRAVEL:
                prevWindow = -1;
                break;
            case MEMBER:
                prevWindow = -1;
                break;
            case CONTEST:
                prevWindow = -1;
                break;
            default:
                break;
        }
    } else {
        // Animate active window
        
        switch(activeWindow) {
            case HOME:
                break;
            case AUTO:
                autoBox->update();
                break;
            case TRAVEL:
                break;
            case MEMBER:
                break;
            case CONTEST:
                break;
            default:
                break;
        }
    }
    
    container->begin();
        ofClear(0,0,0,0);
        waitTime->draw();
        house->draw();
        car->draw();
        travel->draw();
        membership->draw();
    // This is a terrible way to manage this.
    setActive(true);
    if(prevWindow != -1) {
        switch(prevWindow) {
//            setActive(false);
            case HOME:
                break;
            case AUTO:
                autoBox->draw();
                break;
            case TRAVEL:
                break;
            case MEMBER:
                break;
            case CONTEST:
                break;
            default:
                break;
        }
    } else {
        switch(activeWindow) {
            case HOME:
                break;
            case AUTO:
                autoBox->draw();
//                setActive(false);
                break;
            case TRAVEL:
                break;
            case MEMBER:
                break;
            case CONTEST:
                break;
            default:
                break;
        }
    }
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



void HomeContainer::setupGUI() {
    
}

void HomeContainer::draw() {
    container->draw(0,0);
}