//
//  homeContainer.cpp
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-22.
//
//

#include "homeContainer.h"

HomeContainer::HomeContainer() {
    
    container = new ofFbo();
    container->allocate(ofGetWidth(),ofGetHeight());
    
    int iconWidth = 150; // Radius
    
    float density = 4.0;
    float bounce = .3;
    float friction = 1.1;
    
    box2d = new ofxBox2d();
    box2d->init();
	box2d->setGravity(0, 0);
	box2d->setFPS(1.0);
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
    house->addRepulsionForce(membership->getPosition(),0.1);
    house->addRepulsionForce(car->getPosition(), 0.1);
    house->addRepulsionForce(travel->getPosition(), 0.1);
    
    car->addRepulsionForce(house->getPosition(),0.1);
    car->addRepulsionForce(membership->getPosition(), 0.1);
    car->addRepulsionForce(travel->getPosition(), 0.1);
    
    travel->addRepulsionForce(house->getPosition(),0.1);
    travel->addRepulsionForce(car->getPosition(), 0.1);
    travel->addRepulsionForce(membership->getPosition(), 0.1);
    
    membership->addRepulsionForce(house->getPosition(),0.1);
    membership->addRepulsionForce(car->getPosition(), 0.1);
    membership->addRepulsionForce(travel->getPosition(), 0.1);
}

void HomeContainer::update() {
    box2d->update();
    
    //touch->getPoint();
    
    container->begin();
        ofClear(0,0,0,0);
        house->draw();
        car->draw();
        travel->draw();
        membership->draw();
    container->end();
}

void HomeContainer::draw() {
    container->draw(0,0);
}