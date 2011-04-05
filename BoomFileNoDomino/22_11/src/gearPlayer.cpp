#include "gearPlayer.h"

//--------------------------------------------------------------
void gearPlayer::loadGear(){
	if(!loadedImage) {
	
		ofEnableAlphaBlending();
				
		for (int i=0; i<89; i++){
			gear[i].loadImage("gears/c" + ofToString(i) + "copy.png");
			//cout << "gears/c" + ofToString(i) + "copy.png" << endl;
			gear[i].setImageType(OF_IMAGE_COLOR_ALPHA);
		}
		counter=0;
		cout << "just loaded BKG.png" << endl;
		loadedImage = true;
		
	}
}
//--------------------------------------------------------------
void gearPlayer::drawGear(){
	gear[counter].draw(7900/2,200, gear[counter].getWidth()/3, gear[counter].getHeight()/3);
	counter++;
	if(counter >= 89){
		counter=0;	
	}
	
}
