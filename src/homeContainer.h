//
//  homeContainer.h
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-22.
//
//

#ifndef __BCAA__homeContainer__
#define __BCAA__homeContainer__

#include <iostream>
#include "container.h"
#include "homeicon.h"

class HomeContainer : public Container {
  
    public:
    
    HomeContainer();
    ~HomeContainer();
    
    private:
    vector<HomeIcon> * icons;
    const int iconNumber = 3;
    
    Container * testContainer;
};

#endif /* defined(__BCAA__homeContainer__) */
