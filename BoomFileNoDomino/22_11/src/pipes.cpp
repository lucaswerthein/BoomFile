#include "pipes.h"

bool pipes::loadedImage = false;
ofImage pipes::pipeOne;
ofImage pipes::pipeTwo;
ofImage pipes::pipe3;


//--------------------------------------------------------------
void pipes::loadImage(){
	if(!loadedImage) {
		ofSetRectMode(OF_RECTMODE_CENTER);
		pipeOne.setImageType(OF_IMAGE_COLOR_ALPHA);
		pipeOne.loadImage("pipe.png");
		cout << "just loaded pipe1.png" << endl;
		pipeOne.resize(pipeOne.getWidth()/2, pipeOne.getHeight()/2);
		
		pipeTwo.setImageType(OF_IMAGE_COLOR_ALPHA);
		pipeTwo.loadImage("pipe.png");
		pipeTwo.resize(pipeTwo.getWidth()/5, pipeTwo.getHeight()/5);
		cout << "just loaded pipe2.png" << endl;

		pipe3.setImageType(OF_IMAGE_COLOR_ALPHA);
		pipe3.loadImage("pipe.png");
		pipe3.resize(pipe3.getWidth()/9, pipe3.getHeight()/9);
		cout << "just loaded pipe3.png" << endl;

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
	pipe3.draw(2130,0);

}
