
#ifndef _SOUNDSWOOSH
#define _SOUNDSWOOSH

#include "ofMain.h"

class soundSwoosh: public ofBaseApp{
public:
	static void loadSwoosh();
	static bool loadedSound;
	static		ofSoundPlayer  swoosh;
	
};

#endif _SOUNDSWOOSH