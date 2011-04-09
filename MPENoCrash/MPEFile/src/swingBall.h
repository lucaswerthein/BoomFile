#ifndef _SWINGBALL
#define _SWINGBALL

#include "ofMain.h"
#include "ofxBox2d.h"

class swingBall: public ofxBox2dCircle{
public:
	static void loadImage();
	void draw();
	
	static bool loadedImage;
	static		ofImage tball;
	
};

#endif _SWINGBALL