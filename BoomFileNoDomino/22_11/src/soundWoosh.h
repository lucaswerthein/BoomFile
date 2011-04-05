
#ifndef _SOUNDWOOSH
#define _SOUNDWOOSH

#include "ofMain.h"

class soundWoosh: public ofBaseApp{
public:
	static void loadWoosh();
	static bool loadedSound;
	static		ofSoundPlayer  woosh;
	
};

#endif _SOUNDWOOSH