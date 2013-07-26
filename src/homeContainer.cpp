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
    
    box2d = new ofxBox2d();
    box2d->init();
	box2d->setGravity(0, 0);
	box2d->setFPS(1.0);
    box2d->createBounds(0,0,container->getWidth(), container->getHeight());
//    box2d->registerGrabbing();
    
//    ofAddListener(o
    
    int iconWidth = 300;
    
    house = new HomeIcon("House", "/api/home", "img/icon_home.png");
    house->setPhysics(3.0, 0.53, 0.9);
    house->setup(box2d->getWorld(), ofRandom(0,container->getWidth()), ofRandom(0,container->getHeight()), iconWidth);
    
    car = new HomeIcon("Car", "/api/car", "img/icon_home.png");
    car->setPhysics(3.0, 0.53, 0.9);
    car->setup(box2d->getWorld(), ofRandom(0,container->getWidth()), ofRandom(0,container->getHeight()), iconWidth);
    
    travel = new HomeIcon("Travel", "/api/travel", "img/icon_home.png");
    travel->setPhysics(3.0, 0.53, 0.9);
    travel->setup(box2d->getWorld(), ofRandom(0,container->getWidth()), ofRandom(0,container->getHeight()), iconWidth);
    
    membership = new HomeIcon("BCAA Membership", "/api/member", "img/icon_home.png");
    membership->setPhysics(3.0, 0.53, 0.9);
    membership->setup(box2d->getWorld(), ofRandom(0,container->getWidth()), ofRandom(0,container->getHeight()), iconWidth);

    
}

HomeContainer::~HomeContainer() {
    
}

void HomeContainer::update() {
    box2d->update();
     
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