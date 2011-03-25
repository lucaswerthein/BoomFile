#include "rectImage.h"

bool rectImage::loadedImage = false;
ofImage rectImage::tball;
//--------------------------------------------------------------
void rectImage::loadImage(){
	if(!loadedImage) {
		ofSetRectMode(OF_RECTMODE_CENTER);
		tball.setImageType(OF_IMAGE_COLOR_ALPHA);
		tball.loadImage("rectImage.png");
		cout << "just loaded RectImage.png" << endl;
		loadedImage = true;
	}
}
//--------------------------------------------------------------
void rectImage::draw(){
	float rotation = getRotation(); // don't know why this needs to be multiplied by 2
	glPushMatrix();
	ofSetRectMode(OF_RECTMODE_CENTER);
	glTranslatef(getPosition().x, getPosition().y, 0);
	glRotated(rotation, 0, 0, 1);
	ofNoFill();
	ofSetColor(255,255,255);
	ofEnableAlphaBlending();
	tball.draw(0,0, drawW, drawH+5);
	glPopMatrix();
}
