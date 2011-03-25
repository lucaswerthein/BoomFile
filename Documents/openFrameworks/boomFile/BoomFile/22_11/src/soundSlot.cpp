#include "soundSlot.h"

bool soundSlot::loadedSound = false;
ofSoundPlayer soundSlot::slot; 

//--------------------------------------------------------------
void soundSlot::loadSlot(){
	if(!loadedSound) {
		slot.setMultiPlay(true);
		slot.setVolume(0.8);
		slot.loadSound("slot.wav");
		cout << "just loaded slot" << endl;
		loadedSound = true;
	}
	slot.play();
}