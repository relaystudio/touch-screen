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
    
    autoBox = new AutoContainer(container->getWidth(), container->getHeight(), padding);
    
    float density = 4.0;
    float bounce = .3;
    float friction = 1.1;
    
    box2d = new ofxBox2d();
    box2d->init();
	box2d->setGravity(0, 0);
	box2d->setFPS(30.0);
    box2d->createBounds(0,0,container->getWidth(), container->getHeight());
    box2d->registerGrabbing();
    
    
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
    //touch->getPoint();

    house->update(box2d);
    car->update(box2d);
    travel->update(box2d);
    membership->update(box2d);
    
    if(house->isActivated())
        ofLog() << "Activating Home page";
    if(car->isActivated()) {
        ofLog() << "Activating Auto page";
        autoBox->open();
        activeWindow = AUTO;
    }
    if(travel->isActivated())
        ofLog() << "Activating Travel page";
    if(membership->isActivated())
        ofLog() << "Activating Membership page";
    
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
    
    container->begin();
        ofClear(0,0,0,0);
        house->draw();
        car->draw();
        travel->draw();
        membership->draw();
    
        switch(activeWindow) {
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
    container->end();
}

void HomeContainer::draw() {
    container->draw(0,0);
}