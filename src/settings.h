//
//  settings.h
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-17.
//
//

#ifndef __BCAA__settings__
#define __BCAA__settings__

#include <iostream>
#include "ofMain.h"
#include "ofxNetwork.h"
#include "ofxXmlSettings.h"
#include "ofxAutoControlPanel.h"

enum ValueType{
    DEBUG = 0,
    FULLSCREEN = 1
    
};


class Settings {
    
public:
    Settings(string _path);
    Settings();
    ~Settings();
    
    bool loadSettings();
    bool saveSettings();
    
    int getValue(ValueType _title); //0-255
    void setValue(ValueType _title, int _value);
};


#endif /* defined(__BCAA__settings__) */
