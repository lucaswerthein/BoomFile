
#ifndef _SOUNDBALL
#define _SOUNDBALL

#include "ofMain.h"

class soundBall: public ofBaseApp{
public:
	static void loadBall();
	static bool loadedSound;
	static		ofSoundPlayer  ballBeat;
	
};

#endif _SOUNDBALL