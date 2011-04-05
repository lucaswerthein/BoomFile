/*
 *  soundContact.cpp
 *  emptyExample
 *
 *  Created by Lucas Werthein on 11/13/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "soundContact.h"

bool soundContact::loadedSound = false;
ofSoundPlayer soundContact::beat;
//--------------------------------------------------------------
void soundContact::loadSoundDomino(){
	if(!loadedSound) {
		beat.setMultiPlay(true);
		beat.setVolume(1);
		beat.loadSound("metronome.mp3");
		cout << "just loaded sound" << endl;
		//printf("%i %i \n", tball.width, tball.height);
		loadedSound = true;
	}
	beat.play();
}
