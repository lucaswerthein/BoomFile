#ifndef	_PLAIDPLAYER
#define _PLAIDPLAYER

#include "ofMain.h"
#include "ofxBox2d.h"

class plaidPlayer: public ofBaseApp{
public:
	void loadPlaid();
	void drawPlaid();
	
	bool loadedImage;
	ofImage plaid[160];
	int counter;
};

#endif _GEARPLAYER