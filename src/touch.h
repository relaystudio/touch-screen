//
//  touch.h
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-19.
//
//

#ifndef __BCAA__touch__
#define __BCAA__touch__

#include <iostream>
#include "ofMain.h"
#include "ofxTuio.h"

class Touch {
    
public:
    Touch();
    Touch(int _port);
    ~Touch();
    
    
    vector<ofPoint> * getPoints();
    
    void update(); // Recieve msg
    void draw(); // draw cursor (debug)
    
private:
    void tuioAdded(ofxTuioCursor & tuioCursor);
	void tuioRemoved(ofxTuioCursor & tuioCursor);
	void tuioUpdated(ofxTuioCursor & tuioCursor);
  
    vector<ofPoint> pnt;
    
    ofxTuioClient tuioClient;
    
};



#endif /* defined(__BCAA__touch__) */
