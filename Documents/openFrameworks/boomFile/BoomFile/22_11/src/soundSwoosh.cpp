#include "soundSwoosh.h"

bool soundSwoosh::loadedSound = false;
ofSoundPlayer soundSwoosh::swoosh; 

//--------------------------------------------------------------
void soundSwoosh::loadSwoosh(){
	if(!loadedSound) {
		swoosh.setMultiPlay(true);
		swoosh.setVolume(0.5);
		swoosh.loadSound("swosh.wav");
		cout << "just loaded swoosh" << endl;
		loadedSound = true;
	}
	swoosh.play();
}