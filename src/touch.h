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

class Touch :  public ofEventArgs  {
    
public:
    Touch();
    Touch(int _port);
    ~Touch();
    
    
    vector<ofPoint> * getPoints();
    ofPoint * getPoint();
    
    void update(); // Recieve msg
    void draw(); // draw cursor (debug)
    long getLastMoved();
private:
    void tuioAdded(ofxTuioCursor & tuioCursor);
	void tuioRemoved(ofxTuioCursor & tuioCursor);
	void tuioUpdated(ofxTuioCursor & tuioCursor);
  
    vector<ofPoint> pnt;
    
    ofxTuioClient tuioClient;
    long lastMoved;
};



#endif /* defined(__BCAA__touch__) */
