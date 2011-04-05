/*
 *  soundBucket.cpp
 *  2ndFullScreenTest
 *
 *  Created by Lucas Werthein on 11/22/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "soundBucket.h"

bool soundBucket::loadedSound = false;
ofSoundPlayer soundBucket::bucket; 

//--------------------------------------------------------------
void soundBucket::loadBucket(){
	if(!loadedSound) {
		bucket.setMultiPlay(true);
		bucket.setVolume(0.5);
		bucket.loadSound("bucket.wav");
		cout << "just loaded bucket" << endl;
		loadedSound = true;
	}
	bucket.play();
}