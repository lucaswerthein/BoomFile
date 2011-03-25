#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"
//#define	FULL_SCREEN

//========================================================================
int main( ){
	
#ifdef FULL_SCREEN
	
	ofSetupOpenGL( 8160, 768, OF_FULLSCREEN);
	ofHideCursor();
#else
	ofAppGlutWindow window;
	window.setGlutDisplayString("rgba double samples>=4 depth");
	//ofSetupOpenGL(&window, 4080*1.5058, 384*1.5058, OF_WINDOW);
	ofSetupOpenGL(4080, 384, OF_WINDOW );


	
#endif
	
	ofRunApp( new testApp() );
}
