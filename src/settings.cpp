//
//  settings.cpp
//  BCAA
//
//  Created by Andrew Lovett Barron on 2013-07-17.
//
//

#include "settings.h"

Settings* Settings::settings= NULL;

Settings::Settings(string _path){
    
}

Settings::Settings() { // Default constructor
    // do init stuff
}

Settings * Settings::getSettings(string _path)
{
	if (settings== NULL) {
		settings = new Settings(_path);
	}
	return settings;
}

Settings::~Settings() {
    
}

////////////////////////////////////////////////
////////////////////////////////////////////////
int Settings::getValue(ValueType _title) {
    // to Implement 
    return 0;
}

void setValue(ValueType _title, int _value) {
    // to Implement
}
