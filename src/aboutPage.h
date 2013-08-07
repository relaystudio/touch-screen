//
//  aboutPage.h
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-31.
//
//

#ifndef __BCAA__aboutPage__
#define __BCAA__aboutPage__

#include <iostream>
#include "page.h"
//#include <Awesomium/WebCore.h>

class AboutPage : public Page {
    
public:
     
    AboutPage(string _path);
    ~AboutPage();
    
    void update();
    void draw();
    
private:
    ofFbo * page;
    ofPoint loc;
    
    
    string name;
    
};
#endif /* defined(__BCAA__aboutPage__) */
