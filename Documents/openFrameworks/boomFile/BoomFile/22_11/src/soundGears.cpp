#include "soundGears.h"

bool soundGears::loadedSound = false;
ofSoundPlayer soundGears::gears; 

//--------------------------------------------------------------
void soundGears::loadGears(){
	if(!loadedSound) {
		gears.setMultiPlay(false);
		gears.setVolume(0.8);
		gears.loadSound("gears.mp3");
		cout << "just loaded gears" << endl;
		loadedSound = true;
	}
	gears.play();
}