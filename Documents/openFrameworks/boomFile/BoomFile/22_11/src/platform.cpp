#include "platform.h"

bool platform::loadedImage = false;
ofImage platform::base;
//--------------------------------------------------------------
void platform::loadImage(){
	if(!loadedImage) {
		ofSetRectMode(OF_RECTMODE_CENTER);
		base.setImageType(OF_IMAGE_COLOR_ALPHA);
		base.loadImage("platform.png");
		cout << "just loaded platform.png" << endl;
		loadedImage = true;
	}
}
//--------------------------------------------------------------
void platform::draw(){
	float rotation = getRotation(); // don't know why this needs to be multiplied by 2
	glPushMatrix();
	ofSetRectMode(OF_RECTMODE_CENTER);
	glTranslatef(getPosition().x, getPosition().y, 0);
	glRotated(rotation, 0, 0, 1);
	ofNoFill();
	ofSetColor(255,255,255);
	ofEnableAlphaBlending();
	base.draw(0,0, drawW+5, drawH+8);
	glPopMatrix();
}
