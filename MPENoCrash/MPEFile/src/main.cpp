#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"
#define	FULL_SCREEN

//========================================================================
int main( ){
	
#ifdef FULL_SCREEN
	ofAppGlutWindow window;
	window.setGlutDisplayString("rgb alpha double samples depth");
	ofSetupOpenGL(&window, 8160,768, OF_FULLSCREEN);  
	ofHideCursor();

	/*
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 8160, 768, OF_FULLSCREEN);
	ofHideCursor();*/
#else
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 4080/2, 384/2, OF_WINDOW);
	
#endif
	
	ofRunApp( new testApp() );
}
