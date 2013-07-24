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
    DEBUG,
    FULLSCREEN
    
};


class Settings {
    
public:
    
    static Settings * getSettings(string _path);
    

private:
    Settings(string _path);
    Settings();
    ~Settings();

    static Settings * settings;
    
    bool loadSettings();
    bool saveSettings();
    
    int getValue(ValueType _title); //0-255
    void setValue(ValueType _title, int _value);
};


#endif /* defined(__BCAA__settings__) */
