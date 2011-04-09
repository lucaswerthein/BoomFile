/*
 *  soundBridge.cpp
 *  2ndFullScreenTest
 *
 *  Created by Lucas Werthein on 11/25/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "soundBridge.h"

bool soundBridge::loadedSound = false;
ofSoundPlayer soundBridge::bridge; 

//--------------------------------------------------------------
void soundBridge::loadBridge(){
	if(!loadedSound) {
		bridge.setMultiPlay(true);
		bridge.setVolume(0.4);
		bridge.loadSound("bridge.mp3");
		cout << "just loaded bridge" << endl;
		loadedSound = true;
	}
	bridge.play();
}