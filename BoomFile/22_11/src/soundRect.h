
#ifndef _SOUNDRECT
#define _SOUNDRECT

#include "ofMain.h"

class soundRect: public ofBaseApp{
public:
	static void loadRect();
	static bool loadedSound;
	static		ofSoundPlayer  rectBeat;
	
};

#endif _SOUNDRECT