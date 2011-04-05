#include "worldBall.h"

//--------------------------------------------------------------
void worldBall::setup(ofxBox2d * box2d){
	this->box2d = box2d;
}

//--------------------------------------------------------------
void worldBall::draw(){
	for(int i = 0; i < flyingBall.size(); i++) {
		flyingBall[i].draw();
	}
}

//--------------------------------------------------------------
void worldBall::dropOne(){
	float r = 7;										//was originally 7
	ofxBox2dCircle bolas2;
	bolas2.setPhysics(0.1, 0.0, 0.0);
	//bolas2.setup(box2d->getWorld(), 50+1360, 10, r);
	bolas2.setup(box2d->getWorld(), 50, 10, r);
	flyingBall.push_back(bolas2);

	
}
//--------------------------------------------------------------
void worldBall::dropTwo(){
	

}

//--------------------------------------------------------------
void worldBall::dropThree(){
	
 float r = 10;
 ofxBox2dCircle bolas;
 bolas.setPhysics(0.1, 0.4, 0.0);
 //bolas.setup(box2d->getWorld(), 120, 50, r);
 bolas.setup(box2d->getWorld(), 120+2720, 10, r);
 flyingBall.push_back(bolas);
}

//--------------------------------------------------------------
void worldBall::destroyBalls(){
	for(int i =flyingBall.size()-1; i >= 0; i--){
		ofPoint cPos = flyingBall[i].getPosition();
		if (cPos.y>384){
			ofxBox2dCircle b = flyingBall[i];
			b.destroyShape();
			flyingBall.erase(flyingBall.begin()+i);
			free(&b);
		}
	}
	
}
