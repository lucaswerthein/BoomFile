
#ifndef _SOUNDCONTACT
#define _SOUNDCONTACT

#include "ofMain.h"

class soundContact: public ofBaseApp{
public:
	static void loadSoundDomino();
	static bool loadedSound;
	static		ofSoundPlayer  beat;
	
};

#endif _SOUNDCONTACT