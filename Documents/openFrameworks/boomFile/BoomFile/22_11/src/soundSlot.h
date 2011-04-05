
#ifndef _SOUNDSLOT
#define _SOUNDSLOT

#include "ofMain.h"

class soundSlot: public ofBaseApp{
public:
	static void loadSlot();
	static bool loadedSound;
	static		ofSoundPlayer  slot;
	
};

#endif _SOUNDSLOT