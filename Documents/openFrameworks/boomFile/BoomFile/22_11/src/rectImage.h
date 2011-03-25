#ifndef _RECTIMAGE
#define _RECTIMAGE

#include "ofMain.h"
#include "ofxBox2d.h"

class rectImage: public ofxBox2dRect{
public:
	static void loadImage();
	void draw();
	
	static bool loadedImage;
	static		ofImage tball;
	
};

#endif _RECTIMAGE