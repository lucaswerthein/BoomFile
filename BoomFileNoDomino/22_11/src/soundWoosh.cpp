#include "soundWoosh.h"

bool soundWoosh::loadedSound = false;
ofSoundPlayer soundWoosh::woosh; 

//--------------------------------------------------------------
void soundWoosh::loadWoosh(){
	if(!loadedSound) {
		woosh.setMultiPlay(true);
		woosh.setVolume(1.0);
		woosh.loadSound("woosh.wav");
		cout << "just loaded woosh" << endl;
		loadedSound = true;
	}
	woosh.play();
}