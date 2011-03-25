#ifndef	_BKGIMAGE
#define _BKGIMAGE

#include "ofMain.h"
#include "ofxBox2d.h"

class bkgImage: public ofBaseApp{
public:
	static void loadImage();
	static void drawImage();
	
	static bool loadedImage;
	static		ofImage bkg;
	static		ofImage	bkgDomino;
	
};

#endif _BKGIMAGE