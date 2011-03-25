#ifndef _PLATFORM
#define _PLATFORM

#include "ofMain.h"
#include "ofxBox2d.h"

class platform: public ofxBox2dRect{
public:
	static void loadImage();
	void draw();
	
	static bool loadedImage;
	static		ofImage base;
	
};

#endif _RECTIMAGE