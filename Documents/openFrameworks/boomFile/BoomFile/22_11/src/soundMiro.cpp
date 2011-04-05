#include "soundMiro.h"

bool soundMiro::loadedSound = false;
ofSoundPlayer soundMiro::miro; 

//--------------------------------------------------------------
void soundMiro::loadMiro(){
	if(!loadedSound) {
		miro.setMultiPlay(false);
		miro.setVolume(0.4);
		miro.loadSound("miro.mp3");
		cout << "just loaded miro" << endl;
		loadedSound = true;
	}
	miro.play();
}