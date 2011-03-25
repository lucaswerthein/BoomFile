#ifndef _PIPES
#define _PIPES

#include "ofMain.h"
#include "ofxBox2d.h"

class pipes: public ofBaseApp{
public:
	static void loadImage();
	static void drawImage();

	
	static bool loadedImage;
	static		ofImage pipeOne;
	static		ofImage pipeTwo;

	
};

#endif _RECTIMAGE