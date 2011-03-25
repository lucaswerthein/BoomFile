#ifndef	_SWIRLPLAYER
#define _SWIRLPLAYER

#include "ofMain.h"
#include "ofxBox2d.h"

class swirlPlayer: public ofBaseApp{
public:
	void loadSwirl();
	void drawSwirl();
	
	bool loadedImage;
	ofImage swirl[45];
	int counter;
};

#endif _GEARPLAYER