
#include "plaidPlayer.h"

//--------------------------------------------------------------
void plaidPlayer::loadPlaid(){
	if(!loadedImage) {
		
		ofEnableAlphaBlending();
		for (int i=1; i<160; i++){
			plaid[i].loadImage("plaid/c" + ofToString(i) + "plaid.png");
			plaid[i].setImageType(OF_IMAGE_COLOR_ALPHA);
		}
		counter=0;
		cout << "just loaded BKG.png" << endl;
		loadedImage = true;
	}
}
//--------------------------------------------------------------
void plaidPlayer::drawPlaid(){
	plaid[counter].draw(2990,150, plaid[counter].getWidth()/2, plaid[counter].getHeight()/2);
	counter++;
	if(counter >= 160){
		counter=1;	
	}
	
}
