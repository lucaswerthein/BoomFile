#ifndef	_GEARPLAYER
#define _GEARPLAYER

#include "ofMain.h"
#include "ofxBox2d.h"

class gearPlayer: public ofBaseApp{
public:
	 void loadGear();
	 void drawGear();
	
	 bool loadedImage;
	ofImage gear[90];
	int counter;
};

#endif _GEARPLAYER