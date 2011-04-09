#ifndef	_ANIMATIONS
#define _ANIMATIONS

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxAlphaVideoPlayer.h"

class animations: public ofBaseApp{
public:
	 void loadMovie();
	 void updateMovie();
	 void drawMovie();
	
	bool loadedMovie;
	ofxAlphaVideoPlayer				swirl;
	ofxAlphaVideoPlayer				pickery;
	ofxAlphaVideoPlayer				gears;
	ofxAlphaVideoPlayer				plaid;
	ofxAlphaVideoPlayer				layer;

	
};

#endif _ANIMATIONS