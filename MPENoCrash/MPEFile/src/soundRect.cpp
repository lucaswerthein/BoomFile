#include "soundRect.h"

bool soundRect::loadedSound = false;
ofSoundPlayer soundRect::rectBeat; 

//--------------------------------------------------------------
void soundRect::loadRect(){
	if(!loadedSound) {
		rectBeat.setMultiPlay(true);
		rectBeat.setVolume(0.3);
		rectBeat.loadSound("rectBall1.wav");
		cout << "just loaded rectBeat" << endl;
		loadedSound = true;
	}
	rectBeat.play();
}