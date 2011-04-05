/*
 *  soundRect2.cpp
 *  2ndFullScreenTest
 *
 *  Created by Lucas Werthein on 11/22/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "soundRect2.h"

bool soundRect2::loadedSound = false;
ofSoundPlayer soundRect2::rectBeat2; 

//--------------------------------------------------------------
void soundRect2::loadRect2(){
	if(!loadedSound) {
		rectBeat2.setMultiPlay(true);
		rectBeat2.setVolume(0.3);
		rectBeat2.loadSound("rectBall.wav");
		cout << "just loaded rectBeat2" << endl;
		loadedSound = true;
	}
	rectBeat2.play();
}