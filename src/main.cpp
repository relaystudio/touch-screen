#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

int main( ){

    ofAppGlutWindow window;
	//ofSetupOpenGL(&window, 1366,768, OF_FULLSCREEN);			// <-------- setup the GL context

	//ofSetupOpenGL(&window, 1920, 600, OF_WINDOW);			// <-------- setup the GL context
	ofSetupOpenGL(&window, 1920, 1080, OF_WINDOW);			// <-------- setup the GL context

	ofRunApp( new testApp());

}
