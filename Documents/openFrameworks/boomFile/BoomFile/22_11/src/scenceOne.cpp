#include "scenceOne.h"

//--------------------------------------------------------------
void scenceOne::setup(ofxBox2d* box2d){
	this->box2d = box2d;
	middlePos = 0;
	rectImage::loadImage();
	pipes::loadImage();

}
//--------------------------------------------------------------	
void scenceOne::update(){
		
	//worldRects(middlePos+40, 0, 1, 80, 0, 0.06);
	//worldRects(middlePos+60, 0, 1, 80, 0, 0.06);
	worldRects(middlePos+15, 265, 45, 1, 0.7, 1.80);
	worldRects(middlePos+145, 295, 30, 1, 0.9, 1.40);
	worldRects(middlePos+430, 60, 40, 1, 0.95, 0.3);
	worldRects(middlePos+550, 295, 40, 1, -0.4, 0.82);
	worldRects(middlePos+745, 300, 40, 1, 0.4, 0.75);
	worldRects(middlePos+670, 245, 25, 1, 0.1, 1.6);
	worldRects(middlePos+900, 300, 80, 1, -0.415, 0.70);
	worldRects(middlePos+1110, 270, 70, 1, -0.95, 0.8);
	worldRects(middlePos+1310, 260, 30, 1, -0.35, 0.6);
	worldRects(middlePos+1210, 200, 30, 1, 0.3, 1.5);
	worldRects(middlePos+1310, 110, 30, 1, -0.7, 1.55);
	
	worldRects(middlePos+280, 330, 30, 1, 0.7, 1.58);
	worldRects(middlePos+1330, 60, 30, 1, -0.82, 0.30);


	

	
	/////////////////////////DRAW BRIDGE//////////////////////////
	bridge();	
	
}

//--------------------------------------------------------------	
void scenceOne::draw(){
	
	/////////////////////////DRAWING RECTANGLE LINES/////////
	for(int i = 0; i < lineRects.size(); i++)lineRects[i].draw();
	
	/////////////////////////DRAW BRIDGE//////////////////////////
	for(int i=0; i<NUMBALLS; i++) ballJoints[i].draw();
	for(int i=0; i<NUMJOINTS; i++) joints[i].draw();
	
	pipes::drawImage();

}
//--------------------------------------------------------------
void scenceOne::bridge(){
	/////////////////////////BRIDGE FUNCTION I CREATED//////////////////////////
	
	ballJoints[0].setPhysics(0, 0.5, 0.5);
	ballJoints[0].setup("bridgeBall", box2d->getWorld(), 200+middlePos+3550, 330, 8);

	ballJoints[15].setPhysics(0, 0.5, 0.5);
	ballJoints[15].setup("bridgeBall",box2d->getWorld(), 500+middlePos+3550, 330, 8);
	
	
	for(int i = 1; i <=14; i++){
		ballJoints[i].setPhysics(0.1, 0.5, 0.5);
		ballJoints[i].setup("bridgeBall",box2d->getWorld(), (200+i*20)+middlePos+3550, 335, 8);
	}
	
	for( int i = 0; i <= 14; i++){
		joints[i].setWorld(box2d->getWorld());
		joints[i].addJoint(ballJoints[i+1].body, ballJoints[i].body, 30, 0.5);
	}
	
}
//--------------------------------------------------------------
void scenceOne::worldRects(int posX, int posY, int w, int h, float ang, float spring){
	boxW = w;
	boxH = h;
	rectImage lineReplacer;
	lineReplacer.setPhysics(0, spring, 0.1);
	lineReplacer.setup("lineBox",box2d->getWorld(), posX , posY, w, h, ang);
	lineRects.push_back(lineReplacer);
	
}

