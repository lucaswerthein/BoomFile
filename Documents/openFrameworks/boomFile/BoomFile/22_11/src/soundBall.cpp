/*
 *  soundBall.cpp
 *  2ndFullScreenTest
 *
 *  Created by Lucas Werthein on 11/22/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "soundBall.h"

bool soundBall::loadedSound = false;
ofSoundPlayer soundBall::ballBeat; 

//--------------------------------------------------------------
void soundBall::loadBall(){
	if(!loadedSound) {
		ballBeat.setMultiPlay(true);
		ballBeat.setVolume(1);
		ballBeat.loadSound("balloon.wav");
		cout << "just loaded ballBeat" << endl;
		loadedSound = true;
	}
	ballBeat.play();
}