#include "swirlPlayer.h"

//--------------------------------------------------------------
void swirlPlayer::loadSwirl(){
	if(!loadedImage) {
		
		ofEnableAlphaBlending();
		for (int i=0; i<44; i++){
			swirl[i].loadImage("swirl/c" + ofToString(i) + "swirl.png");
			swirl[i].setImageType(OF_IMAGE_COLOR_ALPHA);
		}
		counter=0;
		cout << "just loaded BKG.png" << endl;
		loadedImage = true;
	}
}
//--------------------------------------------------------------
void swirlPlayer::drawSwirl(){
	swirl[counter].draw(160,105, swirl[counter].getWidth()/3, swirl[counter].getHeight()/3);
	counter++;
	if(counter >= 44){
		counter=0;	
	}
	
}
