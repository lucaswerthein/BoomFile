
#ifndef _SOUNDGEARS
#define _SOUNDGEARS

#include "ofMain.h"

class soundGears: public ofBaseApp{
public:
	static void loadGears();
	static bool loadedSound;
	static		ofSoundPlayer  gears;
	
};

#endif _SOUNDGEARS