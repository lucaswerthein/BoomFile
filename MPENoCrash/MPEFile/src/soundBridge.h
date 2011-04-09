#ifndef _SOUNDBRIDGE
#define _SOUNDBRIDGE

#include "ofMain.h"

class soundBridge: public ofBaseApp{
public:
	static void loadBridge();
	static bool loadedSound;
	static		ofSoundPlayer  bridge;
	
};

#endif _SOUNDBRIDGE