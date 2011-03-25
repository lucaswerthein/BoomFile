
#ifndef _SOUNDBUCKET
#define _SOUNDBUCKET

#include "ofMain.h"

class soundBucket: public ofBaseApp{
public:
	static void loadBucket();
	static bool loadedSound;
	static		ofSoundPlayer  bucket;
	
};

#endif _SOUNDBUCKET