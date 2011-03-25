#include "crossImage.h"

bool crossImage::loadedImage = false;
ofImage crossImage::cross;

//--------------------------------------------------------------
void crossImage::loadImage(){
	if(!loadedImage) {
		//ofSetRectMode(OF_RECTMODE_CENTER);
		cross.setImageType(OF_IMAGE_COLOR_ALPHA);
		cross.loadImage("motor.png");
		cout << "just loaded motor.png" << endl;
		loadedImage = true;
	}
}
//--------------------------------------------------------------
void crossImage::draw(){
	float rotation = getRotation(); 
	glPushMatrix();
	//ofSetRectMode(OF_RECTMODE_CENTER);
	glTranslatef(getPosition().x, getPosition().y, 0);
	glRotated(rotation, 0, 0, 1);
	ofNoFill();
	ofSetColor(255,255,255);
	ofEnableAlphaBlending();
	
	cross.draw(0,0,drawW, drawW);
	//cross.draw(0,0,50,50);
	//cout << "w is: " << drawW << " h is:"<< drawH<< endl;
	glPopMatrix();
}
