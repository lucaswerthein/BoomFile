#ifndef _SOUNDMIRO
#define _SOUNDMIRO

#include "ofMain.h"

class soundMiro: public ofBaseApp{
public:
	static void loadMiro();
	static bool loadedSound;
	static		ofSoundPlayer  miro;
	
};

#endif _SOUNDMIRO