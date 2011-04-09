#include "pipes.h"

bool pipes::loadedImage = false;
ofImage pipes::pipeOne;
ofImage pipes::pipeTwo;

//--------------------------------------------------------------
void pipes::loadImage(){
	if(!loadedImage) {
		ofSetRectMode(OF_RECTMODE_CENTER);
		pipeOne.setImageType(OF_IMAGE_COLOR_ALPHA);
		pipeOne.loadImage("pipe.png");
		pipeOne.resize(pipeOne.getWidth()/2, pipeOne.getHeight()/2);
		pipeTwo.setImageType(OF_IMAGE_COLOR_ALPHA);
		pipeTwo.loadImage("pipe.png");
		pipeTwo.resize(pipeTwo.getWidth()/5, pipeTwo.getHeight()/5);
		cout << "just loaded pipeOne.png" << endl;
		loadedImage = true;
	}
}
//--------------------------------------------------------------
void pipes::drawImage(){
	ofEnableAlphaBlending();
	ofNoFill();
	ofSetColor(255,255,255);
	pipeOne.draw(50,0);
	pipeTwo.draw(1390,0);

}
