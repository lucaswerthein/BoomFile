#include "swingBall.h"

bool swingBall::loadedImage = false;
ofImage swingBall::tball;
//--------------------------------------------------------------
void swingBall::loadImage(){
	if(!loadedImage) {
		tball.setImageType(OF_IMAGE_COLOR_ALPHA);
		tball.loadImage("flamengo.png");
		cout << "just loaded Flamengo.png" << endl;
		loadedImage = true;
	}
}
//--------------------------------------------------------------
void swingBall::draw(){
	float radius = getRadius();
	float rotation = getRotation() * 2; // don't know why this needs to be multiplied by 2
	glPushMatrix();
	glTranslatef(getPosition().x, getPosition().y, 0);
	glRotated(rotation, 0, 0, 1);
	ofNoFill();
	ofSetColor(255,255,255);
	ofEnableAlphaBlending();
	tball.draw(0,0, radius*2, radius*2);
	glPopMatrix();
}

