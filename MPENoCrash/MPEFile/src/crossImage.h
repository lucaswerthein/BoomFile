#ifndef	_CROSSIMAGE
#define _CROSSIMAGE

#include "ofMain.h"
#include "ofxBox2d.h"


class crossImage: public ofxBox2dCrissCross{
public:
	static void loadImage();
	void draw();
	
	static bool loadedImage;
	static		ofImage cross;
};

#endif _CROSSIMAGE